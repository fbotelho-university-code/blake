// Include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Include local libraries
#include "defs.h"
#include "blake256.h"	

#define MESSAGE_SIZE_MAX 5242880


int main (int argc, const char * argv[])
{
	FILE *fp=NULL;
	unsigned char message[MESSAGE_SIZE_MAX];
	unsigned i=0;
	
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
				
				prettyPrinter(h, 64, "\nHash:\n");
			}
		}
	}
	
    return 0;
}



