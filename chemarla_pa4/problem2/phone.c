/*Vibhav Chemarla
 * cs 2750 PA 4
 * 04/03/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "phone_fmt.h"

int main(int argc, char *argv[]){
	//check to see if anything was passed
	if(!argv[1]){
		printf("Error! no Arguments passed!\n");
		return 1;
	}
	//Phone format function
	phone_fmt(argc , argv);

	return 0;
}
