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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick (Modified by Joey Lynch June 1 2020)
 * @date April 1 2017
 *
 */
#include <stddef.h>
#include <stdint.h>
 
#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves data from one location in memory to another location
 *
 *	The behavior of the function handles overlap of source and destination.
 *	Copy will occur with no data corruption.
 *
 * @param src Pointer to source location
 * @param dst Pointer to destination location
 * @param length Length of bytes to move 
 *
 * @return pointer to destination
 */
uint8_t* my_memmove(uint8_t* src, uint8_t* dst, size_t length);

/**
 * @brief Copies data from one location in memory to another location
 *
 *	The behavior is undefined if there is overlap of source and destination.
 *	Copy will still occur, but will likely corrupt data.
 *	
 * @param src Pointer to source location
 * @param dst Pointer to destination location
 * @param length Length of bytes to move 
 *
 * @return pointer to destination
 */
uint8_t* my_memcopy(uint8_t* src, uint8_t* dst, size_t length);

/**
 * @brief Sets all memory locations to a specific value
 *
 *	The behavior is undefined if there is overlap of source and destination.
 *	Copy will still occur, but will likely corrupt data.
 *	
 * @param src Pointer to source location
 * @param length Length of bytes to set to given value
 * @param value 8-bit unsigned integer to be stored in memory at all the specified locations
 *
 * @return pointer to source
 */ 
uint8_t* my_memset(uint8_t* src, size_t length, uint8_t value);
 
/**
 * @brief Sets a given amount of memory at a given location to zeros
 *
 *	
 * @param src Pointer to source location
 * @param length Length of bytes to set to zero
 *
 * @return pointer to source
 */ 
uint8_t* my_memzero(uint8_t* src, size_t length);

/**
 * @brief Reverses the order of all bytes from a starting location to a specified length
 *
 *	
 * @param src Pointer to source location
 * @param length Length of bytes until the end of block to be reversed
 *
 * @return pointer to source
 */ 
uint8_t* my_reverse(uint8_t* src, size_t length);

/**
 * @brief Reserve a certain number of words in dynamic memory
 *
 *	
 * @param length Length of bytes to be allocated
 *
 * @return pointer to memory if successful, or Null Pointer if not successful
 */
int32_t* reserve_words(size_t length);

/**
 * @brief Free dynamic memory allocation
 *
 *	
 * @param src Pointer to source of dynamic memory to be freed
 *
 * @return void
 */
void free_words(uint32_t* src); //I had to change the argument to type uint32_t* because that's how it's called in course1.c

#endif /* __MEMORY_H__ */
