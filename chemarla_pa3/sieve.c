#include <stdio.h>
#include <stdlib.h>

#define N 100000
 
 int main (){

	int i, j = 0, sieve[N];
		//fill sieve array with numbers 2 to N
		for (i = 2; i < N; i++)
		{
			sieve[j] = i;
			j++;
		}
		//use sieve of eratosthenes method to make nonprime = 0
		for (i = 0; i < N-2; i++)
		{
			if(sieve[i] != 0)
				for(j = 2*sieve[i]-2; j < N-2; j += sieve[i])
					sieve[j] = 0;
		}
		//Display array numbers that arent 0
		for(i=0; i < N-2;i++)
		{
			if(sieve[i] != 0)
				printf("%d\n" , sieve[i]);
		}
		return 0;
	}
