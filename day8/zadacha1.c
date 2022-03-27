#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

#define COUNT 10

typedef struct{
	char name[150];
	char author[100];
	int pages;
	double price;
} book;

int compareName(const void* bk1, const void* bk2){
	book* b1 = (book*)bk1;
	book* b2 = (book*)bk2;
	return strcmp(b2->name, b1->name);
}

int compareAuthor(const void* bk1, const void* bk2){
	book* b1 = (book*)bk1;
	book* b2 = (book*)bk2;
	return strcmp(b1->author, b2->author);
}

int comparePages(const void* bk1, const void* bk2){
	book* b1 = (book*)bk1;
	book* b2 = (book*)bk2;
	int bk1p = b1->pages;
	int bk2p = b2->pages;
	if(bk1p >= bk2p) return 1;
	else return -1;
}

int comparePrice(const void* bk1, const void* bk2){
	book* b1 = (book*)bk1;
	book* b2 = (book*)bk2;
	double bk1price = b1->price;
	double bk2price = b2->price;
	if((bk1price - bk2price) > 0.001) return 1;
	else return -1;
}

double dRand(double min, double max){
	double num = (double)rand() / RAND_MAX;
	return min + num * (max - min);
}

void swapg(void* a, void* b, size_t size){
	uint8_t temp[size];
	memmove(temp, a, size);
	memmove(a, b, size);
	memmove(b, temp, size);
}

void bubbleSort(void* arr, size_t n, size_t size, int (*comp)(const void*, const void*)){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < (n-i-1) * size; j+= size){
			if(comp(arr+j, arr+j+size) < 0){
				swapg(arr+j, arr+j+size, size);
			}
		}
	}
}

void printInfo(book* b, int n){
	for(int i = 0; i < n; i++){
		printf("Book %s ", b[i].name);
		printf("by %s ", b[i].author);
		printf("with %d pages ", b[i].pages);
		printf("costs %.2lf BGN\n", b[i].price);
	}
}

int main(){
	srand(time(NULL));
	const char bookNames[][150] = { "Oceans of Polaris", "The Heart of the Forsaken", "The Face of the Empire", "The Dark Corpse", "Peas in a Pod", "Temptation of the Knight", "Spear and the Shadow", "Mists of Venus", "The Way of the Wicked", "When We Were Wallflowers", "Kill the Shadow", "Steel Angel", "Eye of the Tiger", "Shield of Crows", "Leather Dreams", "Trials of Fire", "The Butcher in the Picture", "Mystery of the Voiceless Visitor", "The Burden of Nine", "Druid's End"};
	const char authorNames[][100] = { "Ellise Meyer", "Orion Hastings", "Kennedy Merrill", "Caine Sloan", "Mylo Pope", "Jim Dalby", "Sol Steele", "Mariah Sparks", "Donovan Wiley", "Riccardo Ali" };
	book books[COUNT];
	for(int i = 0; i < COUNT; i++){
		strcpy(books[i].name, bookNames[rand() % 20]);
		strcpy(books[i].author, authorNames[rand() % 10]);
		books[i].pages = (rand() % 2001) + 4;
		books[i].price = dRand(1.00, 1000.00);
	}
	printf("----------BOOKS SORTED BY NAME----------\n");
	bubbleSort(books, COUNT, sizeof(book), compareName);
	printInfo(books, COUNT);
	printf("----------BOOKS SORTEDY BY AUTHOR NAME (REVERSED)----------\n");
	bubbleSort(books, COUNT, sizeof(book), compareAuthor);
	printInfo(books, COUNT);
	printf("----------BOOKS SORTED BY PAGES----------\n");
	bubbleSort(books, COUNT, sizeof(book), comparePages);
	printInfo(books, COUNT);
	printf("----------BOOKS SORTED BY PRICE----------\n");
	bubbleSort(books, COUNT, sizeof(book), comparePrice);
	printInfo(books, COUNT);
	return 0;
}
