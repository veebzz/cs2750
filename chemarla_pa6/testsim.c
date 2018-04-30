/*testsim.c*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	int n;
	int sec;

	if(argc <=2)
	{
		fprintf(stderr, "Usage: %s sleep_time repeat_facor\n", argv[0]);
		exit(1);
	}

	scanf(argv[1], "%d", &sec);
	scanf(argv[2], "%d", &n);

	while(n-- > 0)
		sleep(sec);
	printf("Process ID = %d \n", getpid());
	return sec;
}
