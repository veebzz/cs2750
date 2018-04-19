/*Vibhav Chemarla
 * CS 2750 PA 6
 * 4/20/2018
 */

#include <stdio.h>
#include <stdlin.h>
#include <unistd.h>

int main (int argc, char *argv[]){
	pid_t child = 0;
	int i, n;

	if (argc != 2){
		fprintf(stderr, "Usage: %s processes \n", argv[0]);
		return 1;
	}
	n = atoi(argv[1]);
	for(i = 0; i < n; i ++)
		if((childpid = fork()) <= 0)
			break;
	
	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
		i, getpid(), getppid(), childpid);
	
	return 0;
}
