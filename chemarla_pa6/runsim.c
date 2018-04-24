/*Vibhav Chemarla
 * CS 2750 PA 6
 * 4/20/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main (int argc, char *argv[]){
	pid_t childpid = 0;
	int pr_limit;
	int pr_count;

	//check if user entered two arguments
	if (argc != 2){
		fprintf(stderr, "Usage: %s processes \n", argv[0]);
		return 1;
	}

	//pr_limit maximum number of children allowed to execute at a time
	pr_limit = atoi(argv[1]);
	pr_count = 0;
	
	//use fgets to open up to MAX BUFFER ?? 
	for(i = 0; i < n; i ++)
		if((childpid = fork()) <= 0)
			break;
	
	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",i, getpid(), getppid(), childpid);
	
	return 0;
}
