/*Vibhav Chemarla
 * CS 2750 PA 6
 * 4/20/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_BUF 50


int main (int argc, char *argv[]){
	pid_t childpid = 0;
	pid_t wpid;
	int pr_limit;
	int pr_count= 0;
	int status = 0;
	char fArr[MAX_BUF];
	int i;
	//check if user entered two arguments
	if (argc != 2){
		fprintf(stderr, "Usage: %s processes \n", argv[0]);
		return 1;
	}

	//pr_limit maximum number of children allowed to execute at a time
	pr_limit = atoi(argv[1]);

	//main loop	
	while(fgets(fArr, MAX_BUF -1, stdin) !=NULL)
	{
		//if prrcount = prlimit wat for child to finish an ddecrement pr_count
		if(pr_count == pr_limit)
		{
			wait(NULL);
			pr_count--;
		}
		if((childpid = fork())){
			system(fArr);
		}
		if(childpid = waitpid(-1, &status, WNOHANG)> 0){
                //         printf("Child %d terminated\n", childpid);
	                   pr_count--;
              	}		  
	}

		 
	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",i, getpid(), getppid(), childpid);
	
	return 0;
}
