/*Vibhav Chemarla
 * CS 2750 PA 6
 * 4/20/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char *argv[]){
	pid_t childpid = 0;
	pid_t wpid;
	int pr_limit;
	int pr_count= 0;
	int status = 0;
	char fArr[15];
	int i = 0;
	//check if user entered two arguments
	if (argc != 2){
		fprintf(stderr, "Usage: %s processes \n", argv[0]);
		return 1;
	}

	//pr_limit maximum number of children allowed to execute at a time
	pr_limit = atoi(argv[1]);


	// if count is limit wait for  child to finish
	for(i = 1; i < pr_limit; i ++){
		if((childpid = fork()) <= 0)
			break;
	
	//while((wpid = wait(&status)) > 0);
		if(childpid = waitpid(-1, &status, WNOHANG)> 0){
			printf("Child %d terminated\n", childpid);
			pr_count--;
		}
	}
	//fgets command line up to MAX_BUF char
	fgets(fArr, 15, stdin);

	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",i, getpid(), getppid(), childpid);
	
	return 0;
}
