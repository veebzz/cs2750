/* Vibhav Chemarla
 * cs 2750 PA 4
 * 04/01/2018
 */
#define _GNU_SOURCE
#include "input.h"

int input(int argc, char *argv[]){
	int given = 0;
	//Reminder: argc[0] is array, argc wil always be atleast 1
	for (int i = 1; i < argc; i++){
		if (isdigit(argv[i][0])){ 
			given += atoi(argv[i]); // add all numbers in passed parameter
		}	
	}
	return given; // return total 
}
