// #include "data.h"
#include <stdio.h>

#define MAX_LENGTH 100
/***********************************************************
 Function Definitions
***********************************************************/
//Integer to ASCII
uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base){
	
	//Step 1: Assuming data is a decimal value, convert it to proper base
	//Step 2: Split the digits up into a list of char
	//Step 3: Change each char in the list to an ASCII value
	//Step 4: Store the ASCII characters in the proper place in memory
	
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
		printf("Remainder before conversion: %d\n", remainder);
		if(remainder < 10)
			remainder += 48; //48 is the ascii for '0'
		else if(remainder >= 10 && remainder <= 16)
			remainder += 87; //97 is ascii for 'a'. So add 87 to 10th digit to get 'a'
		data /= base;
		printf("Remainder after conversion %c or %d\n", remainder, remainder);
		*(ptr+str_length) = remainder;
		str_length++;
	};
	*(ptr+str_length) = sign;
	str_length++;
	*(ptr+str_length) = '\0';
	return(str_length);
};

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
	uint8_t sign; 
	for(i = 0; i < digits; i++){
		current_digit = (int32_t)*(ptr + (digits-1-i)); //48 is the ascii value of decimal 0
		if(current_digit == 48 || current_digit == 49 || current_digit == 50 || current_digit == 51 || current_digit == 52 || current_digit == 53 || current_digit ==54 || current_digit == 55 || current_digit == 56)
			current_digit-=48;
		else if(current_digit == 97 || current_digit == 98 || current_digit == 99 || current_digit == 100 || current_digit == 101 || current_digit ==102)
			current_digit-=87; //97 is the ascii of 'a'
		else if(current_digit == 43) //43 is ascii for '+'
			sign = 43;
		else if(current_digit == 45) //45 is ascii for '-'
			sign = 45;
		else
			printf("You entered in an incorrect digit!");
		printf("\ncurrent digit = %d\n",current_digit);
		result += current_digit*power(base, i);
		if(sign == 45)
			result *= -1;
		printf("current result = %d",result);
	}
	return(result);
}



int32_t find_newline(uint8_t* list, int32_t length){
	int32_t i = 0;
	uint8_t current_char;
	for(i = 0; i < length; i++){
		current_char = *(list + i);
		if(current_char == '\n')
			return i;
		printf("Current character: %c\n", current_char);
	};
}

int main(){
	
	//Testing the itoa function
	// int32_t value, base = 0;
	// printf("Enter the decimal value you would like to convert: ");
	// scanf("%d", &value);
	// printf("\nEnter the base you would like to convert to: ");
	// scanf("%d", &base);
	
	// uint8_t ptr[MAX_LENGTH];
	// uint8_t str_length = my_itoa(value, ptr, base);
	// printf("Your decimal value is: %d\nYour new value in base %d is ", value, base);
	// int32_t i = 0;
	// for(i = str_length-1; i >= 0; i--){
	// printf("%c", *(ptr+i));
	// }
	
	//Testing the atoi function
	uint8_t value[MAX_LENGTH];
	uint32_t base;
	printf("Enter the value you would like to convert to decimal (use 'a' for eleventh digits, 'b' for twelth digits, etc for bases larger than decimal): ");
	fgets(value, MAX_LENGTH, stdin);
	int32_t num_digits = find_newline(value, MAX_LENGTH);
	printf("Length of the value you entered is = %d", num_digits);
	
	printf("\nEnter the base of your value: ");
	scanf("%d", &base);
	// printf("\nEnter the number of digits in your value: ");
	// scanf("%d", &num_digits);
	
	int32_t result = my_atoi(value, num_digits, base);
	printf("\n%d\n", result);
	printf("Your value in base %d is: %s\nYour new value in decimal is %d", base, value, result);
	// int32_t i = 0;
	// for(i = number_of_digits-1; i >= 0; i--){
	// printf("(%d)", result[i]);
	// }
	
	return 0;
}
