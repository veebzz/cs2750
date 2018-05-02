/*testsim.c*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n;
	int sec;

	if(argc <=2)
	{
		fprintf(stderr, "Usage: %s sleep_time repeat_facor\n", argv[0]);
		exit(1);
	}

	sscanf(argv[1], "%d", &sec);
	sscanf(argv[2], "%d", &n);
	
	for(int i = n; i > 0; i--){
		printf("Process %d [Repeat: %d]  sleeping for %d seconds\n",getpid(),i,sec);
		sleep(sec);
	}

	//printf("Child Process: %d terminated\n",getpid());
	
	
	return sec;
}
