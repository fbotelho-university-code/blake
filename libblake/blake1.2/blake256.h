#include <stdint.h>

unsigned char *blake256(unsigned char *, unsigned, unsigned char *, unsigned char *);

uint32_t state32[16];

/*
	initialization vectors 
 */


/*
	16 constants
 */
static const uint32_t c256[16] = {
    0x243F6A88, 0x85A308D3,
    0x13198A2E, 0x03707344,
    0xA4093822, 0x299F31D0,
    0x082EFA98, 0xEC4E6C89,
    0x452821E6, 0x38D01377,
    0xBE5466CF, 0x34E90C6C,
    0xC0AC29B7, 0xC97C50DD,
    0x3F84D5B5, 0xB5470917 
};
