/*Vibhav Chemarla
 * CS 2750 PA 5
 * 4/16/2018
 */

#include "accStruct.h"
#include "ams.h"

//7 default accounts 

int main(){
//fName,mName,lName,accId,accBal
	Account accounts[7] = {
		{"Vibhav","R","Chemarla",123456,9999999.00},
		{"Jeff","P","Bezos", 199318, 119.40},
		{"Bill", "H","Gates", 199462, 91.0},
		{"Warren", "E", "Buffet", 193087, 84.80},
		{"Bernard","JE","Arnault", 194969, 83.40},
		{"Mark", "The Zuck", "Zuckerberg", 198433, 66.00},
		{"Amancio", "O","Ortega", 193682,69.40}};

	fptr= fopen("accounts.dat", "ab");
	for(int i =0; i <7; i++){
		fwrite(&accounts[i], sizeof(Account), 1, fptr);
	}
	fclose(fptr);
	return 0;
}
