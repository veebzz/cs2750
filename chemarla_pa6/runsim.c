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
		//Child Creation
		if((childpid = fork()) == 0){
           		printf("child:%d started\n", getpid());
			system(fArr);
	//   		printf("end child ID:%ld, Parent: %ld\n", getpid(), getppid());
	   		exit(0);
		}
		else
		{
		    pr_count++;
		}
		
		if (pr_count >= pr_limit) 
		{
		//wait for one
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
	//wait for all
    do 
    {     
        pid = waitpid(-1, &status, WNOHANG); 
        if (pid > 0)
	{
		pr_count--;
        	printf("child exited %d\n", pid);    
	}
	// 0 == no status change while waiting or if there more children ->wait
    } while(pid == 0 || pr_count > 0);

    printf("done parent %d\n", getpid());
	return 0;
}
