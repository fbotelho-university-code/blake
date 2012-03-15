//
//  defs.c
//  blake
//
//  Created by José Manuel Sá Lopes on 3/12/12.
//  Copyright (c) 2012 MSI@FCUL. All rights reserved.
//

#include <stdio.h>
#include "defs.h"

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

void convertNinja (unsigned char *s , int len){
	int i; 
	for (i = 0 ; i < len ; i+=4){
		convert_bytes(&s[i], 4); 
	}
}

void prettyPrinter(unsigned char * hh, int len, char *message){
	puts("");
	printf("%s \n", message); 
	int j; 
	for( j=0; j<len; j++){
		(void)printf("%02X", hh[j]);
		if(!((j+1)%4)) printf(" ");
		if (((j+1) % 64) == 0) puts(""); 
	}
	puts("\n");
}