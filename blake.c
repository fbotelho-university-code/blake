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
#include "blake.h"

// Bit-wise operations for 32bits
#define ROT32(x,n) (((x)<<(32-n))|( (x)>>(n)))
#define ADD32(x,y) ((uint32_t)((x) + (y)))
#define XOR32(x,y) ((uint32_t)((x) ^ (y)))

// Bit-wise operations for 64bits
#define ROT64(x,n) (((x)<<(64-n))|( (x)>>(n)))
#define ADD64(x,y) ((uint64_t)((x) + (y)))
#define XOR64(x,y) ((uint64_t)((x) ^ (y)))

uint32_t state32[4][4];
uint64_t state64[4][4];

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

void g32(uint32_t *a, uint32_t *b, uint32_t *c, uint32_t *d, uint32_t round, uint32_t i, uint32_t m[16])
{

  *a = ADD32((*a),(*b))+XOR32(m[sigma[round%10][2*i]], c256[sigma[round%10][2*i+1]]);
  *d = ROT32(XOR32((*d),(*a)),16);
  *c = ADD32((*c),(*d));
  *b = ROT32(XOR32((*b),(*c)),12);
  *a = ADD32((*a),(*b))+XOR32(m[sigma[round%10][2*i+1]], c256[sigma[round%10][2*i]]);
  *d = ROT32(XOR32((*d),(*a)), 8);
  *c = ADD32((*c),(*d));
  *b = ROT32(XOR32((*b),(*c)), 7);
  
/*
	// ROT32(x,n) (((x)<<(32-n))|( (x)>>(n)))
  *a = ((uint32_t)((*a) + (*b))) + ((uint32_t)(m[sigma[round][2*i]] ^ c256[sigma[round][2*i+1]]));
  *d = (16 << ((uint32_t)((*d) ^ (*a))) | ((uint32_t)((*d) ^ (*a))) >> 16);
  *c = ((uint32_t)((*c) + (*d)));
  *b = (20 << ((uint32_t)((*b) ^ (*c))) | ((uint32_t)((*b) ^ (*c))) >> 12);
  *a = ((uint32_t)((*a) + (*b))) + ((uint32_t)(m[sigma[round][2*i+1]] ^ c256[sigma[round][2*i]]));
  *d = (24 << ((uint32_t)((*d) ^ (*a))) | ((uint32_t)((*d) ^ (*a))) >> 8);
  *c = (uint32_t)((*c) + (*d));
  *b = (25 << ((uint32_t)((*b) ^ (*c))) | ((uint32_t)((*b) ^ (*c))) >> 7);
*/
	
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

void rounds256(uint32_t m[16])
{
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

void rounds512(uint64_t m[16])
{
	uint32_t round;
	
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

unsigned char *blake256(unsigned char *message, unsigned long long len)
{
	uint32_t i;
	uint32_t *h = malloc(sizeof(uint32_t) * 8); 
	unsigned char *hh = h;
	
	uint32_t s[4] = { 0x61616161, 0x61616161, 0x61616161, 0x61616161 };
	uint32_t t[2] = { 0x00000000, 0x00000000 };
	uint32_t m[16]; 
	
	unsigned char *lenChar = len;
	uint64_t newLen = len;
	uint64_t nBlocks;
	
	
	unsigned char  *mp_len; // onde fica o len 
	unsigned char  *mp_one; // onde começa o padding;  
	unsigned long long padLen;  //quanto de padding;

	unsigned char *msg;
		
	unsigned long long resto = len % 512;
	
	if(resto > 447){
		padLen = 447 + (512 - resto);
	}
	else{
	 	padLen = 447 - resto;
	}
	
	if(padLen > 0){
		newLen++;
		newLen+=padLen-1;
	}
	newLen+=65;
	
	msg = (unsigned char *)malloc(newLen);
	if(!msg) exit(-99);
	
	memcpy(msg, message, len);
	
	mp_one = msg + len;
	mp_len = mp_one + padLen;		
	
	if(padLen>0){
		*mp_one = 0x01;
		memset(mp_one+1, 0x00, padLen-1); 
	}
	
	mp_len = 0x01;
	
	for(i=1;i<9;i++)
		mp_len[i]=lenChar[i-1];
	
	//memcpy(mp_len+1, &len, 8);
	
	if((newLen % 512) == 0){
	   nBlocks = newLen / 512;
	}else{
		fprintf(stderr, "Fuck shit deu merda da grossa!");
		exit(-99);
	}
	
	h[0] = IV256[0];
	h[1] = IV256[1];
	h[2] = IV256[2];
	h[3] = IV256[3];
	h[4] = IV256[4];
	h[5] = IV256[5];
	h[6] = IV256[6];
	h[7] = IV256[7];
	
	for (i=0; i<nBlocks; i++) {
		init256(h, s, t);
		rounds256(m);
		finit256(h,s);
		t[0]+=512;
		if (t[0]==0) t[1]++;
	}
	
	return(hh);
}

unsigned char *blake512(unsigned char *message, unsigned long long len)
{
	uint32_t i;
	uint64_t *h = malloc(sizeof(uint64_t) * 8); 
	unsigned char *hh = h;
	
	uint64_t s[4] = { 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000 };
	uint64_t t[2] = { 0x0000000000000008, 0x0000000000000000 };
	uint64_t m[16]; 
	
	uint64_t len64 = (uint64_t) len;
	uint64_t newLen = len64;
	uint64_t nBlocks;
	
	unsigned char  *mp_len; // onde fica o len 
	unsigned char  *mp_one; // onde começa o padding;  
	unsigned padLen;  //quanto de padding;

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
	
	h[0] = IV512[0];
	h[1] = IV512[1];
	h[2] = IV512[2];
	h[3] = IV512[3];
	h[4] = IV512[4];
	h[5] = IV512[5];
	h[6] = IV512[6];
	h[7] = IV512[7];
	
	for (i=0; i<1; i++) {
		init512(h, s, t);
		rounds512(m);
		finit512(h,s);
		t[0]+=1024;
	}
	
	return(hh);
}
