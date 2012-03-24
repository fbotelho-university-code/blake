// Include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "blake.h" 
// Include local libraries
#include "blake512.h"


// Bit-wise operations for 64bits
#define ROT64(x,n) (((x)<<(64-n))|( (x)>>(n)))
#define ADD64(x,y) ((uint64_t)((x) + (y)))
#define XOR64(x,y) ((uint64_t)((x) ^ (y)))
static const uint64_t c[16] = {
	0x243F6A8885A308D3ULL,0x13198A2E03707344ULL,
	0xA4093822299F31D0ULL,0x082EFA98EC4E6C89ULL,
	0x452821E638D01377ULL,0xBE5466CF34E90C6CULL,
	0xC0AC29B7C97C50DDULL,0x3F84D5B5B5470917ULL,
	0x9216D5D98979FB1BULL,0xD1310BA698DFB5ACULL,
	0x2FFD72DBD01ADFB7ULL,0xB8E1AFED6A267E96ULL,
	0xBA7C9045F12C7F99ULL,0x24A19947B3916CF7ULL,
	0x0801F2E2858EFC16ULL,0x636920D871574E69ULL
};
//copy 

static uint64_t state64[16]; 
// direct pointers to matrix
static uint64_t *v0 = &state64[0];
static uint64_t *v1 = &state64[1];
static uint64_t *v2 = &state64[2];
static uint64_t *v3 = &state64[3];
static uint64_t *v4 = &state64[4];
static uint64_t *v5 = &state64[5];
static uint64_t *v6 = &state64[6];
static uint64_t *v7 = &state64[7];
static uint64_t *v8 = &state64[8];
static uint64_t *v9 = &state64[9];
static uint64_t *v10 = &state64[10];
static uint64_t *v11 = &state64[11];
static uint64_t *v12 = &state64[12];
static uint64_t *v13 = &state64[13];
static uint64_t *v14 = &state64[14];
static uint64_t *v15 = &state64[15];


static inline void initH512(uint64_t *h){
  h[0] = 0x6A09E667F3BCC908ULL; 
  h[1] =  0xBB67AE8584CAA73BULL; 
	h[2] = 0x3C6EF372FE94F82BULL;
	h[3] = 0xA54FF53A5F1D36F1ULL;
	h[4] = 0x510E527FADE682D1ULL;
	h[5] =  0x9B05688C2B3E6C1FULL;
	h[6] = 0x1F83D9ABFB41BD6BULL;
	h[7] = 0x5BE0CD19137E2179ULL;
}

//copy 
static inline void init512(uint64_t h[8], uint64_t s[4], uint64_t t[2]){
	*v0 = h[0];
	*v1 = h[1];
	*v2 = h[2];
	*v3 = h[3];
	*v4 = h[4];
	*v5 = h[5];
	*v6 = h[6];
	*v7 = h[7];
	*v8 = s[0] ^ 0x243F6A8885A308D3ULL; 
	*v9 = s[1] ^ 0x13198A2E03707344ULL;
	*v10 = s[2] ^ 0xA4093822299F31D0ULL; 
	*v11 = s[3] ^ 0x082EFA98EC4E6C89ULL; 
	*v12 = t[0] ^ 0x452821E638D01377ULL;
	*v13 = t[0] ^ 0xBE5466CF34E90C6CULL; 
	*v14 = t[1] ^ 0xC0AC29B7C97C50DDULL; 
	*v15 = t[1] ^ 0x3F84D5B5B5470917ULL; 
}


static inline void g64(uint64_t *a, uint64_t *b, uint64_t *c, uint64_t *d, uint32_t round, uint32_t i, uint64_t m[16]){
    *a = ADD64((*a),(*b))+XOR64(m[sigma[round%10][i]], c[sigma[round%10][i+1]]);
    *d = ROT64(XOR64((*d),(*a)),32);
    *c = ADD64((*c),(*d));
    *b = ROT64(XOR64((*b),(*c)),25);
    *a = ADD64((*a),(*b))+XOR64(m[sigma[round%10][i+1]], c[sigma[round%10][i]]);
    *d = ROT64(XOR64((*d),(*a)),16);
    *c = ADD64((*c),(*d));
    *b = ROT64(XOR64((*b),(*c)),11);
}

