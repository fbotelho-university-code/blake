// Include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Include local libraries
#include "blake256.h"
#include "blake.h"
//TODO - set consts on blake

//Functions headers.
static inline uint64_t pad256(unsigned char *message, uint64_t len, unsigned *comPadding, unsigned char * padded); 
static inline void compress(uint32_t *h, const uint32_t *m, const uint32_t *s, const uint32_t * t); 
unsigned char *blake256(unsigned char *message, unsigned len, unsigned char *s, unsigned char *h); 

//16 Constants for Blake-256
static const uint32_t con[16] = {
    0x243F6A88, 0x85A308D3,
    0x13198A2E, 0x03707344,
    0xa4093822, 0x299F31D0,
    0x082EFA98, 0xEC4E6C89,
    0x452821E6, 0x38D01377,
    0xBE5466CF, 0x34E90C6C,
    0xC0AC29B7, 0xC97C50DD,
    0x3F84D5B5, 0xB5470917 
};
//Sima table extended here to avoid rounding values by module 10. 
static const unsigned char sigma[][16] = {
    {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15 } ,
    { 14, 10,  4,  8,  9, 15, 13,  6,  1, 12,  0,  2, 11,  7,  5,  3 } ,
    { 11,  8, 12,  0,  5,  2, 15, 13, 10, 14,  3,  6,  7,  1,  9,  4 } ,
    {  7,  9,  3,  1, 13, 12, 11, 14,  2,  6,  5, 10,  4,  0, 15,  8 } ,
    {  9,  0,  5,  7,  2,  4, 10, 15, 14,  1, 11, 12,  6,  8,  3, 13 } ,
    {  2, 12,  6, 10,  0, 11,  8,  3,  4, 13,  7,  5, 15, 14,  1,  9 } ,
    { 12,  5,  1, 15, 14, 13,  4, 10,  0,  7,  6,  3,  9,  2,  8, 11 } ,
    { 13, 11,  7, 14, 12,  1,  3,  9,  5,  0, 15,  4,  8,  6,  2, 10 } ,
    {  6, 15, 14,  9, 11,  3,  0,  8, 12,  2, 13,  7,  1,  4, 10,  5 } ,
    { 10,  2,  8,  4,  7,  6,  1,  5, 15, 11,  9, 14,  3, 12, 13 , 0 } ,
    {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15 } ,
    { 14, 10,  4,  8,  9, 15, 13,  6,  1, 12,  0,  2, 11,  7,  5,  3 } ,
    { 11,  8, 12,  0,  5,  2, 15, 13, 10, 14,  3,  6,  7,  1,  9,  4 } ,
    {  7,  9,  3,  1, 13, 12, 11, 14,  2,  6,  5, 10,  4,  0, 15,  8 } ,
    {  9,  0,  5,  7,  2,  4, 10, 15, 14,  1, 11, 12,  6,  8,  3, 13 } ,
    {  2, 12,  6, 10,  0, 11,  8,  3,  4, 13,  7,  5, 15, 14,  1,  9 } ,
    { 12,  5,  1, 15, 14, 13,  4, 10,  0,  7,  6,  3,  9,  2,  8, 11 } ,
    { 13, 11,  7, 14, 12,  1,  3,  9,  5,  0, 15,  4,  8,  6,  2, 10 } ,
    {  6, 15, 14,  9, 11,  3,  0,  8, 12,  2, 13,  7,  1,  4, 10,  5 } ,
    { 10,  2,  8,  4,  7,  6,  1,  5, 15, 11,  9, 14,  3, 12, 13 , 0 } ,
};

static uint32_t state32[16]; //Matrix v 
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


/* Begin of functions  */

// Bit-wise operations for 32bits
#define ROT32(x,n) (((x)<<(32-n))|( (x)>>(n)))
#define ADD32(x,y) ((uint32_t)((x) + (y)))
#define XOR32(x,y) ((uint32_t)((x) ^ (y)))

//Conversion of litle endian to big endian. Returns BIG endian 32 bits value equivalent from p. 
#define U8TO32_BE(p) \
  (((uint32_t)((p)[0]) << 24) | \
   ((uint32_t)((p)[1]) << 16) | \
   ((uint32_t)((p)[2]) <<  8) | \
   ((uint32_t)((p)[3])      ))

