#include <stdio.h>
#include <math.h>
#include <string.h>

int value(char);

long int decimalToBinary(int number){
	int result = 0, remainder, counter = 1;
	while(number != 0){
		remainder = number % 2;
		number /= 2;
		result += remainder * counter;
		counter *= 10;
	}
	return result;
}

int binaryToDecimal(long int number){
	int decimal = 0, counter = 0, remainder;
	while(number!=0){
		remainder = number % 10;
		number /= 10;
		decimal += remainder * pow(2, counter);
		counter++;
	}
	return decimal;
}

void decimalToBaseN(long int number, int base){
	char convertedNumber[16];
	long int startingNumber = number;
	int counter = 0;
	while(number!=0){
		int var = 0;
		var = number % base;
		if(var < 10){
			convertedNumber[counter] = var + 48;
			counter++;
		} else {
			convertedNumber[counter] = var + 55;
			counter++;
		}
		number /= base;
	}
	printf("%ld in %d base is ", startingNumber, base);
	for(int i = counter - 1; i >= 0; i--){
		printf("%c", convertedNumber[i]);
	}
	printf("\n");
}

int baseNToDecimal(char *str, int base){
	int len = strlen(str);
	int power = 1, num = 0;
	for(int i = len - 1; i >= 0; i--){
		if(value(str[i]) >= base){
			fprintf(stderr, "Invalid number");
			return -1;
		}

		num += value(str[i]) * power;
		power *= base;
	}
	return num;
}

int value(char c){
	if(c >= '0' && c <= '9'){
		int result = c - '0';	
		return result;
	} else { 
		int result = c - 'A' + 10;
		return result;
	}
}

int main(){
	// DECIMAL TO BINARY
	printf("98(10) in binary is %ld\n", decimalToBinary(98));
	printf("56(10) in binary is %ld\n", decimalToBinary(56));
	printf("31(10) in binary is %ld\n", decimalToBinary(31));
	// BINARY TO DECIMAL
	printf("10(2) in decimal is %d\n", binaryToDecimal(10));
	printf("11101(2) in decimal is %d\n", binaryToDecimal(11101));
	printf("1111(2) in decimal is %d\n", binaryToDecimal(1111));
	// DECIMAL TO HEX
	decimalToBaseN(48, 16);
	decimalToBaseN(156, 16);
	decimalToBaseN(321, 16);
	// HEX TO DECIMAL
	printf("100(16) in decimal is %d\n", baseNToDecimal("100", 16));
	printf("3E(16) in decimal is %d\n", baseNToDecimal("3E", 16));
	printf("1EA(16) in decimal is %d\n", baseNToDecimal("1EA", 16));
	//DECIMAL TO OCT
	decimalToBaseN(8, 8);
	decimalToBaseN(56, 8);
	decimalToBaseN(31, 8);
	// OCT TO DECIMAL
	printf("25(8) to decimal is %d\n", baseNToDecimal("25", 8));
	printf("10(8) to decimal is %d\n", baseNToDecimal("10", 8));
	printf("24(8) to decimal is %d\n", baseNToDecimal("24", 8));
	return 0;
}
