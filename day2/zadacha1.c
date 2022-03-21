#include <stdio.h>
#include <stdlib.h>
#define EPS = 0.0001

double max(double x, double y){
	if(x > y) return x;
	else return y;
}

int main(){
	double a, b, c;
	printf("Enter 3 numbers:\n");
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("The largest number is %.2lf\n", max(a, max(b, c)));
	return 0;
}
