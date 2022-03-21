#include <stdio.h>

int rectangle(double a, double b, double* P, double* S){
    if (a <= 0 || b <= 0) return -1;
    *P = 2 * (a + b);
    *S = a * b;
    return 0;
}

int main(){
	double a, b, per, area;
    while(scanf("%lf %lf", &a, &b) != EOF){
        if (rectangle(a, b, &per, &area) == -1){
            fprintf(stderr, "Invalid sides!\n");
        }else {
            printf("P = %.2lf, S = %.2lf\n", per, area);
        }
    }
	return 0;
}
