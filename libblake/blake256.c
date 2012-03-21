// Include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Include local libraries
#include "blake256.h"
#include "blake.h"


// Bit-wise operations for 32bits
#define ROT32(x,n) (((x)<<(32-n))|( (x)>>(n)))
#define ADD32(x,y) ((uint32_t)((x) + (y)))
#define XOR32(x,y) ((uint32_t)((x) ^ (y)))

void initH256(uint32_t *h){
	h[0] = IV256[0];
	h[1] = IV256[1];
	h[2] = IV256[2];
	h[3] = IV256[3];
	h[4] = IV256[4];
	h[5] = IV256[5];
	h[6] = IV256[6];
	h[7] = IV256[7];
}

void init256(uint32_t h[8], uint32_t s[4], uint32_t t[2]){
	
	state32[0][0] = h[0];
	state32[0][1] = h[1];
	state32[0][2] = h[2];
	state32[0][3] = h[3];
	state32[1][0] = h[4];
	state32[1][1] = h[5];
	state32[1][2] = h[6];
	state32[1][3] = h[7];
	state32[2][0] = s[0] ^ c256[0];
	state32[2][1] = s[1] ^ c256[1];
	state32[2][2] = s[2] ^ c256[2];
	state32[2][3] = s[3] ^ c256[3];
	state32[3][0] = t[0] ^ c256[4];
	state32[3][1] = t[0] ^ c256[5];
	state32[3][2] = t[1] ^ c256[6];
	state32[3][3] = t[1] ^ c256[7];
}

void g32(uint32_t *a, uint32_t *b, uint32_t *c, uint32_t *d, uint32_t round, uint32_t i, uint32_t *m){
	
	*a = ADD32((*a),(*b))+XOR32(m[sigma[round%10][2*i]], c256[sigma[round%10][2*i+1]]);
	*d = ROT32(XOR32((*d),(*a)),16);
	*c = ADD32((*c),(*d));
	*b = ROT32(XOR32((*b),(*c)),12);
	*a = ADD32((*a),(*b))+XOR32(m[sigma[round%10][2*i+1]], c256[sigma[round%10][2*i]]);
	*d = ROT32(XOR32((*d),(*a)), 8);
	*c = ADD32((*c),(*d));
	*b = ROT32(XOR32((*b),(*c)), 7);
}

void rounds256(uint32_t *m){
	
	uint32_t round; 
	for (round = 0 ; round<16 ; round++)
		convert_bytes(&m[round], sizeof(uint32_t)); 
	
	for(round=0;round<14;++round){
		// column steps
		g32(&state32[0][0], &state32[1][0], &state32[2][0], &state32[3][0], round, 0, m);
		g32(&state32[0][1], &state32[1][1], &state32[2][1], &state32[3][1], round, 1, m);
		g32(&state32[0][2], &state32[1][2], &state32[2][2], &state32[3][2], round, 2, m);
		g32(&state32[0][3], &state32[1][3], &state32[2][3], &state32[3][3], round, 3, m);
		
		// diagonal steps
		g32(&state32[0][0], &state32[1][1], &state32[2][2], &state32[3][3], round, 4, m);
		g32(&state32[0][1], &state32[1][2], &state32[2][3], &state32[3][0], round, 5, m);
		g32(&state32[0][2], &state32[1][3], &state32[2][0], &state32[3][1], round, 6, m);
		g32(&state32[0][3], &state32[1][0], &state32[2][1], &state32[3][2], round, 7, m);
		
	}
	
}

void finit256(uint32_t h[8], uint32_t s[4]){
	
	h[0] = h[0] ^ s[0] ^ state32[0][0] ^ state32[2][0];
	h[1] = h[1] ^ s[1] ^ state32[0][1] ^ state32[2][1];
	h[2] = h[2] ^ s[2] ^ state32[0][2] ^ state32[2][2];
	h[3] = h[3] ^ s[3] ^ state32[0][3] ^ state32[2][3];
	h[4] = h[4] ^ s[0] ^ state32[1][0] ^ state32[3][0];
	h[5] = h[5] ^ s[1] ^ state32[1][1] ^ state32[3][1];
	h[6] = h[6] ^ s[2] ^ state32[1][2] ^ state32[3][2];
	h[7] = h[7] ^ s[3] ^ state32[1][3] ^ state32[3][3];	
}

void compress(uint32_t *h, uint32_t *m, uint32_t *s, uint32_t * t){
	init256(h, s, t);
	rounds256(m);
	finit256(h,s);
}

unsigned char *blake256(unsigned char *message, unsigned len, unsigned char *s, unsigned char *h){
	
	//Reference data from the algorithm/paper
	uint32_t i; 
	//uint32_t *h = malloc(sizeof(uint32_t) * 8);  // hashed value. Final, is updated by compress function;
	uint64_t resto = (len*8) % 512 ;    
	uint64_t var = 0;  	
	uint64_t blocksSemPadding;
	uint32_t blocksComPadding=0; 

	blocksSemPadding = pad256(message, (uint64_t ) len, &blocksComPadding);
	//prettyPrinter32(message, (blocksComPadding+blocksSemPadding+1)*64, "msg@pad:\n");
	
	// Initialize h with IV 
	initH256(h);
	
	for (i=0; i<blocksSemPadding; i++) {
		var += 512; 
		compress(h, message + i*64, s, &var); 
	}
	
	// Last message block
	if(resto){
		var += resto; 
		compress(h, message + i++*64, s, &var);
	}
	
	// Add block only with padding, if needed
	if (blocksComPadding == 1){
		var=0;
		compress(h, message + i*64, s, &var); 
	}

	return (unsigned char *) h;
}

// Pad the message and determine the sizes of each h block. 
// Returns the number of blocks without padding.
uint64_t pad256(unsigned char *message, uint64_t len, uint32_t *comPadding){
	
	uint64_t nBlocks = (len/64);   // Number of blocks in message.
	uint64_t resto = len % 64;  // What is left from message to fill. 
	uint64_t num_zeros; // Number of 0x00 bytes to pad message with. 
	unsigned char *begin_of_last_block = message+(len-resto);  // Begin of last block with message
	unsigned char * ptr_begin_pad = begin_of_last_block + resto; // Begin of padding

	
	if (resto==55){
		*(begin_of_last_block + resto) = 0x81; 
		dumpLen(begin_of_last_block + resto + 1, len * 8);
	}
	else{
		if (resto==0){
			num_zeros = 54;
			*comPadding=1; 
		}
		else {
			if (resto<55){
				num_zeros = 54 - resto; 				
			}
			else{
				*comPadding = 1; 
				num_zeros = 118 - resto; 
			}
		}
		
		*ptr_begin_pad++ =  0x80; 
		memset(ptr_begin_pad, 0x00, num_zeros); 
		*(ptr_begin_pad++ + num_zeros) = (unsigned char) 0x01; 
		dumpLen(ptr_begin_pad + num_zeros , len*8); 
	}
	
	return nBlocks; 
}
