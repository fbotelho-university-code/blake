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
	unsigned char *message[1024];
	
	strncpy(message,argv[1],strlen(argv[1]));
	
	unsigned char *h = blake256(message, strlen(message));
	
	for(int i=0; i<32; i++){
		printf("%02X", h[i]);
	}
	
	/*

	FILE *fp=NULL;
	char message[MESSAGE_SIZE_MAX];
	size_t i=0;
	
	
    if (argc != 2)
	{
		(void)printf(stderr, "\nUSAGE: blake $(MESSAGE)\n");
		return(-1);
	}
	else
	{
		if (strlen(argv[1])>FILENAME_MAX)
		{
			return(-1);
		}
		else
		{
			fp = fopen(argv[1], "r");
			i = fread(message, 1, MESSAGE_SIZE_MAX, fp);
			
			if (i == MESSAGE_SIZE_MAX)
			{
				(void)printf(stderr, "\nYour message was truncated\n");
			}
			else
			{
				i = feof(fp);
				
				if (i!=1)
				{
					(void)printf(stderr, "\nCritical error reading the file: ABORT!\n");
				}
				else
				{
					(void)printf("%s",blake256(message));
				}
			}
		}
	}
	*/
	
    return 0;
}

