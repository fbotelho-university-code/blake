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
static uint32_t state32[16]; 
static const uint32_t c[16] = {
    0x243F6A88, 0x85A308D3,
    0x13198A2E, 0x03707344,
    0xa4093822, 0x299F31D0,
    0x082EFA98, 0xEC4E6C89,
    0x452821E6, 0x38D01377,
    0xBE5466CF, 0x34E90C6C,
    0xC0AC29B7, 0xC97C50DD,
    0x3F84D5B5, 0xB5470917 
};

//copy
// direct pointers to matrix
static uint32_t *v0 = &state32[0];
static uint32_t *v1 = &state32[1];
static uint32_t *v2 = &state32[2];
static uint32_t *v3 = &state32[3];
static uint32_t *v4 = &state32[4];
static uint32_t *v5 = &state32[5];
static uint32_t *v6 = &state32[6];
static uint32_t *v7 = &state32[7];
static uint32_t *v8 = &state32[8];
static uint32_t *v9 = &state32[9];
static uint32_t *v10 = &state32[10];
static uint32_t *v11 = &state32[11];
static uint32_t *v12 = &state32[12];
static uint32_t *v13 = &state32[13];
static uint32_t *v14 = &state32[14];
static uint32_t *v15 = &state32[15];

static inline void initH256(uint32_t *h) {
  h[0] = 0x6A09E667UL; 
  h[1] = 0xBB67AE85UL; 
  h[2] = 0x3C6EF372UL; 
  h[3] = 0xA54FF53AUL; 
  h[4] = 0x510E527FUL; 
  h[5] = 0x9B05688CUL; 
  h[6] = 0x1F83D9ABUL; 
  h[7] = 0x5BE0CD19UL; 
}
//copy
static inline void init256(uint32_t h[8], uint32_t s[4], uint32_t t[2]){
  *v0  = h[0]; 
  *v1  = h[1]; 
  *v2  = h[2];
  *v3  = h[3]; 
  *v4  = h[4];
  *v5  = h[5]; 
  *v6  = h[6];
  *v7  = h[7]; 
  *v8  = s[0] ^ 0x243F6A88; 
  *v9  = s[1] ^ 0x85A308D3; 
  *v10 = s[2] ^ 0x13198A2E; 
  *v11 = s[3] ^ 0x03707344; 
  *v12 = t[0] ^ 0xA4093822; 
  *v13 = t[0] ^ 0x299F31D0; 
  *v14 = t[1] ^ 0x082EFA98; 
  *v15 = t[1] ^ 0xEC4E6C89; 
}

static inline void g32(uint32_t *a, uint32_t *b, uint32_t *c, uint32_t *d, uint32_t round, uint32_t i, uint32_t *m){
	
	*a = ADD32((*a),(*b))+XOR32(m[sigma[round%10][i]], c[sigma[round%10][i+1]]);
	*d = ROT32(XOR32((*d),(*a)),16);
	*c = ADD32((*c),(*d));
	*b = ROT32(XOR32((*b),(*c)),12);
	*a = ADD32((*a),(*b))+XOR32(m[sigma[round%10][i+1]], c[sigma[round%10][i]]);
	*d = ROT32(XOR32((*d),(*a)), 8);
	*c = ADD32((*c),(*d));
	*b = ROT32(XOR32((*b),(*c)), 7);
}

static inline void rounds256(uint32_t *m){
  /*	uint32_t round; 


	for(round=0;round<14;++round){
		// column steps
		g32(&state32[0], &state32[4], &state32[8], &state32[12], round, 0, m);
		g32(&state32[1], &state32[5], &state32[9], &state32[13], round, 2, m);
		g32(&state32[2], &state32[6], &state32[10], &state32[14], round, 4, m);
		g32(&state32[3], &state32[7], &state32[11], &state32[15], round, 6, m);
		
		// diagonal steps
		g32(&state32[0], &state32[5], &state32[10], &state32[15], round, 8, m);
		g32(&state32[1], &state32[6], &state32[11], &state32[12], round, 10, m);
		g32(&state32[2], &state32[7], &state32[8], &state32[13], round, 12, m);
		g32(&state32[3], &state32[4], &state32[9], &state32[14], round, 14, m);
	}
  */
#include "rounds32.h"; 
}

