#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libblake/defs.h"
#include "../libblake/blake.h"
#include "../libblake/defs.h"

int main(int argc, char **argv){
	
	int i;
	
	unsigned char in[30480];
	unsigned char out32[32];
	unsigned char out64[64];
	unsigned char *hh;
	
	FILE *fp;
	
	uint32_t s32[4] = { 0x61616161, 0x61616161, 0x61616161, 0x61616161 };
	uint64_t s64[4] = { 0x6161616161616161, 0x6161616161616161, 0x6161616161616161, 0x6161616161616161 };
	
	// Open BLAKE-256 test file
	fp = fopen("correctnesstests/test_file256", "r");
	hh = malloc(32);
	if(!hh){
		puts("MALLOC ERROR ABORT");
		exit(-1);
	}
	
	// Tests for BLAKE-256
	for(i=0; i<20480; i++){
		
		// Read input
		fread(in, 1, i+1, fp);
		//prettyPrinter32(in, i+1, "in:\n");
		
		// Read output
		fread(out32, 1, 32, fp);
		//prettyPrinter32(out32, 32, "out:\n");
		
		// Hash
		BLAKE(in, i+1, s32, 32, hh);
		
		// Test
		convertNinja32(hh, 32); 
		//prettyPrinter32(hh, 32, "hash:\n");
		if(memcmp(out32,hh,32)) printf("BLAKE-256: Error in test %d\n",i+1);
	}
	
	fclose(fp);
	
	// Open BLAKE-512 test file
	fp = fopen("correctnesstests/test_file512", "r");
	
	hh = malloc(64);
	if(!hh){
		puts("MALLOC ERROR ABORT");
		exit(-1);
	}
	
	// Tests for BLAKE-512
	for(i=0; i<20480; i++){
		
		// Read input
		fread(in, 1, i+1, fp);
		//prettyPrinter64(in, i+1, "in:\n");
		
		// Read output
		fread(out64, 1, 64, fp);
		//prettyPrinter64(out64, 64, "out:\n");
		
		// Hash
		//BLAKE(in, i+1, s64, 64, hh);
		BLAKE(in, i+1, s64, 64, hh);
		
		// Test
		convertNinja64(hh, 64);
		//prettyPrinter64(hh, 64, "hash:\n");
		if(memcmp(out64,hh,64)) printf("BLAKE-512: Error in test %d\n",i+1);
	}	
	
	fclose(fp);
	return 0;
}

/*
int main(int argc, char **argv){
		
	unsigned char *hh;
	
	FILE *fp;
	
	uint32_t s32[4] = { 0x61616161, 0x61616161, 0x61616161, 0x61616161 };
	uint64_t s64[4] = { 0x6161616161616161, 0x6161616161616161, 0x6161616161616161, 0x6161616161616161 };
	//s32[0] = s32[1] = s32[2] = s32[3] = 0;
	
	fp = fopen("/Users/sa/Documents/M.S.I./TS/blake/10K.png", "r");
	
	unsigned char *image = (unsigned char *) malloc(10000 * sizeof(char)  + 1024);	
	if(!image){
		puts("MALLOC ERROR ABORT");
		exit(-1);
	}
	
	
	size_t read = fread(image, 1, 10000, fp);
	printf("Bytes lidos: %zu\n",read);
	
	if(read>=20485780){
		puts("message truncated");
		exit(-1);
	}
	puts("IMG 10KB!");
	hh = malloc(32);
	BLAKE(image, read, s32, 32, hh);
	int j;
	puts("BLAKE-256:");
	for( j=0; j<32; j++){
		(void)printf("%02X", hh[j]);
		if(!((j+1)%4)) printf(" ");
		if (((j+1) % 64) == 0) puts(""); 
	}
	Hash(256, image, read, hh);
	puts("\n--deles--");
	for( j=0; j<32; j++){
		(void)printf("%02X", hh[j]);
		if(!((j+1)%4)) printf(" ");
		if (((j+1) % 64) == 0) puts(""); 
	}
	puts("\n");
	
	hh = malloc(64);
	BLAKE(image,(unsigned )  read, s64, 64, hh);
	puts("BLAKE-512:");
	for( j=0; j<64; j++){
		(void)printf("%02X", hh[j]);
		if(!((j+1)%8)) printf(" ");
		if (((j+1) % 64) == 0) puts(""); 
	}
	Hash(512, image, read, hh);
	puts("--deles--");
	for( j=0; j<64; j++){
		(void)printf("%02X", hh[j]);
		if(!((j+1)%8)) printf(" ");
		if (((j+1) % 64) == 0) puts(""); 
	}
	puts("\n");
	
	fclose(fp);
	
	fp = fopen("/Users/sa/Documents/M.S.I./TS/blake/1MB.bmp", "r");
	
	read = fread(image, 1, 20485780, fp);
	
	puts("1MB!");
	hh = malloc(32);
	BLAKE(image, read, s32, 32, hh);
	puts("256:");
	for( j=0; j<32; j++){
		(void)printf("%02X", hh[j]);
		if(!((j+1)%4)) printf(" ");
		if (((j+1) % 64) == 0) puts(""); 
	}
	Hash(256, image, read, hh);
	puts("\n--deles--");
	for( j=0; j<32; j++){
		(void)printf("%02X", hh[j]);
		if(!((j+1)%4)) printf(" ");
		if (((j+1) % 64) == 0) puts(""); 
	}
	puts("\n");
	
	
	hh = malloc(64);
	BLAKE(image, read, s64, 64, hh);
	puts("512");
	for( j=0; j<64; j++){
		(void)printf("%02X", hh[j]);
		if(!((j+1)%8)) printf(" ");
		if (((j+1) % 64) == 0) puts(""); 
	}
	Hash(512, image, read, hh);
	puts("--deles--");
	for( j=0; j<64; j++){
		(void)printf("%02X", hh[j]);
		if(!((j+1)%8)) printf(" ");
		if (((j+1) % 64) == 0) puts(""); 
	}
	puts("\n");	
	
	fclose(fp);
	
	fp = fopen("/Users/sa/Documents/M.S.I./TS/blake/10MB.bmp", "r");
	
	read = fread(image, 1, 20485780, fp);
	
	if(read>=20485780){
		puts("message truncated");
		exit(-1);
	}
	
	puts("10MB!");
	hh = malloc(32);
	BLAKE(image, read, s32, 32, hh);
	puts("256:");
	for( j=0; j<32; j++){
		(void)printf("%02X", hh[j]);
		if(!((j+1)%4)) printf(" ");
		if (((j+1) % 64) == 0) puts(""); 
	}
	Hash(256, image, read, hh);
	puts("\n--deles--");
	for( j=0; j<32; j++){
		(void)printf("%02X", hh[j]);
		if(!((j+1)%4)) printf(" ");
		if (((j+1) % 64) == 0) puts(""); 
	}
	puts("\n");
	
	hh = malloc(64);
	BLAKE(image, read, s64, 64, hh);
	puts("512");
	for( j=0; j<64; j++){
		(void)printf("%02X", hh[j]);
		if(!((j+1)%8)) printf(" ");
		if (((j+1) % 64) == 0) puts(""); 
	}
	Hash(512, image, read, hh);
	puts("--deles--");
	for( j=0; j<64; j++){
		(void)printf("%02X", hh[j]);
		if(!((j+1)%8)) printf(" ");
		if (((j+1) % 64) == 0) puts(""); 
	}
	puts("\n");
	
	fclose(fp);

	return 0;
}
*/