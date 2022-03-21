#include <stdio.h>
#include <math.h>

int triangle(double,double,double,double*,double*);

int main(){
	double a, b, c, per, area;
	while(scanf("%lf %lf %lf", &a, &b, &c) != EOF){
		if(triangle(a, b, c, &per, &area) == -1) printf("Invalid triangle\n");
		else printf("P = %.2lf, S = %.2lf\n", per, area);
	}
	return 0;
}

int triangle(double a, double b, double c, double* perimeter, double* area){
	if(a <= 0 || b <= 0 || c <= 0 || a+b < c || a+c < b || b+c < a)
		return -1;
	*perimeter = a + b + c;
	double halfP = *perimeter / 2;
	*area = sqrt(halfP*(halfP-a)*(halfP-b)*(halfP-c));
	return 0;
}

