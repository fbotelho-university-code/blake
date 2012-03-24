#include <stdint.h>

unsigned char *blake512(unsigned char *, unsigned, unsigned char *, unsigned char *);
uint64_t pad512(unsigned char *, uint64_t, uint32_t *); 
void initH512(uint64_t *);
void init512(uint64_t *, uint64_t *, uint64_t *);
void g64(uint64_t *, uint64_t *, uint64_t *, uint64_t *, uint32_t, uint32_t, uint64_t *);
void rounds512(uint64_t *);
void finit512(uint64_t *, uint64_t *);
void compress64(uint64_t *, uint64_t *, uint64_t *, uint64_t *);
void dumpLen128(void *, uint64_t);

uint64_t state64[4][4];

/*
 initialization vectors 
 */
static const uint64_t IV512[8]={
	0x6A09E667F3BCC908ULL, 0xBB67AE8584CAA73BULL,
	0x3C6EF372FE94F82BULL, 0xA54FF53A5F1D36F1ULL,
	0x510E527FADE682D1ULL, 0x9B05688C2B3E6C1FULL,
	0x1F83D9ABFB41BD6BULL, 0x5BE0CD19137E2179ULL
};

/*
 16 constants
 */
static const uint64_t c512[16] = {
	0x243F6A8885A308D3ULL,0x13198A2E03707344ULL,
	0xA4093822299F31D0ULL,0x082EFA98EC4E6C89ULL,
	0x452821E638D01377ULL,0xBE5466CF34E90C6CULL,
	0xC0AC29B7C97C50DDULL,0x3F84D5B5B5470917ULL,
	0x9216D5D98979FB1BULL,0xD1310BA698DFB5ACULL,
	0x2FFD72DBD01ADFB7ULL,0xB8E1AFED6A267E96ULL,
	0xBA7C9045F12C7F99ULL,0x24A19947B3916CF7ULL,
	0x0801F2E2858EFC16ULL,0x636920D871574E69ULL
};