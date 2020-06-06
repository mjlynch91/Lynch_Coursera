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
 * @file main.c
 * @brief Main entry point to the C1M4 Assessment
 *
 * 
 * @author Alex Fosdick (Modified by Joey Lynch June 1 2020)
 * @date April 1 2017
 *
 */
#include "platform.h"
#include "data.h"
#include "stats.h"
#include "memory.h"
#include "course1.h"

#include <stdint.h>
#include <stdio.h>
// #include "memory.c"
// #include "data.c"
// #include "course1.c"
// #include "stats.c"




int main(void) {
	#ifdef COURSE1
		void course1(void);
	#endif
  return 0;
}

