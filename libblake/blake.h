#ifndef BLAKE_defs_h
#define BLAKE_defs_h

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void convert_bytes(unsigned char *, uint32_t);
void convertNinja32(unsigned char *, uint32_t);
void convertNinja64(unsigned char *, uint32_t);
void prettyPrinter32(unsigned char *, uint32_t, char *); 
void prettyPrinter64(unsigned char *, uint32_t, char *); 
void dumpLen(void *, uint64_t);
void BLAKE(unsigned char *, unsigned, unsigned char *, unsigned, char *);
#define U8TO32_BE(p) \
  (((uint32_t)((p)[0]) << 24) | \
   ((uint32_t)((p)[1]) << 16) | \
   ((uint32_t)((p)[2]) <<  8) | \
   ((uint32_t)((p)[3])      ))

#define U8TO64_BE(p) \
  (((uint64_t)U8TO32_BE(p) << 32) | (uint64_t)U8TO32_BE((p) + 4))

#endif


