/*Vibhav Chemarla
 * CS 2750 PA 5
 * 4/16/2018
 */

#include "ams.h"
#include "accStruct.h"
#include "deposit.h"


void deposit(Account *aptr){

	int input;
	float deposit;

	fptr= fopen("accounts.dat", "rb+");
	//fopen check
	if(fptr == NULL){
		printf("Error opening accounts.dat");
		exit(1);
	}
	//ask user for account number
	printf("Account Number for Deposit: ");
	scanf("%d", &input);

	for (int i = 0; i <51 ; i++){
		fread(&aptr[i], sizeof(Account), 1, fptr);
		//if input of user matches any in the struct
		if(aptr[i].accId == input){
			//display user info
			printf("Account Number: %d\n", aptr[i].accId);
			printf("Account Owner:  %s %s %s\n", aptr[i].fName, aptr[i].mName, aptr[i].lName);
			printf("Account Balance: $%.2f\n",aptr[i].accBal);
			//ask user for a deposit amount
			printf("Enter Deposit Amount: \n");
			scanf("%f", &deposit);
			//add it deposit to accBal
			aptr[i].accBal += deposit;
			//display new accBal
			printf("Deposit added\n");
			printf("Account Balance: $%.2f\n", aptr[i].accBal);
			//find place in dat file and update it
			fseek(fptr, ftell(fptr)-sizeof(Account), SEEK_SET);
			fwrite(&aptr[i], sizeof(Account), 1,fptr);
		}
		//if input doesnt match any accId in Account struct
		else if(aptr[i].accId != input){
			printf("Account number not found!\n");
			//go back to menu
			break;
		}
	}
	//close file
	fclose(fptr);
}
