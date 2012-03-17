// Include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Include local libraries
#include "blake512.h"
#include "defs.h"

// Bit-wise operations for 64bits
#define ROT64(x,n) (((x)<<(64-n))|( (x)>>(n)))
#define ADD64(x,y) ((uint64_t)((x) + (y)))
#define XOR64(x,y) ((uint64_t)((x) ^ (y)))

void initH512(uint64_t *h){
	h[0] = IV512[0];
	h[1] = IV512[1];
	h[2] = IV512[2];
	h[3] = IV512[3];
	h[4] = IV512[4];
	h[5] = IV512[5];
	h[6] = IV512[6];
	h[7] = IV512[7];
}

void init512(uint64_t h[8], uint64_t s[4], uint64_t t[2]){
	
	state64[0][0] = h[0];
	state64[0][1] = h[1];
	state64[0][2] = h[2];
	state64[0][3] = h[3];
	state64[1][0] = h[4];
	state64[1][1] = h[5];
	state64[1][2] = h[6];
	state64[1][3] = h[7];
	state64[2][0] = s[0] ^ c512[0];
	state64[2][1] = s[1] ^ c512[1];
	state64[2][2] = s[2] ^ c512[2];
	state64[2][3] = s[3] ^ c512[3];
	state64[3][0] = t[0] ^ c512[4];
	state64[3][1] = t[0] ^ c512[5];
	state64[3][2] = t[1] ^ c512[6];
	state64[3][3] = t[1] ^ c512[7];
}

void g64(uint64_t *a, uint64_t *b, uint64_t *c, uint64_t *d, uint32_t round, uint32_t i, uint64_t m[16]){
	
	*a = ADD64((*a),(*b))+XOR64(m[sigma[round%10][2*i]], c512[sigma[round%10][2*i+1]]);
    *d = ROT64(XOR64((*d),(*a)),32);
    *c = ADD64((*c),(*d));
    *b = ROT64(XOR64((*b),(*c)),25);
    *a = ADD64((*a),(*b))+XOR64(m[sigma[round%10][2*i+1]], c512[sigma[round%10][2*i]]);
    *d = ROT64(XOR64((*d),(*a)),16);
    *c = ADD64((*c),(*d));
    *b = ROT64(XOR64((*b),(*c)),11);
	
}

void rounds512(uint64_t *m){
	
	uint32_t round; 
	for (round = 0 ; round<16 ; round++)
		convert_bytes(&m[round], sizeof(uint64_t)); 
	
	for(round=0;round<16;++round){
		
		// column steps
		g64(&state64[0][0], &state64[1][0], &state64[2][0], &state64[3][0], round, 0, m);
		g64(&state64[0][1], &state64[1][1], &state64[2][1], &state64[3][1], round, 1, m);
		g64(&state64[0][2], &state64[1][2], &state64[2][2], &state64[3][2], round, 2, m);
		g64(&state64[0][3], &state64[1][3], &state64[2][3], &state64[3][3], round, 3, m);
		
		// diagonal steps
		g64(&state64[0][0], &state64[1][1], &state64[2][2], &state64[3][3], round, 4, m);
		g64(&state64[0][1], &state64[1][2], &state64[2][3], &state64[3][0], round, 5, m);
		g64(&state64[0][2], &state64[1][3], &state64[2][0], &state64[3][1], round, 6, m);
		g64(&state64[0][3], &state64[1][0], &state64[2][1], &state64[3][2], round, 7, m);
		
	}
	
}

void finit512(uint64_t h[8], uint64_t s[4]){
	h[0] = h[0] ^ s[0] ^ state64[0][0] ^ state64[2][0];
	h[1] = h[1] ^ s[1] ^ state64[0][1] ^ state64[2][1];
	h[2] = h[2] ^ s[2] ^ state64[0][2] ^ state64[2][2];
	h[3] = h[3] ^ s[3] ^ state64[0][3] ^ state64[2][3];
	h[4] = h[4] ^ s[0] ^ state64[1][0] ^ state64[3][0];
	h[5] = h[5] ^ s[1] ^ state64[1][1] ^ state64[3][1];
	h[6] = h[6] ^ s[2] ^ state64[1][2] ^ state64[3][2];
	h[7] = h[7] ^ s[3] ^ state64[1][3] ^ state64[3][3];	
}

void compress64(uint64_t *h, uint64_t *m, uint64_t *s, uint64_t * t){
	init512(h, s, t);
	rounds512(m);
	finit512(h,s);
}

unsigned char *blake512(unsigned char *message, unsigned len, unsigned char *s){
	//message[0]=0x00;
	//Reference data from the algorithm/paper
	uint32_t i; 
	uint64_t *h = malloc(sizeof(uint64_t) * 8);  // hashed value. Final, is updated by compress function;
	uint64_t resto = (len*8) % 1024 ;    
	uint64_t var[2] = { 0, 0 };  	
	uint64_t blocksSemPadding;
	uint32_t blocksComPadding=0; 
	
	blocksSemPadding = pad512(message, (uint64_t ) len, &blocksComPadding);
	//prettyPrinter64(message, (blocksComPadding+blocksSemPadding+1)*128, "msg@pad:\n");
	
	// Initialize h with IV 
	initH512(h);
	
	for (i=0; i<blocksSemPadding; i++) {
		var[0] += 1024; 
		compress64(h, message + i*128, s, &var); 
	}
	
	// Last message block
	if(resto){
		var[0] += resto; 
		compress64(h, message + i++*128, s, &var);
	}
	
	// Add block only with padding, if needed
	if (blocksComPadding == 1){
		var[0]=0;
		compress64(h, message + i*128, s, &var); 
	}
	
	return (unsigned char *) h;
}

uint64_t pad512(unsigned char *message, uint64_t len, uint32_t *comPadding){
	
	uint64_t nBlocks = (len/128);   // Number of blocks in message.
	uint64_t resto = len % 128;  // What is left from message to fill. 
	uint64_t num_zeros; // Number of 0x00 bytes to pad message with. 
	unsigned char *begin_of_last_block = message+(len-resto);  // Begin of last block with message
	unsigned char * ptr_begin_pad = begin_of_last_block + resto; // Begin of padding
	
	
	if (resto==111){
		*(begin_of_last_block++ + resto) = 0x81;
		memset(begin_of_last_block + resto, 0x00, 8); // 64bit t[1
		begin_of_last_block +=8;
		dumpLen(begin_of_last_block + resto, len*8);
	}
	else{
		if (resto==0){
			num_zeros = 110;
			*comPadding=1; 
		}
		else {
			if (resto<111){
				num_zeros = 110 - resto; 				
			}
			else{
				*comPadding = 1; 
				num_zeros = 238 - resto; 
			}
		}
		
		*ptr_begin_pad++ =  0x80; 
		memset(ptr_begin_pad, 0x00, num_zeros); 
		*(ptr_begin_pad++ + num_zeros) = (unsigned char) 0x01;
		memset(ptr_begin_pad+num_zeros, 0x00, 8); // 64bit t[1]
		ptr_begin_pad += 8;
		dumpLen(ptr_begin_pad + num_zeros , len*8); 
	}
	
	return nBlocks;
}