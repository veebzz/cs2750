/*Vibhav Chemarla
 * CS2750 PA 6
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
	int pr_limit;
	int pr_count= 0;
	int status = 0;
	char fArr[MAX_BUF];
	int pid = 0;
	int total = 0;
	
	//check if user entered two arguments
	if (argc != 2){
		fprintf(stderr, "Usage: %s processes \n", argv[0]);
		return 1;
	}

	//pr_limit maximum number of children allowed to execute at a time
	pr_limit = atoi(argv[1]);

	//while(fgets(fArr, MAX_BUF-1, stdin) ! = NULL){
	//	printf("%s", fArr);
	//}

	//main loop	
	while(fgets(fArr, MAX_BUF -1, stdin) !=NULL)
	{
		//Child Creation
		if((childpid = fork()) == 0){
           		printf("child:%d started\n", getpid());
			//printf("%s", fArr);
			system(fArr);
	   		exit(EXIT_SUCCESS);// assigns exit code to 0
		}
		else
		{
		    total++;		
		    pr_count++;
		}
		
		//wait for process slot to open up if process count hits limit
		if (pr_count >= pr_limit) 
		{
        	    do 
		    {     
               		pid = waitpid(-1, &status, WNOHANG); 
                	if (pid > 0) {
                	pr_count--;
                	}	
            	    } 
		    while(pid == 0);

		}
	}
    //wait for all to finsih
    do 
    {     
        pid = waitpid(-1, &status, WNOHANG); 
        if (pid > 0)
	{
		pr_count--;
		//print out child termination with Exit code of 0 because we use exit(EXIT__SUCCESS) above
        	printf("\nChild Terminated %d, with exit code: %d\n", pid,WEXITSTATUS(status));    
	}
	// 0 == no status change while waiting or if there more children ->wait
    } while(pid == 0 || pr_count > 0);
	// total childrenforked
    printf("Total count: %d\n", total);
	return 0;
}
