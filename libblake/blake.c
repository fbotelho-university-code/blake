#include <stdlib.h>

#include "blake.h"
#include "blake256.h"
#include "blake512.h"

void BLAKE(unsigned char *data, unsigned len, unsigned char *salt, unsigned lenDigest, char *digest){
	
	switch (lenDigest) {
		case 32:
			digest = blake256(data, len, salt);
			break;
		case 64	:
			digest = blake512(data, len, salt);
			break;
		default:
			digest = NULL;
			break;
	}
	
	
}
