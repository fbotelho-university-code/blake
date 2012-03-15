//
//  blake.c
//  BLAKE
//
//  Created by José Manuel Sá Lopes on 2/14/12.
//  Copyright (c) 2012 MSI@FCUL. All rights reserved.
//

// Include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Include local libraries
#include "blake256.h"
#include "defs.h"

// Bit-wise operations for 32bits
#define ROT32(x,n) (((x)<<(32-n))|( (x)>>(n)))
#define ADD32(x,y) ((uint32_t)((x) + (y)))
#define XOR32(x,y) ((uint32_t)((x) ^ (y)))

void dumpLen(void * ptr, uint64_t len); 
int  pad256(unsigned char *message, uint64_t len, uint32_t **t, uint64_t *); 
uint32_t state32[4][4];

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

void init256(uint32_t h[8], uint32_t s[4], uint32_t t[2])
{	
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

void g32(uint32_t *a, uint32_t *b, uint32_t *c, uint32_t *d, uint32_t round, uint32_t i, uint32_t *m)
{
	
	*a = ADD32((*a),(*b))+XOR32(m[sigma[round%10][2*i]], c256[sigma[round%10][2*i+1]]);
	*d = ROT32(XOR32((*d),(*a)),16);
	*c = ADD32((*c),(*d));
	*b = ROT32(XOR32((*b),(*c)),12);
	*a = ADD32((*a),(*b))+XOR32(m[sigma[round%10][2*i+1]], c256[sigma[round%10][2*i]]);
	*d = ROT32(XOR32((*d),(*a)), 8);
	*c = ADD32((*c),(*d));
	*b = ROT32(XOR32((*b),(*c)), 7);
	
}

void rounds256(uint32_t *m)
{
	int z; 
	for (z = 0 ; z< 16 ; z++){
		convert_bytes(&m[z], sizeof(uint32_t)); 
	}
	uint32_t round;
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

void finit256(uint32_t h[8], uint32_t s[4])
{
	h[0] = h[0] ^ s[0] ^ state32[0][0] ^ state32[2][0];
	h[1] = h[1] ^ s[1] ^ state32[0][1] ^ state32[2][1];
	h[2] = h[2] ^ s[2] ^ state32[0][2] ^ state32[2][2];
	h[3] = h[3] ^ s[3] ^ state32[0][3] ^ state32[2][3];
	h[4] = h[4] ^ s[0] ^ state32[1][0] ^ state32[3][0];
	h[5] = h[5] ^ s[1] ^ state32[1][1] ^ state32[3][1];
	h[6] = h[6] ^ s[2] ^ state32[1][2] ^ state32[3][2];
	h[7] = h[7] ^ s[3] ^ state32[1][3] ^ state32[3][3];	
}
/*
 *h[8]
 *m[16] 
 */

void compress(uint32_t *h, uint32_t *m, uint32_t *s, uint32_t * t){
	convertNinja(t, 8); 
	prettyPrinter(t, 8, "myt\n" ); 
	convertNinja(t , 8); 
	
	init256(h, s, t);
	rounds256(m);
	finit256(h,s);
}

unsigned char *blake256(unsigned char *message, unsigned long len){
	//Reference data from the algorithm/paper
	int i; 
	uint32_t *h = malloc(sizeof(uint32_t) * 8);  // hashed value. Final, is updated by compress function;
	uint32_t s[4] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000};  // No salt considered yet. 
	uint32_t *t; // Counter/Size. 
    
	
	uint64_t blocksSemPadding; //Number of blocks to be hashed
	uint64_t blocksComPadding; 
	//TODO - does casting len works ok? 
	blocksSemPadding = pad256(message, (uint64_t ) len,  &t, &blocksComPadding); 
	printf("N blocks : %d\n", (blocksComPadding + blocksSemPadding)); 
	//	convertNinja(message, (nBlocks)  * 64); 
	prettyPrinter(message, (blocksComPadding + blocksSemPadding) * 64, "message@pad:"); 
	//	convertNinja(message, (nBlocks) * 64); 
	
	/*  //debug
	 unsigned char * hh = message; 
	 puts("\nMessage:"); 
	 for( i=0; i<64; i++){
	 (void)printf("%02X",hh[i]);
	 if(!((i+1)%4)) printf(" ");
	 }
	 //undebug
	 */  initH256(h); // Initialize h with IV 
	
	
	uint64_t var = 0;  
	for (i=0; i<blocksSemPadding; i++) {
		var += i*512; 
		compress(h, message + i*64, s, &var); 
	}
	
	uint64_t resto = len % 512 ;
	var += resto; 
	compress(h, message + i*64, s, &var);
	i++; 
	
	if (blocksComPadding == 1){
		var =0; 
		compress(h, message + i*64, s, &var); 
		i++; 
	}
/*	for (i=0; i<nBlocks; i++) {
		compress(h, message + i*64, s, t + (i*2)); 
	}
*/	
	return (unsigned char *) h;
}

//Pad the message and determine the sizes of each h block. 
//Creates the array of t's (Counter) with the message number of blocks. 
//Returns the number of blocks in the message; 
int pad256(unsigned char *message, uint64_t len, uint32_t **t, uint64_t *comPadding){
	
	//TODO - create t. 
	int i; 
	uint64_t nBlocks ;   //Number of blocks in message. TODO - why 64 bits in nblocks . 
	uint64_t resto = len % 64;  // what is left from message to fill. 
	
	nBlocks = ((len%64)==0)  ? (len/64) : (len/64 ) + 1 ; // assuming there will be no new block with no message bits. 
	unsigned char *begin_of_last_block = message+(len-resto);  
	
	// Create array with upper bound of t's (considering case where we create a new block) 
	*t = malloc(sizeof(uint32_t) * 2 * (nBlocks+1)); 
	
	uint64_t * crazy = *t; 
	if (!t){
		perror("malloc: "); 
		exit(-1); 
	}
	
	//TODO - can nBlocks be 0? 
	uint64_t *myT =  (uint64_t *) *t; 
	*myT = 0; 
	for (i = 0 ; i < (nBlocks-1); i++){
		*myT += 512; 
		myT ++; 
	}
	
	*myT += ( nBlocks  == 1) ?  resto*8 : (*(myT-1)) + resto * 8; 
	 
	
	if ( resto == 55 ){
		// The case where no new block is needed and we only have to dump the perfect fit padding info.
		*(begin_of_last_block + resto ) = 0x81; 
		dumpLen(begin_of_last_block + resto +1, len * 8 ); 
	}
	else{
		unsigned num_zeros; // Numeros of 0x00 bytes to pad message with. 
		unsigned char * ptr_begin_pad = (resto == 0) ?  begin_of_last_block  : begin_of_last_block + resto; 
		
		if (resto == 0){
			//puts("zero"); 
			num_zeros = 54;
			*comPadding=1; 
			*comPadding = 1;;
			//nblocks++; 
			// Go 
			//			*( myT +1 ) = 0x00 ;
		}
		else {
			if (resto < 55){
				//puts("menor que 55"); 
				num_zeros = 54 - resto; 
				
			}
			else{
				//puts("RESTO>55");

				//	*myT = 0; 
				*comPadding =1; 
				num_zeros = 118 - resto; 
			}
		}
		
		

			//			puts ("---------------------------"); 
			//			printf("Len : %d, Resto : %d\n", len, resto); 
			//			puts("Printing the t for this case ABOVE");
			int w ; 
			for (w = 0 ; w < nBlocks ; w ++){
				char s[10]; 
				sprintf(s, "%d\n", w);  
				//convertNinja(&crazy[w], 8); 
				//	prettyPrinter(&crazy[w], 8, s ); 
				//copnvertNinja(&crazy[w] , 8); 
			}

		
		*ptr_begin_pad =  0x80; 
		memset(ptr_begin_pad+1, 0x00, num_zeros); 
		//TODO - autoincrement ptrs on the way... 
		*( ptr_begin_pad + 1 + num_zeros )  = (unsigned char) 0x01; 
		dumpLen(ptr_begin_pad  + 2 + num_zeros , len*8); 
	}
	return nBlocks; 
}

void dumpLen(void * ptr, uint64_t len){
	convert_bytes( (unsigned char *) &len, sizeof(uint64_t)); 
	memcpy(ptr, &len, sizeof(uint64_t)); 
}

/*
 int main(int argc, char **argv){
 unsigned char m[64]; 
 uint32_t *t[2]; 
 
 m[0] = 0;
 uint32_t *h = m; 
 uint32_t len = 1;
 
 unsigned char *hh = blake256(m, len);
 
 int i,j; 
 puts("hash");
 for( i=0; i<32; i++){
 (void)printf("%02X",hh[i]);
 if(!((i+1)%4)) printf(" ");
 }
 
 return 0; 
 }*/
