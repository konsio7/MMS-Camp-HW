#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define COUNT 10

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int* arr, size_t n){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

int binarySearch(int* arr, size_t n, int key){
	int startIndex = 0;
	int endIndex = n - 1;
	while(startIndex <= endIndex){
		int temp = startIndex + ((endIndex - startIndex) / 2);
		if(arr[temp] == key) return temp;
		if(arr[temp] < key) startIndex = temp + 1;
		else endIndex = temp - 1;
	}
	return -1;
}

int main(){
	srand(time(NULL));
	int arr[COUNT];
	int element;
	printf("Enter a number [0-9]:\n");
	scanf("%d", &element);
	printf("Unsorted array:\n");
	for(int i = 0; i < COUNT; i++){
		arr[i] = rand() % 10;
		printf("%d ", arr[i]);
	}
	printf("\n");
	bubbleSort(arr, COUNT);
	printf("Sorted array:\n");
	for(int i = 0; i < COUNT; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("Element %d:\n", element);
	int result = binarySearch(arr, COUNT, element);
	if(result != -1) printf("%d\n", result);
	else printf("No such number\n");
	return 0;
}
