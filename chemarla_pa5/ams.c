/*Vibhav Chemarla
 * CS 2750 PA 5
 * 4/16/2018
 */

#include "ams.h"
#include "accStruct.h"


int main()
{
	Account accounts[SIZE];
	int menu = 0, choice;
	Account *aptr = accounts;
	
	int makeAcc();
	
	//Menu for problem2
	while (menu >= 0)
	     {
	    	printf("\n--------------------------------------------------------");
		printf("\n0.\tExit\n1.\tDeposit\n2.\tWithdrawl\n3.\tAdd Account\n");
		printf("4.\tRemove Account\n5.\tBalance Inquiry\n6.\tView Accounts\n");
		printf("Enter Option Choice: ");
		scanf("%d", &choice);
		if (choice == 0){
			menu = -1;
			printf("Program Terminated\n");
		}
		else if (choice == 1){
			deposit(aptr);
		}
		else if (choice == 2){
			withdrawl(aptr);
		}
		else if (choice == 3){
			addAccount(aptr);
		}
		else if (choice == 4){
			remAccount(aptr);
		}
		else if (choice == 5){
			balInquiry(aptr);
		}
		else if (choice == 6){
			viewAcc(aptr);
		}
		else{
			printf("An invalid choice has been entered.\nRestarting menu.\n");
		}
	}
		return(0);
}



//intialize first 7 into accounts struct
int makeAcc(){
//fName,mName,lName,accId,accBal
	Account accounts[7] = {
			{"Vibhav","R","Chemarla",123456,9999999.00},
			{"Jeff","P","Bezos", 199318, 119.40},
			{"Bill", "H","Gates", 199462, 91.0},
			{"Warren", "E", "Buffet", 193087, 84.80},
			{"Bernard","JE","Arnault", 194969, 83.40},					     {"Mark", "The Zuck", "Zuckerberg", 198433, 66.00},
			{"Amancio", "O","Ortega", 193682,69.40},
	};
	//open file
	fptr= fopen("accounts.dat", "ab");
	
	for(int i =0; i <8; i++){
		fwrite(&accounts[i], sizeof(Account), 1, fptr);				     }
	//close file		
	fclose(fptr);
											     return 0;
								
}
