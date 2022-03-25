#include <stdio.h>

#define PI 3.1415926

double power(double number, int exponent){
	if(exponent < 0){
		if(number == 0) return -1;
		return 1 / (number * power(number, (-exponent) - 1));
	} else if(exponent == 0) return 1;
	else if(exponent == 1) return number;
	
	return number * power(number, exponent - 1);
}

double factoriel(int n){
	return n <= 0 ? 1 : n * factoriel(n - 1);
}

double my_sin(int degree){
	double radian, sin;
	degree %= 360;
	radian = degree * PI / 180;
	for(int i = 0; i < 7; i++){
		sin += power(-1, i) * power(radian, 2 * i + 1) / factoriel(2 * i + 1);
	}
	return sin;
}

int main(){
	int degree;
	printf("Enter degrees:\n");
	scanf("%d", &degree);
	printf("Sin(%d) = %.2lf\n", degree, my_sin(degree));
	return 0;
}
