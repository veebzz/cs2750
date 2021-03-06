/*Vibhav Chemarla
 * CS 2750 PA 5
 * 4/16/2018
 */

#include "accStruct.h"
#include "ams.h"
#include "balInquiry.h"

void balInquiry(Account *aptr){

	int input, count =0;
	//ask user for input
	printf("Enter account number: ");
	scanf("%d", &input);
	//open file
	fptr = fopen("accounts.dat", "rb+");
	//fopen check
	if(fptr==NULL){
		 printf("Error opening accounts.dat");
		 exit (1);
	}


	for(int i = 0; i < 51; i++){
		fread(&aptr[i], sizeof(Account), 1, fptr);
		//if account is found
		if(aptr[i].accId == input){
			count++;
			//display account info
			printf("Account found\n");
			printf("Account Owner: %s %s %s\n", aptr[i].fName, aptr[i].mName, aptr[i].lName);
			printf("Balance: $%.2f\n", aptr[i].accBal);
			fclose(fptr);
		}
	}
	//since all the accounts are 0 it will display accounts not found
	if (input == 0){
		printf("Account not found");
		fclose(fptr);
	}
}
