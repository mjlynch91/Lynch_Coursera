/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick (Modified by Joey Lynch June 1 2020)
 * @date April 1 2017
 *
 */
#include "memory.h"

#define MEM_SIZE 100000

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t* my_memmove(uint8_t* src, uint8_t* dst, size_t length){
	if(src - dst < length)
		PRINTF(" Your destination had to be moved due to overlap of source and destination!");
		//dst = new SAFE dst location
	int i = 0;
	for(i = 0; i < length; i++){
		*(dst+i) = *(src+i);
	}
	return dst;
}

uint8_t* my_memcopy(uint8_t* src, uint8_t* dst, size_t length){
	if(src - dst < length)
		PRINTF(" Your destination overlaps with your source so your data may now be corrupted!");
	int i = 0;
	for(i = 0; i < length; i++){
		*(dst+i) = *(src+i);
	}
	return dst;
}

uint8_t* my_memset(uint8_t* src, size_t length, uint8_t value){
	int i = 0;
	for(i = 0; i < length; i++){
		*(src+i) = value;
	};
	return src;
}

uint8_t* my_memzero(uint8_t* src, size_t length){
	int i = 0;
	for(i = 0; i < length; i++){
		*(src+i) = 0;
	};
	return src;
}

void swap(int* a,int* b)
{
	int temp = *a;
	*a = *b;
	*b =temp;
}

uint8_t* my_reverse(uint8_t* src, size_t length){
	int i;
	uint8_t temp = 0;
	for(i = 0; i < length; i++){
		temp = *(src + i);
		*(src + i) = *(src + length - (i+1));
		*(src + length - (i+1)) = temp;
	}
	return src;
}

int32_t* reserve_words(size_t length){
	static int32_t nextAddress = BASE_ADDRESS;
	void *ptr = (void*)nextAddress;
	nextAddress += size;
	return ptr;
}

void free_words(int32_t* src){
	return;
}