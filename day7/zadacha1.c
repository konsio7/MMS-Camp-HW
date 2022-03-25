#include <stdio.h>

int secondMax(const int* arr, size_t n, int* secondMax){
	int temp, sameElements = 1;
	for(int i = 0; i < n - 1; i++) if(arr[i] != arr[i + 1]) sameElements = 0;

	if(n == 1){
		printf("Array size is 1!");
		return -1;
	} else if(sameElements){
		printf("All elements of the array are equal!\n");
		return -1;
	}

	int sortedArr[n];
	for(int i = 0; i < n; i++) sortedArr[i] = arr[i];

	for(int i = 0; i < n - 1; i++){
		if(*(sortedArr + i) < *(sortedArr + i + 1)){
			temp = *(arr + i);
			*(sortedArr + i) = *(sortedArr + i + 1);
			*(sortedArr+i+1) = temp;
		}
	}
	*secondMax = arr[n-2];
	return sortedArr[n-2];
}

int main(){
	int sm;
	int arr[] = {12, 34, 5, 70, 46};
	printf("%d\n", secondMax(arr, 5, &sm));
	return 0;
}
