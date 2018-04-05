/*Vibhav Chemarla
 * cs 2750 PA 4
 * 04/01/2018
 */
#define _GNU_SOURCE
#include "subInput.h"

void subInput(int argc, char *argv[]){


	for (int i = 1; i < argc; i++) {
		//skip iteration if the string is digit
		if (isdigit(argv[i][0])){
			continue;
		}	
		else{
		//display substring text
			for (int j = 1; j < argc; j++){
				if ((strcmp(argv[i], argv[j]) !=  0) && (strcasestr(argv[j] , argv[i]) != NULL))
				printf("%s is a substring of %s\n", argv[i],argv[j]);
			}
		}
	}
}
