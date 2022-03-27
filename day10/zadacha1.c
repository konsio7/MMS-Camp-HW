#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef union {
	float f;
	uint32_t byte;
} ufloat;

void printFloatBits(float f){
	ufloat fl1;
	fl1.f = f;
	uint32_t mask = 1 << 31;
	do{
		if(mask == 0x40000000 || mask == 0x400000) putchar (' ');
		putchar(fl1.byte & mask ? '1' : '0');
	} while (mask >>=1);
}

int main(){
	float input = 3.1415926f;
	printFloatBits(input);
	printf("\n");
	return 0;
}
