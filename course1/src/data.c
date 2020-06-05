#include data.h

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
	if(data > 0)
		ptr[0] = 43; //43 is ascii for '+'
		str_length++;
	else if(data < 0)
		ptr[0] = 45; //45 is ascii for '-'
		str_length++;
		
	while(data != 0){
		remainder = data % base;
		printf("Remainder before conversion: %d\n", remainder);
		if(remainder < 10)
			remainer += 48; //48 is the ascii for '0'
		else if(remainder >= 10 && remainder <= 16)
			remainder += 87; //97 is ascii for 'a'. So add 87 to 10th digit to get 'a'
		data /= base;
		printf("Remainder after conversion %c or %d\n", remainder, remainder);
		ptr[str_length] = remainder;
		str_length++;
	};
	
	str_length++;
	ptr[str_length] = '\0';
	return(str_length);
};

//ASCII to Integer
int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base);

int main(){
	//Testing the itoa function
	int32_t value, base = 0;
	printf("Enter the decimal value you would like to convert: ");
	scanf("%d", &value);
	printf("\nEnter the base you would like to convert to: ");
	scanf("%d", &base);
	
	uint8_t ptr[MAX_LENGTH];
	uint8_t str_length = convert(value, ptr, base);
	printf("Your decimal value is: %d\nYour new value in base %d is ", value, base);
	int i = 0;
	for(i = str_length-1; i >= 0; i--){
	printf("%c", ptr[i]);
	}
	return 0;
}
