#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

#define COUNT 10

int main(){
	srand(time(NULL));
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		pid_t pid = fork();
		sleep(1);
		srand(time(NULL));
		if(0 == pid){
			char random[COUNT];
			for(int j = 0; j < COUNT; j++){
				random[j] = 'a' + rand() % ('z' - 'a' + 1);
			}
			random[COUNT] = '\0';
			printf("%s\n", random);
			exit(0);
		}
	}
	for(int i = 0; i < n; i++) wait(NULL);
	return 0;
}
