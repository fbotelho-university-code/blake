#include <stdlib.h>

#include "blake.h"
#include "blake256.h"
#include "blake512.h"


void convert_bytes(unsigned char *start, uint32_t len){
	int i,j; 
	unsigned char tmp; 
	//TODO - len not par 
	for (i=0, j =len-1  ; i < len/2 ; i++, j--) {
		tmp = start[i]; 
		start[i] = start[j]; 
		start[j] = tmp; 
	} 
}

void convertNinja64(unsigned char *s , uint32_t len){
	int i; 
	for (i = 0 ; i < len ; i+=8){
		convert_bytes(&s[i], 8); 
	}
}

void convertNinja32(unsigned char *s , uint32_t len){
	int i; 
	for (i = 0 ; i < len ; i+=4){
		convert_bytes(&s[i], 4); 
	}
}

void prettyPrinter64(unsigned char * hh, uint32_t len, char *message){
	puts("");
	printf("%s \n", message); 
	int j; 
	for( j=0; j<len; j++){
		(void)printf("%02X", hh[j]);
		if(!((j+1)%8)) printf(" ");
		if (((j+1) % 64) == 0) puts(""); 
	}
	puts("\n");
}

void prettyPrinter32(unsigned char * hh, uint32_t len, char *message){
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

void dumpLen(void * ptr, uint64_t len){
  	convert_bytes((unsigned char *) &len, sizeof(uint64_t)); // 8
	memcpy(ptr, &len, sizeof(uint64_t)); 
}

void BLAKE(unsigned char *data, unsigned len, unsigned char *salt, unsigned lenDigest, char *digest){
	
	switch (lenDigest) {
		case 32:
			blake256(data, len, salt, digest);
			break;
		case 64	:
			blake512(data, len, salt, digest);
			break;
		default:
			digest = NULL;
			break;
	}
	
	
}
