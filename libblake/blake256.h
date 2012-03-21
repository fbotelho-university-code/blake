#include <stdint.h>

unsigned char *blake256(unsigned char *, unsigned, unsigned char *, unsigned char *);
uint64_t pad256(unsigned char *, uint64_t, uint32_t *); 
void initH256(uint32_t *);
void init256(uint32_t *, uint32_t *, uint32_t *);
void g32(uint32_t *, uint32_t *, uint32_t *, uint32_t *, uint32_t, uint32_t, uint32_t *);
void rounds256(uint32_t *);
void finit256(uint32_t *, uint32_t *);
void compress(uint32_t *, uint32_t *, uint32_t *, uint32_t *);

uint32_t state32[4][4];

/*
	initialization vectors 
 */

static const uint32_t IV256[8]={
	0x6A09E667, 0xBB67AE85,
	0x3C6EF372, 0xA54FF53A,
	0x510E527F, 0x9B05688C,
	0x1F83D9AB, 0x5BE0CD19
};

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