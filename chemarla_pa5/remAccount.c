/*Vibhav Chemarla
 * CS 2750 PA 5
 * 4/16/2018
 */

#include "accStruct.h"
#include "ams.h"
#include "remAccount.h"
void remAccount(Account *aptr){

	int input;

	fptr= fopen("accounts.dat", "wb+");
	if(fptr==NULL){
	 	 printf("Error opening accounts.dat");
		 exit (1);
	}

	printf("Enter the account number to delete: \n");
	scanf("%d", &input);

	if(input < 100000 || input > 999999){

		for (int i = 0; i < 51; i++){
			fwrite( &aptr[i], sizeof(Account),1, fptr);
		}
		printf("Account not found.\n");
		return 0;
	}

	for(int i = 0; i <51; i++){
		if(input != aptr[i].accId){
			fwrite(&aptr[i], sizeof(Account), 1,fptr);
		}
	}
		fclose(fptr);
}
