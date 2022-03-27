#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define COUNT 10

typedef struct{
	char name[150];
	char author[100];
	int pages;
	double price;
} book;

double dRand(double min, double max){
	double num = (double)rand() / RAND_MAX;
	return min + num * (max - min);
}

int lsearch(const double key, book* arr, size_t n){
	for(int i = 0; i < n; i++){
		// 20.5043543534 20.50 00.0043565
		if((fabs(arr[i].price - key)) < 0.001) return i;
	}
	return -1;
}

void printInfo(book* b, int n){
	for(int i = 0; i < n; i++){
		printf("Book %s by %s with %d pages costs %.2lf BGN\n", b[i].name, b[i].author, b[i].pages, b[i].price);
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
		books[i].price = dRand(1.00, 50.00);
	}
	int result = lsearch(20.50, books, COUNT);
	if(result == -1) printf("No such book!\n");
	else printf("%s\n", books[result].name);

	printInfo(books, COUNT);
	return 0;
}
