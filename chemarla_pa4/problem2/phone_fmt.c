/*Vibhav Chemarla
 * cs 2750 PA 4
 * 04/03/2018
 */
#include "phone_fmt.h"

void phone_fmt(int argc, char *argv[]){
	
	int n=0;
	int m;
	int length=0;

	for (int i = 1; i < argc; i++){
		
		//store number of arguments passed into length
		length = strlen(argv[i]);
		//Dynamic memory allocation
		int *array = (int*) malloc(length * sizeof(int));

		m = 0;
		for (int j = 0; j < length; j++){

			if(isdigit(argv[i][j])){

				n = argv[i][j] - '0';
				array[m] = n;
				m++;
			}
		}
		//number count check
		if (m < 10){
			printf("Error!Less than 10 digits entered!\n");
			exit(-1);
		}
		//display phone in (xxx)xxx-xxx format
		printf("(%d%d%d) %d%d%d-%d%d%d%d\n", array[0], array[1],array[2],array[3], array[4], array[5],array[6], array[7],array[8], array[9]);
		//release dynamic allocation
		free(array);
	}
}