//copy
static inline void finit256(uint32_t h[8], uint32_t s[4]){
	
  h[0] = h[0] ^ s[0] ^ (*v0) ^ (*v8);
  h[1] = h[1] ^ s[1] ^ (*v1) ^ (*v9);
  h[2] = h[2] ^ s[2] ^ (*v2) ^ (*v10);
  h[3] = h[3] ^ s[3] ^ (*v3) ^ (*v11);
  h[4] = h[4] ^ s[0] ^ (*v4) ^ (*v12);
  h[5] = h[5] ^ s[1] ^ (*v5) ^ (*v13);
  h[6] = h[6] ^ s[2] ^ (*v6) ^ (*v14);
  h[7] = h[7] ^ s[3] ^ (*v7) ^ (*v15);	
}


static inline void compress(uint32_t *h, uint32_t *m, uint32_t *s, uint32_t * t){
	init256(h, s, t);
	rounds256(m);
	finit256(h,s);
}

static inline uint64_t pad256(unsigned char *message, uint64_t len, uint32_t *comPadding, unsigned char * padded); 
unsigned char *blake256(unsigned char *message, unsigned len, unsigned char *s, unsigned char *h){
        unsigned char   padded[128]; 

	//Reference data from the algorithm/paper
	uint32_t i; 
	//uint32_t *h = malloc(sizeof(uint32_t) * 8);  // hashed value. Final, is updated by compress function;
	uint64_t resto = (len*8) % 512 ;    
	uint64_t var = 0;  	
	uint64_t blocksSemPadding;
	uint32_t blocksComPadding=0; 

	blocksSemPadding = pad256(message, (uint64_t ) len, &blocksComPadding, padded);
	//prettyPrinter32(message, (blocksComPadding+blocksSemPadding+1)*64, "msg@pad:\n");
	
	// Initialize h with IV 
	initH256(h);
	uint64_t bytes_total = (64* blocksSemPadding); 
	uint64_t round; 
	uint32_t *type = message; 
	for (round = 0 ,i=0; round< bytes_total ; round+=4,i++)
	  type[i] = U8TO32_BE(message + round); //convert_bytes(&m[round], sizeof(uint32_t)); 

	type = padded; 
	for (round = 0,i=0 ; round< 128 ; round+=4,i++)
	  type[i] = U8TO32_BE(&padded[round]); //convert_bytes(&m[round], sizeof(uint32_t)); 

	for (i=0; i<blocksSemPadding; i++) {
		var += 512; 
		compress(h, message + i*64, s, &var); 
	}
	// Last message block
	if(resto){
		var += resto; 
		compress(h, padded, s, &var);
	}

	// Add block only with padding, if needed
	if (blocksComPadding == 1){
		var=0;
		if (resto == 0 ){ 
		  compress(h, padded , s, &var); 
		}
		else{
		  compress(h, &padded[64] , s, &var); 
		}
	}

	return (unsigned char *) h;
}

// Pad the message and determine the sizes of each h block. 
// Returns the number of blocks without padding.
static inline uint64_t pad256(unsigned char *message, uint64_t len, uint32_t *comPadding, unsigned char *padded){
	
	uint64_t nBlocks = (len/64);   // Number of blocks in message.
	uint64_t resto = len % 64;  // What is left from message to fill. 

	uint64_t num_zeros; // Number of 0x00 bytes to pad message with. 

	unsigned char *begin_of_last_block = message+(len-resto);  // Begin of last block with message
	memcpy(padded, begin_of_last_block, resto); 
	begin_of_last_block = padded; 
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
