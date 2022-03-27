#include <stdio.h>
#include <stdint.h>

void swapBytes(uint16_t* word){
	word = (word << 8) | (word >> 8);
}

int main(){

	return 0;
}
