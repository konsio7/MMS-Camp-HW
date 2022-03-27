#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 10

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* arr, int low, int high){
	int pivot = arr[high];
	int smallerElement = low - 1;
	for(int i = low; i < high; i++){
		if(arr[i] <= pivot){
			smallerElement++;
			swap(&arr[smallerElement], &arr[i]);
		}
	}
	swap(&arr[smallerElement+1], &arr[high]);
	return (smallerElement+1);
}

void quickSort(int* arr, int low, int high){
	if(low < high){
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot-1);
		quickSort(arr, pivot+1, high);
	}
}

int main(){
	srand(time(NULL));
	int arr[COUNT];
	printf("Unsorted array:\n");
	for(int i = 0; i < COUNT; i++){
		arr[i] = (rand() % 100) + 1;
		printf("%d ", arr[i]);
	}
	printf("\n");
	quickSort(arr, 0, COUNT-1);
	printf("Sorted array:\n");
	for(int i = 0; i < COUNT; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
