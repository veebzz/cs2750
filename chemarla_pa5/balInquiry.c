/*Vibhav Chemarla
 * CS 2750 PA 5
 * 4/16/2018
 */

#include "accStruct.h"
#include "ams.h"
#include "balInquiry.h"

void balInquiry(Account *aptr){

	int input, count =0;

	printf("Enter account number: ");
	scanf("%d", &input);

	fptr = fopen("accounts.dat", "rb+");
	for(int i = 0; i < 51; i++){
		fread(&aptr[i], sizeof(Account), 1, fptr);
		if(aptr[i].accId == input){
			count++;

			printf("Account found\n");
			printf("Account Owner: %s %s %s\n", aptr[i].fName, aptr[i].mName, aptr[i].lName);
			printf("Balance: $%.2f\n", aptr[i].accBal);
			fclose(fptr);
		}
	}

	if (input == 0){
		printf("Account not found");
		fclose(fptr);
		}
}
