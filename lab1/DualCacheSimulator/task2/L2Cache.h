#ifndef SIMPLECACHE_H
#define SIMPLECACHE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "Cache.h"

#define L1_NUM_LINES L1_SIZE/BLOCK_SIZE
#define L2_NUM_LINES L2_SIZE/BLOCK_SIZE

void resetTime();

uint32_t getTime();

/****************  RAM memory (byte addressable) ***************/
void accessDRAM(uint32_t, uint8_t *, uint32_t);

/*********************** Cache *************************/

void initCache();
void accessL1(uint32_t, uint8_t *, uint32_t);
void accessL2(uint32_t, uint8_t *, uint32_t);

uint8_t is_L2_dirty(uint32_t address);
uint8_t is_L1_dirty(uint32_t address);

typedef struct CacheLine {
  uint8_t Valid;
  uint8_t Dirty;
  uint32_t Tag;
} CacheLine;

typedef struct { 
  uint32_t init;
  CacheLine L1[L1_NUM_LINES];
  CacheLine L2[L2_NUM_LINES];   
} Cache;

/*********************** Interfaces *************************/

void read(uint32_t, uint8_t *);

void write(uint32_t, uint8_t *);

#endif