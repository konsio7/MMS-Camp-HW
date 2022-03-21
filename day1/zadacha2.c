#include <stdio.h>
#include <math.h>

int main(){
	// A
	double radius, height, length, volume;
	printf("Enter the radius and height of a cyllinder:\n");
	scanf("%lf %lf", &radius, &height);
	volume = M_PI * pow(radius, 2) * height;
	printf("Radius is %.2lf\n", volume);
	// B
	printf("Enter radius, height and length: \n");
	scanf("%lf %lf %lf", &radius, &height, &length);
	double area = pow(cos(radius - height / radius), -1) * pow(radius, 2) - (radius - height) * sqrt(2*radius*height - pow(height, 2));
	volume = area * length;
	printf("Radius is %.2lf\n", volume);
	return 0;
}
