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
	
	//check if user entered two arguments
	if (argc != 2){
		fprintf(stderr, "Usage: %s processes \n", argv[0]);
		return 1;
	}

	//pr_limit maximum number of children allowed to execute at a time
	pr_limit = atoi(argv[1]);
	//display testing.data commands to see if fgets works
	//while(fgets(fArr, MAX_BUF -1, stdin)){
	//	printf("%s\n", fArr);
//	}
	//main loop	
	while(fgets(fArr, MAX_BUF -1, stdin )!=NULL)
	{
		//if prrcount = prlimit wat for child to finish an ddecrement pr_count
		
		// fork a child
		if((childpid = fork())==0){
			printf("%s" , fArr);
			system(fArr);
			return 0;

		}
		else{
			pr_count++;
		}
		//throw erro if fork fails
	//	if(childpid < 0){
	//		perror("child has failed to fork");
	//		return 1;
	//	}
		if(pr_count >= pr_limit){
		
			if((childpid = waitpid(-1, &status, WNOHANG))> 0){
                 //     	   printf("Child %d terminated. Exit code: \n", childpid);
			   pr_count--;
              		}
			else{
				printf("Child process exit fail");
				return 1;
			}
		}
	}
	printf("end file");
		 
//	fprintf(stderr, "process ID:%ld parent ID:%ld child ID:%ld\n", getpid(), getppid(), childpid);
	
	return 0;
}
