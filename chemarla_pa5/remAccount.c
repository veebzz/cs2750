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
	//fopen check
	if(fptr==NULL){
	 	 printf("Error opening accounts.dat");
		 exit (1);
	}
	//User input for account deletion
	printf("Enter the account number to delete: \n");
	scanf("%d", &input);

	if(input < 100000 || input > 999999){
		//Rewrites struct if inputted account is not found 
		for (int i = 0; i < 50; i++){
			fwrite( &aptr[i], sizeof(Account),1, fptr);
		}
		printf("Account not found.\n");
		exit (0);
	}

	for(int i = 0; i <50; i++){
		//Rewrites struct except the inputed account
		if(aptr[i].accId != input){
			fwrite(&aptr[i], sizeof(Account), 1,fptr);
		}
	}
		fclose(fptr);
}
