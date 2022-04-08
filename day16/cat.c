#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
extern int errno;

int main(int argc, char **argv){
	char buffer[BUFSIZ];
	size_t bytes;
	int fd;
	if(argc > 1){
		for(int i = 1; i < argc; i++){
			int fd = open(argv[i], O_RDONLY);
			if(fd<0){
				perror("r1");
				return -1;
			}
			int nread;
			while((nread = read(fd, buffer, BUFSIZ))){
				write(STDOUT_FILENO, buffer, nread);
			}
			close(fd);
		}
	} else 
		while(bytes = read(STDIN_FILENO, buffer, BUFSIZ)) 
			write(STDOUT_FILENO, buffer, bytes);
	return 0;
}
