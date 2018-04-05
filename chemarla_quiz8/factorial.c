#include<stdlib.h>
#include<stdio.h>
int main(int argc, char * argv[]) {
   	int i, sum = 0;
	long int fact=1;	 
	if (argc != 2) {
	printf("Missing Parameter! Example: ./a.out 5\n");
	exit(1);
	}
	if(atoi(argv[1])==0||atoi(argv[1])==1)
	fact=1;
	else
	for (i = 2; i <=atoi(argv[1]); i--)
	fact=fact*i;
	printf("Factorial of %s is %ld\n", argv[1],fact);
	return 0;																		 }
