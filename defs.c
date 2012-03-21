#include "defs.h"

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

void convertNinja(unsigned char *s , uint32_t len){
	int i; 
	for (i = 0 ; i < len ; i+=8){
		convert_bytes(&s[i], 8); 
	}
}

void prettyPrinter(unsigned char * hh, uint32_t len, char *message){
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