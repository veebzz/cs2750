/*Vibhav Chemarla
 * CS 2750 PA 5
 * 4/16/2018
 */

#include "accStruct.h"
#include "ams.h"
#include "addAccount.h"
#include "stdio.h"
#include "accStruct.h"

void addAccount(Account *aptr)
{
	int input;
	char fName[25],mName[25],lName[25];
	float accBal;
	//open file
	fptr = fopen("accounts.dat", "wb+");
	//fopen check
	if(fptr ==NULL){
		printf("Error opening accounts.dat");
		exit (1);
	}
	
	for (int i=0; i < 50; i++){
		//On the next empty struct element
		if(aptr[i].accId == 0){
			//Rewite struct as
			for(int j = 0; j < i; j++){
				fwrite(&aptr[j], sizeof(Account), 1,fptr);
			}
			//ask for user input
			printf("Enter an account number(6 digits): ");
			scanf("%d/n", &input);
			//Check to see if the account exists
			for(int j=0; j < i; j++){
				if(aptr[j].accId == input){
					printf("Account already registered!\n");
					exit(1);
				}
			}
			//invalid range check
			if(input < 100000 || input >= 999999){
				printf("Invalid account number format!");
				break;
			}
			// if within range take info
			else{
				//First name input
				aptr[i].accId= input;
				printf("\nFirst Name: ");
				scanf("%s", fName);
				strcpy(aptr[i].fName, fName);
				//Middle name input
				printf("\nMiddle Name: ");
				scanf("%s", mName);
				strcpy(aptr[i].mName, mName);
				//Last name input
				printf("\nLast Name: ");
				scanf("%s", lName);
				strcpy(aptr[i].lName, lName);
				//Account balance input
				printf("\nAccount Balance: ");
				scanf("%f", &accBal);
				aptr[i].accBal = accBal;
				//update
				fwrite(&aptr[i], sizeof(Account), 1, fptr);
				break;
			}
		}
		
	}
	fclose(fptr);
}

