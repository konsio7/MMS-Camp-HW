#include <stdio.h>

int main(){
	int bit, newBit;
	for(int i = 0; i < 3; i++){
		printf("Enter 1 or 0:\n");
		scanf("%d", &bit);
		printf("%d\n", 1 ^ bit);
	}
	return 0;
}
