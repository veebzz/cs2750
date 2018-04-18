/* Vibhav Chemarla
 * CS 2750 PA 5
 * 4/16/2018
 */

#include "accStruct.h"
#include "ams.h"
#include "ctype.h"

void viewAcc(Account *aptr){
	//open file
	fptr = fopen("accounts.dat", "rb");
	//fopen Check
	if(fptr==NULL){
		  printf("Error opening accounts.dat");
	  	  exit (1);
	 }
	for (int i = 0; i < 51; i++){
		fread(&aptr[i], sizeof(Account), 1, fptr);
		//range check
		if((aptr[0].accId < 100000) || (aptr[0].accId > 999999)){
			printf("Accounts not found. \n");
			fclose(fptr);
			break;
		}
		//display accounts that are not empty
		else if(aptr[i].accId != 0) {
			printf("********************************\n");
			printf("Account Number: %d \n", aptr[i].accId);
			printf("Account Owner: %s %s %s\n", aptr[i].fName, aptr[i].mName,aptr[i].lName);
			printf("Account Balance: $%.2f\n", aptr[i].accBal);
		}
		else{
		//close file
			fclose(fptr);
			break;
		}
	}
}

