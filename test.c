#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"
#include "blake256.h"
#include "blake512.h"

int main(int argc, char **argv){
	
	int i;
	
	unsigned char in[1024];
	unsigned char out[32];
	unsigned char hash[32];
	unsigned char *hh = hash;
	
	FILE *fp;
	
	// Open file
	fp = fopen(argv[1], "r");
/*	
	// Tests for BLAKE-256
	for(i=0; i<200; i++){
		
		// Read input
		fread(in, 1, i+1, fp);
		
		// Read output
		fread(out, 1, 32, fp);
				
		// Hash
		hh = blake256(in, i+1);
		
		// Test
		convertNinja(hh, 32); 
		if(memcmp(out,hh,32)) printf("Error in test %d\n",i+1);
	}
*/
	
	// Tests for BLAKE-512
	for(i=0; i<1; i++){
		
		// Read input
		fread(in, 1, i+1, fp);
		convertNinja(in, i+1); 
		prettyPrinter(in,i+1, "in:");
		convertNinja(in, i+1); 
		// Read output
		fread(out, 1, 64, fp);
		
		prettyPrinter(out,64, "output:");
		
		// Hash
		hh = blake512(in, i+1);
		convertNinja(hh, 64); 
		prettyPrinter(hh,64, "hash:");
		
		// Test
		if(memcmp(out,hh,64)) printf("Error in test %d\n",i+1);
	}
	
	fclose(fp);
	return 0;
}