#define LE_BLOCK_2_BE(mptr)\
  {\
uint32_t *msg_ptr = (uint32_t*)   (mptr);\
unsigned char *message = (unsigned char *) (mptr);\
(msg_ptr)[0] = U8TO32_BE((message)); \
(msg_ptr)[1] = U8TO32_BE( (((message) + 4))); \
(msg_ptr)[2] = U8TO32_BE( ((message) + 8)); \
(msg_ptr)[3] = U8TO32_BE( ((message) + 12)); \
(msg_ptr)[4] = U8TO32_BE( ((message) + 16)); \
(msg_ptr)[5] = U8TO32_BE( ((message) + 20)); \
(msg_ptr)[6] = U8TO32_BE( ((message) + 24)); \
(msg_ptr)[7] = U8TO32_BE( ((message) + 28)); \
(msg_ptr)[8] = U8TO32_BE( ((message) + 32)); \
(msg_ptr)[9] = U8TO32_BE( ((message) + 36)); \
(msg_ptr)[10] = U8TO32_BE( ((message) + 40)); \
(msg_ptr)[11] = U8TO32_BE( ((message) + 44)); \
(msg_ptr)[12] = U8TO32_BE( ((message) + 48)); \
(msg_ptr)[13] = U8TO32_BE( ((message) + 52)); \
(msg_ptr)[14] = U8TO32_BE( ((message) + 56)); \
(msg_ptr)[15] = U8TO32_BE( ((message) + 60)); \
}\

//Initialization vectors, used only once. 
#define INITH256(h)\
  (h)[0] = 0x6A09E667UL; \
  (h)[1] = 0xBB67AE85UL; \
  (h)[2] = 0x3C6EF372UL; \
  (h)[3] = 0xA54FF53AUL; \
  (h)[4] = 0x510E527FUL; \
  (h)[5] = 0x9B05688CUL; \
  (h)[6] = 0x1F83D9ABUL; \
  (h)[7] = 0x5BE0CD19UL;  

//Initialization of State for each block 
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
//Finalization@ compressing the block
#define FINIT256(h, s)\
  (h)[0] = (h)[0] ^ (s)[0] ^ (*v0) ^ (*v8);\
  (h)[1] = (h)[1] ^ (s)[1] ^ (*v1) ^ (*v9);\
  (h)[2] = (h)[2] ^ (s)[2] ^ (*v2) ^ (*v10);\
  (h)[3] = (h)[3] ^ (s)[3] ^ (*v3) ^ (*v11);\
  (h)[4] = (h)[4] ^ (s)[0] ^ (*v4) ^ (*v12);\
  (h)[5] = (h)[5] ^ (s)[1] ^ (*v5) ^ (*v13);\
  (h)[6] = (h)[6] ^ (s)[2] ^ (*v6) ^ (*v14);\
  (h)[7] = (h)[7] ^ (s)[3] ^ (*v7) ^ (*v15);

/*
 * Function that performs the compression of one block. 
 * @param h The chained value. i.e., the result of the compression of the block is setted here. H must be initialized already; 
 * @param m The 64 bytes block message; 
 * @param s The salt;
 * @param t The counter;
 * The functions performs compression and stores it at h. 
 */
static inline void compress(uint32_t *h, const  uint32_t *m, const uint32_t *s, const uint32_t * t){
	INIT256(h, s, t);
        #include "rounds32.h";
	FINIT256(h,s); 
}

unsigned char *blake256(unsigned char *message, unsigned len, unsigned char *s, unsigned char *h){

  unsigned char   padded[128];  // Space for two padding blocks. Maybe only 1 is necessary. 
  uint64_t counter = 0;   //Counts the number of bits hashed so far. (i.e., see t in specification) 
  uint64_t resto = (len*8) % 512 ;    // The leftover in bytes of the last message block. 
  uint64_t blocksSemPadding;    
  unsigned  blocksComPadding=0;    //Can be 0 or one. One when last special block with no message bits.
  unsigned char *cmsg = message;  // TO manipulate message blocks
  unsigned  i;   //the usual suspect. 



  blocksSemPadding = pad256(message, (uint64_t ) len, &blocksComPadding, padded);
  // Initialize hash  with IV 
  INITH256((uint32_t *)h);

  for (i=0; i < blocksSemPadding ; i++, cmsg += 64){
	  LE_BLOCK_2_BE(cmsg); 
  }

  cmsg = padded; 
  LE_BLOCK_2_BE(cmsg); 
  if (blocksComPadding){
    cmsg+=64; 
    LE_BLOCK_2_BE(cmsg); 
  }
  
  for (i=0,cmsg =message; i<blocksSemPadding; i++, cmsg +=64) {
    counter += 512; 
    compress((uint32_t *) h, (const  uint32_t*) cmsg, (const uint32_t *) s, (const uint32_t *) &counter); 
  }
  
// Last message block
  if(resto){
    counter += resto; 
    compress((uint32_t *) h, (const  uint32_t *) padded, (const uint32_t *) s, (const uint32_t *) &counter); 

  }
  
// Add block only with padding, if needed
  if (blocksComPadding == 1){
    counter=0; //Last block, does not contain message bits. (see spec). 
    if (resto == 0 ){ 
      compress((uint32_t *) h, (const  uint32_t*) padded, (const uint32_t *) s, (const uint32_t *) &counter); 
    }
    else{
      compress((uint32_t *) h, (const  uint32_t*) &padded[64], (const uint32_t *) s, (const uint32_t *) &counter); 
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
