/**
 * @file data.h
 * @brief Abstraction of memory read and write operations
 *
 * Header file for data.c
 *
 * @author Joey Lynch
 * @date June 1 2020
 *
 */
 
/**
 * @brief Converts a signed 32-bit integer into an ASCII string
 *
 *	A Null terminator is placed at the end of the converted c-string.
 *	Supports bases 2 to 16.
 *
 * @param data The 32-bit integer to be converted to an ASCII string
 * @param ptr Pointer to the location to store ASCII string
 * @param base Integer value of the base you wish to convert to (2 for binary, 10 for decimal, 16 for hexidecimal)
 *
 * @return length of the converted data
 */
uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base);

/**
 * @brief Converts ASCII string into an integer type
 *
 *	Supports bases 2 to 16.
 *	Can handle signed data.
 *
 * @param ptr Pointer to the ASCII character string to be converted to an unsigned integer
 * @param digits The number of digits in the character set
 * @param base Integer value of the base you wish to convert to (2 for binary, 10 for decimal, 16 for hexidecimal)
 *
 * @return converted 32-bit signed integer
 */
int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base);