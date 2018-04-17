/*Vibhav Chemarla
 * CS 2750 PA 5
 * 4/16/2018
 */

#include "ams.h"
#include "accStruct.h"
#include "withdrawl.h"

void withdrawl(Account *aptr){

	int input, count=0;
	double withdrawl;

	fptr= fopen("accounts.dat", "rb+");
	printf("Enter account number for withdrawl: ");

	scanf("%d", &input);
	for (int i = 0; i <51 ; i++){
		fread(&aptr[i], sizeof(Account), 1, fptr);
		if(aptr[i].accId == input){
			count++;

			printf("Account Number: %d/n", aptr[i].accId);
			printf("Account Owner:  %s %s %s", aptr[i].fName, aptr[i].mName, aptr[i].lName);
			printf("Account Balance: $%.2f\n",aptr[i].accBal);
			printf("Enter Withdrawl Amount: ");
			scanf("%f", &withdrawl);
			if(withdrawl <= aptr[i].accBal){
				aptr[i].accBal -= withdrawl;
				printf("Withdrawl subtracted");
			}
			else{
				printf("Insufficient funds in your account.\n");
				fclose(fptr);
				break;
			}
			printf("Account Balance: $%.2f", aptr[i].accBal);
			fseek(fptr, ftell(fptr) - sizeof(Account), SEEK_SET);
			fwrite(&aptr[i], sizeof(Account), 1,fptr);
			fclose(fptr);
			break;
		}
	}

	if(count == 0){
	printf("Account not found");
	fclose(fptr);
	}
	
}