static inline void rounds512(uint64_t *m){
  /*
	uint32_t round; 
	for(round=0;round<16;++round){
		// column steps
		g64(&state64[0], &state64[4], &state64[8], &state64[12], round, 0, m);
		g64(&state64[1], &state64[5], &state64[9], &state64[13], round, 2, m);
		g64(&state64[2], &state64[6], &state64[10], &state64[14], round, 4, m);
		g64(&state64[3], &state64[7], &state64[11], &state64[15], round, 6, m);
		
		// diagonal steps
		g64(&state64[0], &state64[5], &state64[10], &state64[15], round, 8, m);
		g64(&state64[1], &state64[6], &state64[11], &state64[12], round, 10, m);
		g64(&state64[2], &state64[7], &state64[8], &state64[13], round, 12, m);
		g64(&state64[3], &state64[4], &state64[9], &state64[14], round, 14, m);
	}
  */
#include "rounds64.h"; 

}

//copy 
static inline void finit512(uint64_t h[8], uint64_t s[4]){
  h[0] = h[0] ^ s[0] ^ (*v0) ^ (*v8);
  h[1] = h[1] ^ s[1] ^ (*v1) ^ (*v9);
  h[2] = h[2] ^ s[2] ^ (*v2) ^ (*v10);
  h[3] = h[3] ^ s[3] ^ (*v3) ^ (*v11);
  h[4] = h[4] ^ s[0] ^ (*v4) ^ (*v12);
  h[5] = h[5] ^ s[1] ^ (*v5) ^ (*v13);
  h[6] = h[6] ^ s[2] ^ (*v6) ^ (*v14);
  h[7] = h[7] ^ s[3] ^ (*v7) ^ (*v15);	
}

static inline void compress64(uint64_t *h, uint64_t *m, uint64_t *s, uint64_t * t){
	init512(h, s, t);
	rounds512(m);
	finit512(h,s);
}

static inline uint64_t pad512(unsigned char *message, uint64_t len, uint32_t *comPadding, unsigned char *padded); 
unsigned char *blake512(unsigned char *message, unsigned len, unsigned char *s, unsigned char *h){
	//message[0]=0x00;
        unsigned char padded[256]; 
	unsigned char *paddptr = padded; 
	//Reference data from the algorithm/paper
	uint32_t i; 
	//uint64_t *h = malloc(sizeof(uint64_t) * 8);  // hashed value. Final, is updated by compress function;
	uint64_t resto = (len*8) % 1024 ;    
	uint64_t var[2] = { 0, 0 };  	
	uint64_t blocksSemPadding;
	uint32_t blocksComPadding=0; 
	
	blocksSemPadding = pad512(message, (uint64_t ) len, &blocksComPadding, padded);
	//prettyPrinter64(message, (blocksComPadding+blocksSemPadding+1)*128, "msg@pad:\n");
	
	// Initialize h with IV 
	initH512(h);
	uint64_t bytes_total = (128 * blocksSemPadding); 
	uint64_t round; 
	uint64_t *type = message; 
	//	prettyPrinter64(message, bytes_total, "msg@pad:\n");
	//	prettyPrinter64(padded, 256, "pad@pad:\n");
	for (round =0, i=0 ; round < bytes_total; round += 8, i++){
	  type[i] = U8TO64_BE(message + round); 
	}
	type = padded; 
	for (round =0, i=0 ; round < 256; round += 8, i++){
	  type[i] = U8TO64_BE(&padded[round]); 
	}

	//	prettyPrinter64(message, bytes_total, "msg@pad:\n");
	//	prettyPrinter64(padded, 256, "pad@pad:\n");

	for (i=0; i<blocksSemPadding; i++) {
		var[0] += 1024;
		if(var[0]==0){
			var[1]++;
		}
		compress64(h, message + i*128, s, &var); 
	}
	
	// Last message block
	i =0; 
	if(resto){
		var[0] += resto; 
		if(var[0]==0){
			var[1]++;
		}
		compress64(h, paddptr + i++*128, s, &var);
	}
	
	// Add block only with padding, if needed
	if (blocksComPadding == 1){
		var[0]=0;
		var[1]=0;
		compress64(h, paddptr + i*128, s, &var); 
	}
	
	return (unsigned char *) h;
}

static inline uint64_t pad512(unsigned char *message, uint64_t len, uint32_t *comPadding, unsigned char *padded){
	
	uint64_t nBlocks = (len/128);   // Number of blocks in message.
	uint64_t resto = len % 128;  // What is left from message to fill. 
	uint64_t num_zeros; // Number of 0x00 bytes to pad message with. 
	
	unsigned char *begin_of_last_block = message+(len-resto);  // Begin of last block with message
	memcpy(padded, begin_of_last_block, resto); 
	begin_of_last_block = padded; 
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
