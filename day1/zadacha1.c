#include <stdio.h>
#include <math.h>

int main(){
	// A
	double weight, height, bmi;
	printf("Enter your weight:\n");
	scanf("%lf", &weight);
	printf("Enter your height:\n");
	scanf("%lf", &height);
	bmi = weight / pow(height, 2);
	printf("Your BMI is %.2lf\n", bmi);
	// B
	double bmiNew;
	bmiNew = 1.3 * mass / pow(height, 2.5);
	printf("Your BMI according to Nick Trefethen is %.2lf", bmiNew);
	return 0;
}
