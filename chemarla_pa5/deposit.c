/*Vibhav Chemarla
 * CS 2750 PA 5
 * 4/16/2018
 */

#include "ams.h"
#include "accStruct.h"
#include "deposit.h"


void deposit(Account *aptr){

	int input, count=0;
	double deposit;

	fptr= fopen("accounts.dat", "rb+");
	printf("Account Number for Deposit: ");

	scanf("%d", &input);
	for (int i = 0; i <51 ; i++){
		fread(&aptr[i], sizeof(Account), 1, fptr);
		if(aptr[i].accId == input){
			count++;

			printf("Account Number: %d/n", aptr[i].accId);
			printf("Account Owner:  %s %s %s", &aptr[i].fName, &aptr[i].mName, &aptr[i].lName);
			printf("Account Balance: $%.2f\n",aptr[i].accBal);
			printf("Enter Deposit Amount: ");

			scanf("%f", &deposit);
			aptr[i].accBal += deposit;
			printf("Deposit added");
			printf("Account Balance: $%.2f", aptr[i].accBal);
			fseek(fptr, ftell(fptr) - sizeof(Account), SEEK_SET);
			fwrite(&aptr[i], sizeof(Account), 1,fptr);
		}
	}

	if(count < 1){
		printf("Account not found");
	}
	fclose(fptr);
}
