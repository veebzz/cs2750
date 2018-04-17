/* Vibhav Chemarla
 * CS 2750 PA 5
 * 4/16/2018
 */

#include "accStruct.h"
#include "ams.h"

void viewAcc(Account *aptr){

	fptr = fopen("accounts.dat", "rb+");
	for (int i = 0; i < 51; i++){
		fread(&aptr[i], sizeof(Account), 1, fptr);

		if(aptr[0].accId < 100000 || aptr[0].accId > 999999){
			printf("Account not found. \n");
			fclose(fptr);
			break;
		}
		else if(aptr[i].accId >= 100000 || aptr[i].accId <= 999999){
			printf("*******************\n");
			printf("Account Number: %d \n", aptr[i].accId);
			printf("Account Owner: %s %s %s\n", aptr[i].fName, aptr[i].mName,aptr[i].lName);
			printf("Account Balance: $%.2f\n", aptr[i].accBal);
		}
		else{
			fclose(fptr);
			break;
		}
	}
}

