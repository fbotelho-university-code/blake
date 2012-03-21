#include <stdlib.h>

#include "blake.h"
#include "blake256.h"
#include "blake512.h"

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
