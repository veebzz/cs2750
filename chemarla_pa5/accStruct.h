#ifndef _ACCSTRUCT_
#define _ACCSTRUCT_

typedef struct Account
{
	char fName[25];
	char mName[25];
	char lName[25];
	int accId;
	float accBal;
}Account;

Account accounts[50];
#endif
