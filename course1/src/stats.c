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
 * @date May 17, 2020 (Modified June 1 2020)
 *
 */



#include <stdio.h>
#include <limits.h>
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
	int median;
	int mean;
	int min;
	int max;
	
  /* Statistics and Printing Functions Go Here */
	printf("Your inital array (before sorting) is:\n");
	print_array(test, SIZE);
  
	median = find_median(test, SIZE);
	mean = find_mean(test, SIZE);
	min = find_min(test, SIZE);
	max = find_max(test, SIZE);
	
	printf("Your array after sorting is:\n");
	sort(test, SIZE);
	print_array(test, SIZE);
	print_statistics(median, mean, max, min);
	
}

/* Add other Implementation File Code Here */

void print_statistics(int med, int mean, int max, int min){
	printf("Median = %d\nMean = %d\nMax = %d\nMin = %d\n",med, mean, max, min);
};

//If the user gives the flag -DVERBOSE then print_array will print the array. If the user doesn't give that flag print_array does nothing.
//Compile time switch
#ifdef VERBOSE
	void print_array(unsigned char* data, int length){
		int i;
		printf("The length of your array is %d\nHere are the elements of your array:\n",length);
		for(i = 0; i < length; i++){
			printf("%d\n",data[i]);
		};
	};
#else
	void print_array(unsigned char* data, int length){};
#endif

void swap(unsigned char* p, unsigned char* q){
	unsigned char t = *p;
	*p = *q;
	*q = t;
};

void sort(unsigned char* data, int length){
	int i,j;
	for(i = 0; i < length-1; i++){
		for(j = 0; j < length-i-1; j++){
			if(data[j] < data[j+1]){
				swap(&data[j],&data[j+1]);
			};
		};
	};
};

int find_median(unsigned char* data, int length){
	int n = (length+1)/2 - 1;
	sort(data, length); //sort data in case it isn't already
	int median = data[n];
	return median;
};

int find_mean(unsigned char* data, int length){
	int i;
	int sum = 0;
	for(i = 0; i < length-1; i++){
		sum += data[i];
	};
	int mean = sum/length;
	return mean;
};

int find_max(unsigned char* data, int length){
	int i = 0;
	int temp = 0;
	for(i = 0; i < length -1; i++){
		if(data[i] > temp){
			temp = data[i];
		};
	};
	return temp;
};

int find_min(unsigned char* data, int length){
	int i = 0;
	int temp = INT_MAX;
	for(i = 0; i < length -1; i++){
		if(data[i] < temp){
			temp = data[i];
		};
	};
	return temp;
};