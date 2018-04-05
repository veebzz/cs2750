/* Vibhav Chemarla
 * cs 2750 PA 4
 * 04/01/2018
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "subInput.h"


int main (int argc, char *argv[]){
	//argument pass check
	if(!argv[1]){
		printf("Error! No arguments passed!\n");
		return 1;
	}
	//display input
	printf("Sum of Intergers Passed: %d\n", input(argc , argv));
	//substring function 
	subInput (argc , argv);

	return 0;
}
