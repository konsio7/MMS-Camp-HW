#include <stdio.h>

unsigned sumArrayDigits(const int* arr, size_t n){
	int sum = 0;
	int digit, number;
	for(int i = 0; i < n; i++){
		number = *(arr+i);
		while(number > 0){
			digit = number % 10;
			sum += digit;
			number /= 10;
		}	
	}
	return sum;
}

int main(){
	int arr[] = {12,34,5,70};
	printf("Sum is %lu\n", sumArrayDigits(arr, 4));
	return 0;
}
