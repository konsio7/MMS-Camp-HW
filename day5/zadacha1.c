#include <stdio.h>

int main(){
	double operand1, operand2;
	char operator;
	while(scanf("%lf %c %lf", &operand1, &operator, &operand2) != EOF){
		if(operator == '+') printf("%.2lf", operand1 + operand2);
		else if(operator == '-') printf("%.2lf", operand1 - operand2);
		else if(operator == '/') printf("%.2lf", operand1 / operand2);
		else if(operator == '.') printf("%.2lf", operand1 * operand2);
		else fprintf(stderr, "Invalid data");
	}
	return 0;
}
