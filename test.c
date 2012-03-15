//
//  test.c
//  blake
//
//  Created by José Manuel Sá Lopes on 3/12/12.
//  Copyright (c) 2012 MSI@FCUL. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"
#include "blake256.h"



int main(int argc, char **argv){
	
	int i,j;
	
	unsigned char in[1024];
	unsigned char out[32];
	unsigned char hash[32];
	unsigned char *hh = hash;
	
	FILE *fp;
	
	// Open file
	fp = fopen(argv[1], "r");
	
	// Tests
	for(i=0; i<200; i++){
		
		// Read input
		fread(in, 1, i+1, fp);
		convertNinja(in, i+1); 
		prettyPrinter(in,i+1, "in:");
		convertNinja(in, i+1); 
		// Read output
		fread(out, 1, 32, fp);
		
		prettyPrinter(out,32, "output:");
		
		// Hash
		hh = blake256(in, i+1);
		convertNinja(hh, 32); 
		prettyPrinter(hh,32, "hash:");
		
		// Test
		if(memcmp(out,hh,32)) printf("Error in test %d\n",i+1);
	}

	fclose(fp);
	return 0;
}

