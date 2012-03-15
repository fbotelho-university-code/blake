//
//  blake512.c
//  blake
//
//  Created by José Manuel Sá Lopes on 3/12/12.
//  Copyright (c) 2012 MSI@FCUL. All rights reserved.
//

// Include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Include local libraries
#include "blake512.h"

// Bit-wise operations for 64bits
#define ROT64(x,n) (((x)<<(64-n))|( (x)>>(n)))
#define ADD64(x,y) ((uint64_t)((x) + (y)))
#define XOR64(x,y) ((uint64_t)((x) ^ (y)))

uint32_t state64[4][4];


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

void init512(uint64_t h[8], uint64_t s[4], uint64_t t[2])
{	
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

void g64(uint64_t *a, uint64_t *b, uint64_t *c, uint64_t *d, uint32_t round, uint32_t i, uint64_t m[16])
{
	
	*a = ADD64((*a),(*b))+XOR64(m[sigma[round%10][2*i]], c512[sigma[round%10][2*i+1]]);
    *d = ROT64(XOR64((*d),(*a)),32);
    *c = ADD64((*c),(*d));
    *b = ROT64(XOR64((*b),(*c)),25);
    *a = ADD64((*a),(*b))+XOR64(m[sigma[round%10][2*i+1]], c512[sigma[round%10][2*i]]);
    *d = ROT64(XOR64((*d),(*a)),16);
    *c = ADD64((*c),(*d));
    *b = ROT64(XOR64((*b),(*c)),11);
	
}

void rounds512(uint64_t *m)
{
	uint32_t round;
	
	int z; 
	for (z = 0 ; z< 16 ; z++){
		convert_bytes(&m[z], sizeof(uint32_t)); 
	}
	
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

void finit512(uint64_t h[8], uint64_t s[4])
{
	h[0] = h[0] ^ s[0] ^ state64[0][0] ^ state64[2][0];
	h[1] = h[1] ^ s[1] ^ state64[0][1] ^ state64[2][1];
	h[2] = h[2] ^ s[2] ^ state64[0][2] ^ state64[2][2];
	h[3] = h[3] ^ s[3] ^ state64[0][3] ^ state64[2][3];
	h[4] = h[4] ^ s[0] ^ state64[1][0] ^ state64[3][0];
	h[5] = h[5] ^ s[1] ^ state64[1][1] ^ state64[3][1];
	h[6] = h[6] ^ s[2] ^ state64[1][2] ^ state64[3][2];
	h[7] = h[7] ^ s[3] ^ state64[1][3] ^ state64[3][3];	
}

void compress(uint64_t *h, uint64_t *m, uint64_t *s, uint64_t * t){
	init512(h, s, t);
	rounds512(m);
	finit512(h,s);
}

unsigned char *blake512(unsigned char *message, unsigned long len)
{
	uint32_t i;	
	uint64_t s[4] = { 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000 };
	uint64_t t[2] = { 0x0000000000000008, 0x0000000000000000 };
	uint64_t m[16]; 
	
	//Reference data from the algorithm/paper
	uint32_t *h = malloc(sizeof(uint64_t) * 8);  // hashed value. Final, is updated by compress function;
    
	
	uint64_t nBlocks; //Number of blocks to be hashed
	
	//TODO - does casting len works ok? 
	nBlocks = 1;//pad256(message, (uint64_t ) len,  &t); 
	
	// Bloco 1
	m[ 0] = 0x0080000000000000;
	m[ 1] = 0x0000000000000000; 
	m[ 2] = 0x0000000000000000;
	m[ 3] = 0x0000000000000000; 
	m[ 4] = 0x0000000000000000; 
	m[ 5] = 0x0000000000000000; 
	m[ 6] = 0x0000000000000000; 
	m[ 7] = 0x0000000000000000; 
	m[ 8] = 0x0000000000000000;
	m[ 9] = 0x0000000000000000; 
	m[10] = 0x0000000000000000; 
	m[11] = 0x0000000000000000; 
	m[12] = 0x0000000000000000; 
	m[13] = 0x0000000000000001; 
	m[14] = 0x0000000000000000; 
	m[15] = 0x0000000800000008;
	
	initH512(h); // Initialize h with IV
	for (i=0; i<nBlocks; i++) {
		compress(h,message + i*128, s, t + (i*2));
	}
	
	return (unsigned char *) h;
}

void convert_bytes(unsigned char *start, int len){
	int i,j; 
	unsigned char tmp; 
	//TODO - len not par 
	for (i=0, j =len-1  ; i < len/2 ; i++, j--) {
		tmp = start[i]; 
		start[i] = start[j]; 
		start[j] = tmp; 
	}  
}

void dumpLen(void * ptr, uint64_t len){
	convert_bytes( (unsigned char *) &len, sizeof(uint64_t)); 
	memcpy(ptr, &len, sizeof(uint64_t)); 
}

int main(int argc, char **argv){
	unsigned char m[64]; 
	uint64_t *t[2]; 
	
	m[0] = 0;
	uint64_t *h = m; 
	uint64_t len = 1;
	
	unsigned char *hh = blake512(m, len);
	
	int i,j; 
	puts("hash");
	for( i=0; i<64; i++){
		(void)printf("%02X",hh[i]);
		if(!((i+1)%4)) printf(" ");
	}
	
	return 0; 
}