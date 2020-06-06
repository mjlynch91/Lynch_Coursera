#include "data.h"
#include <stdint.h>
#include "platform.h"

#define MAX_LENGTH 256 //a 32-bit value in binary needs 32 ASCII characters to represent it and a char is 8-bits therefore MAX_LENGTH is (8*32)=256 

uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base);
int32_t power(int32_t base, int32_t exponent);
int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base);
uint8_t find_newline(uint8_t* list, int32_t length);


/***********************************************************
 Function Definitions
***********************************************************/
//Integer to ASCII
uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base){

	uint32_t str_length = 0;
	uint8_t remainder;
	uint8_t sign;
	if(data > 0){
		sign = 43; //43 is ascii for '+'
		str_length++;}
	else if(data < 0){
			sign = 45; //45 is ascii for '-'
			data *= -1; //convert the data to it's positive
			str_length++;}
	while(data != 0){
		remainder = data % base;
		if(remainder < 10)
			remainder += 48; //48 is the ascii for '0'
		else if(remainder >= 10 && remainder <= 16)
			remainder += 87; //97 is ascii for 'a'. So add 87 to 10th digit to get 'a'
		data /= base;
		*(ptr+str_length) = remainder;
		str_length++;
	};
	*(ptr+str_length) = sign;
	str_length++;
	*(ptr+str_length) = '\0';
	return(str_length);
};

//Used in the ASCII to integer function
int32_t power(int32_t base, int32_t exponent){
	int32_t i = 0;
	int32_t result = 1;
	for(i = 0; i < exponent; i++){
		result *= base;
	};
	return result;
}

//ASCII to Integer
int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base){
	int32_t i = 0;
	int32_t current_digit = 0;
	int32_t result = 0;
	// uint8_t sign; 
	for(i = 0; i < digits; i++){
		current_digit = (int32_t)*(ptr + (digits-1-i)); //48 is the ascii value of decimal 0
		if(current_digit == 48 || current_digit == 49 || current_digit == 50 || current_digit == 51 || current_digit == 52 || current_digit == 53 || current_digit ==54 || current_digit == 55 || current_digit == 56)
			current_digit-=48;
		else if(current_digit == 97 || current_digit == 98 || current_digit == 99 || current_digit == 100 || current_digit == 101 || current_digit ==102)
			current_digit-=87; //97 is the ascii of 'a'
		else if(current_digit == 65 || current_digit == 66 || current_digit == 67 || current_digit == 68 || current_digit == 69 || current_digit ==70)
			current_digit-=55; //65 is the ascii of 'A'
		else
			PRINTF("You entered in an incorrent digit! This result won't make any sense!\n");
			//something to handle unknown input characters
		result += current_digit*power(base, i);
		PRINTF("current digit = %d\n", current_digit);
		PRINTF("current result = %d\n", result);
	}
	return(result);
}

//Used in the ASCII to integer function
uint8_t find_newline(uint8_t* list, int32_t length){
	uint8_t i = 0;
	uint8_t current_char;
	for(i = 0; i < length; i++){
		current_char = *(list + i);
		if(current_char == '\n')
			break;
		PRINTF("Current character: %c\n", current_char);
	};
	return i;
}