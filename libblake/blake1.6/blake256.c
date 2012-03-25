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

#define LE_BLOCK_2_BE(msg_ptr, message)\
(msg_ptr)[1] = U8TO32_BE( (message) + 4); \ 
(msg_ptr)[2] = U8TO32_BE( (message) + 8); \ 
(msg_ptr)[3] = U8TO32_BE( (message) + 12); \
(msg_ptr)[4] = U8TO32_BE( (message) + 16); \
(msg_ptr)[5] = U8TO32_BE( (message) + 20); \
(msg_ptr)[6] = U8TO32_BE( (message) + 24); \
(msg_ptr)[7] = U8TO32_BE( (message) + 28); \
(msg_ptr)[8] = U8TO32_BE( (message) + 32); \
(msg_ptr)[9] = U8TO32_BE( (message) + 36); \
(msg_ptr)[10] = U8TO32_BE( (message) + 40); \
(msg_ptr)[11] = U8TO32_BE( (message) + 44); \
(msg_ptr)[12] = U8TO32_BE( (message) + 48); \
(msg_ptr)[13] = U8TO32_BE( (message) + 52); \
(msg_ptr)[14] = U8TO32_BE( (message) + 56); \
(msg_ptr)[15] = U8TO32_BE( (message) + 60); 

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

#define INITH256(h)\
  (h)[0] = 0x6A09E667UL; \
  (h)[1] = 0xBB67AE85UL; \
  (h)[2] = 0x3C6EF372UL; \
  (h)[3] = 0xA54FF53AUL; \
  (h)[4] = 0x510E527FUL; \
  (h)[5] = 0x9B05688CUL; \
  (h)[6] = 0x1F83D9ABUL; \
  (h)[7] = 0x5BE0CD19UL;  


//copy
#define INIT256(h,s,t)\
  *v0  = (h)[0]; \
  *v1  = (h)[1]; \
  *v2  = (h)[2]; \
  *v3  = (h)[3]; \
  *v4  = (h)[4]; \
  *v5  = (h)[5]; \
  *v6  = (h)[6]; \
  *v7  = (h)[7]; \
  *v8  = (s)[0] ^ 0x243F6A88; \
  *v9  = (s)[1] ^ 0x85A308D3; \
  *v10 = (s)[2] ^ 0x13198A2E; \
  *v11 = (s)[3] ^ 0x03707344; \
  *v12 = (t)[0] ^ 0xA4093822; \
  *v13 = (t)[0] ^ 0x299F31D0; \
  *v14 = (t)[1] ^ 0x082EFA98; \
  *v15 = (t)[1] ^ 0xEC4E6C89;  

//copy
#define FINIT256(h, s)\
  (h)[0] = (h)[0] ^ (s)[0] ^ (*v0) ^ (*v8);\
  (h)[1] = (h)[1] ^ (s)[1] ^ (*v1) ^ (*v9);\
  (h)[2] = (h)[2] ^ (s)[2] ^ (*v2) ^ (*v10);\
  (h)[3] = (h)[3] ^ (s)[3] ^ (*v3) ^ (*v11);\
  (h)[4] = (h)[4] ^ (s)[0] ^ (*v4) ^ (*v12);\
  (h)[5] = (h)[5] ^ (s)[1] ^ (*v5) ^ (*v13);\
  (h)[6] = (h)[6] ^ (s)[2] ^ (*v6) ^ (*v14);\
  (h)[7] = (h)[7] ^ (s)[3] ^ (*v7) ^ (*v15);


static inline void compress(uint32_t *h, uint32_t *m, uint32_t *s, uint32_t * t){
	INIT256(h, s, t);
        #include "rounds32.h";
	FINIT256(h,s); 
}

static inline uint64_t pad256(unsigned char *message, uint64_t len, uint32_t *comPadding, unsigned char * padded); 
unsigned char *blake256(unsigned char *message, unsigned len, unsigned char *s, unsigned char *h){
        unsigned char   padded[128]; 
	uint32_t i; 
	uint64_t resto = (len*8) % 512 ;    
	uint64_t var = 0;  	
	uint64_t blocksSemPadding;
	uint32_t blocksComPadding=0; 
	
	blocksSemPadding = pad256(message, (uint64_t ) len, &blocksComPadding, padded);
	
	// Initialize h with IV 
	INITH256((uint32_t *)h);

	uint64_t bytes_total = (64* blocksSemPadding); 
	uint64_t round; 
	uint32_t *type = message; 
	uint32_t *m_ptr = message; 
	//TODO - posso saltar de 64 bytes em 64 bytes

	for (i=0; i < blocksSemPadding ; i++, m_ptr += 64  ){
	  LE_BLOCK_2_BE(msg_ptr, message); 
	}
	// type[i] = U8TO32_BE(message + round);

	type = padded; 

	#include "padded32.h"

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
uint64_t pad256(unsigned char *message, uint64_t len, uint32_t *comPadding, unsigned char *padded){
	
	uint64_t nBlocks = (len/64);   // Number of blocks in message.
	uint64_t resto = len % 64;  // What is left from message to fill. 
	uint64_t num_zeros; // Number of 0x00 bytes to pad message with. 

	unsigned char *begin_of_last_block = message+(len-resto);  // Begin of last block with message
	memcpy(padded, begin_of_last_block, resto); //copy the last bytes of message to the block to be padded
	begin_of_last_block = padded; 
	unsigned char * ptr_begin_pad = begin_of_last_block + resto; // Begin of padding
	
	if(resto == 0){
		num_zeros = 54;
		*comPadding=1;
		*ptr_begin_pad++ =  0x80; 
		memset(ptr_begin_pad, 0x00, num_zeros); 
		*(ptr_begin_pad++ + num_zeros) = (unsigned char) 0x01; 
		dumpLen(ptr_begin_pad + num_zeros , len*8); 
	} 
	else if(resto < 55){
		num_zeros = 54 - resto;
		*ptr_begin_pad++ =  0x80; 
		memset(ptr_begin_pad, 0x00, num_zeros); 
		*(ptr_begin_pad++ + num_zeros) = (unsigned char) 0x01; 
		dumpLen(ptr_begin_pad + num_zeros , len*8);  
	}
	else if(resto > 55){
		*comPadding = 1; 
		num_zeros = 118 - resto; 
		*ptr_begin_pad++ =  0x80; 
		memset(ptr_begin_pad, 0x00, num_zeros); 
		*(ptr_begin_pad++ + num_zeros) = (unsigned char) 0x01; 
		dumpLen(ptr_begin_pad + num_zeros , len*8); 
	}
	else{ // resto = 55 - special case when dont need to increase number of blocks
		*(begin_of_last_block + resto) = 0x81; 
		dumpLen(begin_of_last_block + resto + 1, len * 8);
	}
	
	return nBlocks; 
}
