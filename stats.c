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
 * @file stats.c
 * @brief C program to compute basic stats of a data array
 *
 * The program defines a data array of unsigned chars of a given size, defined in the preprocessor.
 * The program uses functions to compute the mean, median, maximum, and minimum of the data in the array.
 * The is also a function to sort the data from smallest to largest. The program then prints the stats
 * to the standard output.
 *
 * @author Joey Lynch
 * @date May 17, 2020
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned char median = 51;
  unsigned char mean = 44;
  unsigned char min = 2;
  unsigned char max = 99;
  /* Statistics and Printing Functions Go Here */
	print_statistics(median, mean, max, min);
}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char med, unsigned char mean, unsigned char max, unsigned char min){
	printf("Median = %d\nMean = %d\nMax = %d\nMin = %d\n",med, mean, max, min);
};