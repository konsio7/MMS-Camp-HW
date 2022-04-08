#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv){
	char buffer[BUFSIZ];
	int files[2];
	int count;
	if(argc<3) return -1;
	files[0] = open(argv[1], O_RDONLY);
	if(files[0] == -1){
	 	perror("error");      
		return -1;
	}
	files[1] = open(argv[2], O_WRONLY | O_CREAT | S_IRUSR | S_IWUSR);
	if(files[1] == -1){
		perror("error");
		close(files[0]);       
		return -1;
	}
	while(count = read(files[0], buffer, sizeof(buffer))){
		write(files[1], buffer, count);
	}
	close(files[0]);
	close(files[1]);
	return 0;
}
