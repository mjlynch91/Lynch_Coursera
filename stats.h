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
 * @file stats.h
 * @brief header file for stats.c
 *
 * Program is meant to perform statistics on an array of data
 *
 * @author Joey Lynch
 * @date May 17, 2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief function that prints the statistics of an array including minimum, maximum,
 *	mean, and median.
 *
 * This function will take in the arguments of min, max, mean, and median and print
 *	them to the command line. The stats will be rounded down to the nearest integer.
 *
 * @param med the median of the data array that will be printed
 * @param mean the mean of the data array that will be printed
 * @param max the maximum of data array that will be printed
 * @param min the minimum of data array that will be printed
 * 
 * @return none
 */
void print_statistics(int med, int mean, int max, int min);



/**
 * @brief function that prints a data array of unsigned chars and it's length
 *
 *
 * @param data a pointer to the data array of unsigned char
 *
 * @return none
 */
void print_array(unsigned char* data, int length);



/**
 * @brief given an array of data and a length, returns the median value
 *
 *
 * @param data pointer to data array of unsigned char
 * @param length the length of the data array
 *
 * @return The median value of the array
 */
int find_median(unsigned char* data, int length);



/**
 * @brief given an array of daya and a length, returns the mean value
 *
 *
 * @param data pointer to data array of unsigned char
 * @param length the length of the data array
 *
 * @return The mean value of the array
 */
int find_mean(unsigned char* data, int length);



/**
 * @brief given an array of data and a length, returns the maximum
 *
 * @param data pointer to data array of unsigned char
 * @param length the length of the data array
 *
 * @return The maximum value of the array
 */
int find_max(unsigned char* data, int length);



/**
 * @brief given an array of data and a length, returns the minimum
 *
 * @param data pointer to data array of unsigned char
 * @param length the length of the data array
 *
 * @return The minimum value of the array
 */
int find_min(unsigned char* data, int length);



/**
 * @brief sorts array from largest to smallest
 *
 * given an array of data and a length, sorts the array from largest to
 * smallest. (the zeroeth element is the largest value and the last element
 * (n-1) is the smallest value.
 *
 * @param data pointer to data array of unsigned char
 * @param length the length of the data array
 *
 * @return none
 */
void sort(unsigned char* data, int length);



/**
 * @brief swaps the positions of two unsigned char elements of an array
 *
 *
 * @param p element 1
 * @param q element 2
 *
 * @return none
*/
void swap(unsigned char* p, unsigned char* q);


#endif /* __STATS_H__ */
