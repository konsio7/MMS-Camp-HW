#include <stdio.h>

double squareRoot(int number){
	double result = number / 2;
	int x = 0;
	while(result != x){
		x = result;
		result = (number / x + x) / 2;
	}
	return (double)result;

}

int main(){
	int num;
	printf("Enter a number:\n");
	scanf("%d", &num);
	printf("Square root of %d is %.2lf\n", num, squareRoot(num));
	return 0;
}
