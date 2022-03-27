#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void swapg(void* a, void* b, size_t size){
	uint8_t temp[size];
	memmove(temp, a, size);
	memmove(a, b, size);
	memmove(b, temp, size);
}

void bubbleSort(void* arr, size_t n, size_t size, int(*comp)(const void*,const void*)){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < (n-i-1)*size; j += size){
			if(comp(arr+j, arr+j+size) < 0) swapg(arr+j, arr+j+size, size);
		}
	}
}

void (*getSorting(char* fname))(void*,size_t,size_t,int(*)(const void*,const void*)){
	if(strcmp(fname, "qsort") == 0) return qsort;
	else if(strcmp(fname, "bubble Sort") == 0) return bubbleSort;
}

int main(){

	return 0;
}
