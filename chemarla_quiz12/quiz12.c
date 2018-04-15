#include<stdio.h>
#include<stdlib.h>

int main()
{
   int n, sum = 0, i;
      int* arr;
         printf("Enter n: ");
	    scanf("%d",&n);
	       arr = (int*)malloc(sizeof(int)*n);
	          printf("Enter %d numbers:\n",n);
		     for(i = 0;i<n;i++){
		            scanf("%d",&arr[i]);
			       }
			          for(i = 0;i<n;i++){
				         sum += arr[i];
					    }
					       printf("Sum = %d\n",sum);
					           return 0;
						   }
