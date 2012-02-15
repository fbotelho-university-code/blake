//
//  blake.c
//  BLAKE
//
//  Created by José Manuel Sá Lopes on 2/14/12.
//  Copyright (c) 2012 MSI@FCUL. All rights reserved.
//

// Include standard libraries

#define ROT32(x,n) (((x)<<(32-n))|( (x)>>(n)))
#define ADD32(x,y)   ((uint32_t)((x) + (y)))
#define XOR32(x,y)    ((uint32_t)((x) ^ (y)))
  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Include local libraries
#include "blake.h"

uint32_t state32[4][4];
uint64_t state64[4][4];

void init(uint32_t h[8], uint32_t s[4], uint32_t t[2])
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

void g(uint32_t *a, uint32_t *b, uint32_t *c, uint32_t *d, uint32_t round, uint32_t i, uint32_t m[16])
{

  *a = ADD32((*a),(*b))+XOR32(m[sigma[round][2*i]], c256[sigma[round][2*i+1]]); \
  *d = ROT32(XOR32((*d),(*a)),16);					\
  *c = ADD32((*c),(*d));						\
  *b = ROT32(XOR32((*b),(*c)),12);					\
  *a = ADD32((*a),(*b))+XOR32(m[sigma[round][2*i+1]], c256[sigma[round][2*i]]); \
  *d = ROT32(XOR32((*d),(*a)), 8);					\
  *c = ADD32((*c),(*d));						\
  *b = ROT32(XOR32((*b),(*c)), 7);					\

  /* *a = (*a) + (*b) + (m[sigma[round][2*i]] ^ c256[sigma[round][2*i+1]]); */
  /* *d = ((*d) ^ (*a)) >> 16; */
  /* *c = (*c) + (*d); */
  /* *b = ((*b) ^ (*c)) >> 12; */
  /* *a = (*a) + (*b) + (m[sigma[round][2*i+1]] ^ c256[sigma[round][2*i]]); */
  /* *d = ((*d) ^ (*a)) >> 8; */
  /* *c = (*c) + (*d); */
  /* *b = ((*b) ^ (*c)) >> 7; */
	
}

void rounds(uint32_t m[16])
{
	uint32_t round=0,i=0,j=0;
		
	while (j<14)
	{
		// column steps
		g(&state32[0][0], &state32[1][0], &state32[2][0], &state32[3][0], j, i++, m);
		g(&state32[0][1], &state32[1][1], &state32[2][1], &state32[3][1], j, i++, m);
		g(&state32[0][2], &state32[1][2], &state32[2][2], &state32[3][2], j, i++, m);
		g(&state32[0][3], &state32[1][3], &state32[2][3], &state32[3][3], j, i++, m);
		
		// diagonal steps
		g(&state32[0][0], &state32[1][1], &state32[2][2], &state32[3][3], j, i++, m);
		g(&state32[0][1], &state32[1][2], &state32[2][3], &state32[3][0], j, i++, m);
		g(&state32[0][2], &state32[1][3], &state32[2][0], &state32[3][1], j, i++, m);
		g(&state32[0][3], &state32[1][0], &state32[2][1], &state32[3][2], j, i++, m);
	
		j++;
		i=0;
	}
	
}

void finit(uint32_t h[8], uint32_t s[4])
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

unsigned char *blake256(unsigned char *message, unsigned len)
{
	uint32_t i;
	uint32_t *h = malloc(sizeof(uint32_t) * 8); 

	uint32_t s[4] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
	uint32_t t[2] = { 0x0000000008 , 0x00000000};
	uint32_t m[16]; 
	
	m[0] = 0x00800000;
	m[1] = 0x00000000; 
	m[2] = 0x00000000; 
	m[3] = 0x00000000; 
	m[4] = 0x00000000; 
	m[5] = 0x00000000; 
	m[6] = 0x00000000; 
	m[7] = 0x00000000; 
	m[8] = 0x00000000;
	m[9] = 0x00000000; 
	m[10] = 0x00000000; 
	m[11] = 0x00000000; 
	m[12] = 0x00000000; 
	m[13] = 0x00000000; 
	m[14] = 0x00000000; 
	m[15] = 0x00000008; 

	
	/* uint64_t len64 = (uint64_t) len; */
	/* uint64_t newLen = len64; */
	/* uint64_t nBlocks; */
	
	
	/* unsigned char  *mp_len; // onde fica o len */
	/* unsigned char  *mp_one; // onde começa o padding;  */
	/* unsigned padLen;  //quanto de padding;  */
	
	/* mp_one = message + len;  */
	
	/* unsigned resto = len % 512;  */
	
	/* if ( resto > 447){ */
	/* 	padLen = 447 + (512 - resto);  */
	/* } */
	/* else{ */
	/* 	padLen = 447 - resto;  */
	/* } */

	/* mp_len = mp_one + padLen;  */

	
	/* if(padLen > 0){ */
	/*   //	*mp_one = 0x01; */
	/* 	newLen++; */
	/* } */
	/* if (padLen !=0){ */
	/*   //	memset(mp_one+1, 0x00, padLen-1); */
	/* 	newLen+=padLen-1; */
	/* } */

	/* //\*mp_len = 0x01; */
	/* //	memcpy(mp_len+1, &len64, 8); */
	/* newLen+=65; */
	
	/* if((newLen % 512) == 0){ */
	/*    nBlocks = newLen / 512; */
	/* }else{ */
	/* 	fprintf(stderr, "Fuck shit deu merda da grossa!"); */
	/* } */
	
	h[0] = IV256[0];
	h[1] = IV256[1];
	h[2] = IV256[2];
	h[3] = IV256[3];
	h[4] = IV256[4];
	h[5] = IV256[5];
	h[6] = IV256[6];
	h[7] = IV256[7];
	
	for (i=0; i< 1; i++) {
		init(h, s, t);
		rounds(m);
		finit(h,s);
	}
	
	return( (unsigned char *) h);
}

char *blake512(char *message)
{
	
	return(NULL);
}
