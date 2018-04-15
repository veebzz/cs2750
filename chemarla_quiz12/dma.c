#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]){

int i, n;
int *a;

printf("Enter size of elements, followed by the numbers seperated by spaces");
n = atoi(argv[1]);

a= (int*)malloc(n*sizeof(int));
for(i=0; i<n;i++){
	a[i] = argv[i+2];
}
free(n);
return 0;
}
