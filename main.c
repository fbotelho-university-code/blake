//
//  main.c
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
#include "defs.h"
#include "blake.h"	

int main (int argc, const char * argv[])
{
	FILE *fp=NULL;
	unsigned char message[MESSAGE_SIZE_MAX];
	size_t i=0;
	
	unsigned char m[8];
	for (i=0; i<8; i++) {
		m[i]=0x00;
	}
	
	unsigned char *h = blake256(m, 8);
	
	puts("\nHash:");
	for( i=0; i<64; i++){
		(void)printf("%02X", h[i]);
		if(!((i+1)%4)) printf(" ");
	}
	puts("\n");
	
	return 0;
	
    if (argc != 2)
	{
		(void)printf("\nUSAGE: blake $(MESSAGE)\n");
		return(-1);
	}
	else
	{
		if (strlen(argv[1])>FILENAME_MAX)
		{
			(void)printf("\nFilename invalid!\n");
			return(-1);
		}
		else
		{
			fp = fopen(argv[1], "r");
			i = fread(message, 1, MESSAGE_SIZE_MAX, fp);
			if (i == MESSAGE_SIZE_MAX)
			{
				printf("\nYour message was truncated\n");
			}
			
			i = feof(fp);
			
			if (i!=1)
			{
				printf("\nCritical error reading the file: ABORT!\n");
				exit(-99);
			}
			else
			{
				unsigned char *h = blake256(message, i);
				
				puts("\nHash:");
				for( i=0; i<32; i++){
					(void)printf("%02X", h[i]);
					if(!((i+1)%4)) printf(" ");
				}
				puts("\n");
			}
		}
	}
	
    return 0;
}

