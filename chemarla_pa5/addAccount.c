/*Vibhav Chemarla
 * CS 2750 PA 5
 * 4/16/2018
 */

#include "accStruct.h"
#include "ams.h"
#include "addAccount.h"
#include "stdio.h"

void addAccount(Account *aptr)
{
	int input;
	char fName,mName,lName;
	float accBal;
	FILE *fptr;

	fptr = fopen("accounts.dat", "wb");
	if(fptr ==NULL){
		printf("Error opening accounts.dat");
		exit (1);
	}
	for (int i=0; i < 51; i++){
		
		if(aptr[i].accId == 0){
			for(int j = 0; j < i; j++){
				fwrite(&aptr[j], sizeof(Account), 1,fptr);
			}
			printf("Enter an account number(6 digits): ");
			scanf("%d/n", &input);

			for(int j=0; j < i; j++){
				if(input == aptr[j].accId){
					printf("Account already registered!\n");
			
				}
			}

			if(input < 100000 || input >= 999999){
				printf("Invalid account number format!");
				break;
			}
			else{
				//First name input
				aptr[i].accId= input;
				printf("\nFirst Name: ");
				sscanf("%s", &fName);
				strcpy(aptr[i].fName, fName);
				//Middle name input
				printf("\nMiddle Name: ");
				sscanf("%s", &mName);
				strcpy(aptr[i].mName, mName);
				//Last name input
				printf("\nLast Name: ");
				sscanf("%s", &lName);
				strcpy(aptr[i].lName, lName);
				//Account balance input
				printf("\nAccount Name: ");
				scanf("%f", &accBal);
				aptr[i].accBal = accBal;
				
				fwrite(&aptr[i], sizeof(Account), 1, fptr);
				break;
			}
		}
	}
	fclose(fptr);
}
