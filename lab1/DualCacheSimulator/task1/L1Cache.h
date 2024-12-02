#ifndef SIMPLECACHE_H
#define SIMPLECACHE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "Cache.h"

#define L1_NUM_LINES L1_SIZE/BLOCK_SIZE

void resetTime();

uint32_t getTime();

/****************  RAM memory (byte addressable) ***************/
void accessDRAM(uint32_t, uint8_t *, uint32_t);

/*********************** Cache *************************/

void initCache();
void accessL1(uint32_t, uint8_t *, uint32_t);

typedef struct CacheLine {
  uint8_t Valid;
  uint8_t Dirty;
  uint32_t Tag;
} CacheLine;

typedef struct Cache {
  uint32_t init;
  CacheLine lines[L1_NUM_LINES];  // The Cache object now has several lines
} Cache;

/*********************** Interfaces *************************/

void read(uint32_t, uint8_t *);

void write(uint32_t, uint8_t *);

#endif
