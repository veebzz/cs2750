/*Vibhav Chemarla
 * CS 2750 PA 5
 * 4/16/2018
 */

#include "ams.h"
#include "accStruct.h"
#include "withdrawl.h"

void withdrawl(Account *aptr){

	int input;
	float withdrawl;
	//open file
	fptr= fopen("accounts.dat", "rb+");
	//fopen check
	if(fptr==NULL){
		printf("Error opening accounts.dat\n");
                exit (1);
   	    }
	//ask user for account number   
	printf("Enter account number for withdrawl: \n");
	scanf("%d", &input);

	for (int i = 0; i < 50 ; i++){
		fread(&aptr[i], sizeof(Account), 1, fptr);
		//if account number matches
		if(aptr[i].accId == input){
			//display Account info
			printf("Account Number: %d\n", aptr[i].accId);
			printf("Account Owner:  %s %s %s\n", aptr[i].fName, aptr[i].mName, aptr[i].lName);
			printf("Account Balance: $%.2f\n",aptr[i].accBal);
			//ask user for withdrawal amount
			printf("Enter Withdrawal Amount: \n");
			scanf("%f", &withdrawl);
			//check to see if  account has funds for withdrawal
			if(aptr[i].accBal >= withdrawl){
				aptr[i].accBal -= withdrawl;
				printf("Withdrawal subtracted\n");
				//display new amount
				printf("Account Balance: $%.2f\n", aptr[i].accBal);
				//update dat file
				fseek(fptr,ftell(fptr)-sizeof(Account),SEEK_SET);
				fwrite(&aptr[i],sizeof(Account),1,fptr);
				fclose(fptr);
				break;
			}
			else{
				printf("Insufficient funds in your account.\n");
				fclose(fptr);
				break;
			}
		}
		//if inputted account number is not found in struct
		else if(aptr[i].accId != input){
			printf("Account number not found!\n");
			break;
	
		}
	}
}	


