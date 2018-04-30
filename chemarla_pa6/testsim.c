/*testsim.c*/
#include <stdio.h>

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
		printf("[Repeat: %d] Process: %d is sleeping for %d seconds\n",i,getpid(),sec);
		sleep(sec);
	}

	printf("Child Process: %d terminated\n",getpid());
	
	//printf("Child Process ID = %d \n", getpid());
	return sec;
}
