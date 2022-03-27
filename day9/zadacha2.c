#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 10

int indexes[COUNT] = { 0 };

int func(int* arr, size_t size, int index, int counter){
	indexes[index]++;
	for(int i = 0; i < COUNT; i++){
		if(indexes[i] >= 2) return counter + 1;
	}
	int sum = 0;
	int num = arr[index];
	while(num != 0){
		sum += num % 10;
		num /= 10;
	}
	if((sum % 2) == 0) index += 3;
	else index -= 2;

	if(!(index >= size || index < 0)){
			counter++;
	       		func(arr, size, index, counter);
	}
	else return counter;
}

int main(){
	srand(time(NULL));
	int arr[COUNT] = { 5, 23, 77, 123, 681, 9, 772, 16 };
	/*for(int i = 0; i < COUNT; i++){
		arr[i] = (rand() % 1000) + 1;
		printf("%d ", arr[i]);
	}
	printf("\n");*/
	printf("%d\n", func(arr, COUNT, 4, 0));

	return 0;
}
