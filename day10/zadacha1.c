#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef union {
	float f;
	uint32_t byte;
} ufloat;

int main(){
	ufloat input;
	scanf("%lf", &input.f);
	printf("%lu\n", input.byte);
	return 0;
}
