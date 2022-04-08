#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char **argv){
	int fd[2];
	int numbers[argc-1];
	for(int i = 0; i < argc - 1; i ++){
		numbers[i] = atoi(argv[i+1]);
	}
	if(-1 == pipe(fd)) return -1;
	int sum1 = 0, sum2 = 0;
	pid_t pid = fork();
	if(-1 == pid) return -1;
	if(0 == pid){
		close(fd[0]);
		for(int i = 0; i < (argc - 1) / 2; i++){
			sum1 += numbers[i];
		}
		write(fd[1], &sum1, sizeof(sum1));
		close(fd[1]);
		//printf("Child sum is %d\n", sum1);
	} else {
		close(fd[1]);
		for(int i = (argc - 1) / 2; i < argc - 1; i++){
			sum2 += numbers[i];
		}
		int sumChild;
		read(fd[0], &sumChild, sizeof(sumChild));
		close(fd[0]);
		printf("Parent sum is %d\n", sum2);
		printf("Child sum is %d\n", sumChild);
		printf("Total sum is %d\n", sum2 + sumChild);
	}
	for(int i = 0; i < argc - 1; i++) wait(NULL);
	return 0;
}
