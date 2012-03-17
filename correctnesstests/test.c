#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libblake/defs.h"
#include "../libblake/blake.h"

#include "../libblake/blake256.h"
#include "../libblake/blake512.h"

int main(int argc, char **argv){
	
	int i;
	
	unsigned char in[1024];
	unsigned char out32[32];
	unsigned char out64[64];
	unsigned char *hh;
	
	FILE *fp;

	uint32_t s32[4] = { 0x61616161, 0x61616161, 0x61616161, 0x61616161 };
	uint64_t s64[4] = { 0x6161616161616161, 0x6161616161616161, 0x6161616161616161, 0x6161616161616161 };
	
	// Open BLAKE-256 test file
	fp = fopen("correctnesstests/test_file256", "r");

	// Tests for BLAKE-256
	for(i=0; i<600; i++){
		
		// Read input
		fread(in, 1, i+1, fp);
		//prettyPrinter32(in, i+1, "in:\n");

		// Read output
		fread(out32, 1, 32, fp);
		//prettyPrinter32(out32, 32, "out:\n");
		
		// Hash
		//BLAKE(in, i+1, s32, 32, hh);
		hh = blake256(in, i+1, s32);
		
		// Test
		convertNinja32(hh, 32); 
		//prettyPrinter32(hh, 32, "hash:\n");
		if(memcmp(out32,hh,32)) printf("BLAKE-256: Error in test %d\n",i+1);
	}

	fclose(fp);
	
	// Open BLAKE-512 test file
	fp = fopen("correctnesstests/test_file512", "r");
	
	// Tests for BLAKE-512
	for(i=0; i<600; i++){
		
		// Read input
		fread(in, 1, i+1, fp);
		//prettyPrinter64(in, i+1, "in:\n");
		
		// Read output
		fread(out64, 1, 64, fp);
		//prettyPrinter64(out64, 64, "out:\n");
				
		// Hash
		//BLAKE(in, i+1, s64, 64, hh);
		hh = blake512(in, i+1, s64);
		
		// Test
		convertNinja64(hh, 64);
		//prettyPrinter64(hh, 64, "hash:\n");
		if(memcmp(out64,hh,64)) printf("BLAKE-512: Error in test %d\n",i+1);
	}
	
	fclose(fp);
	return 0;
}

