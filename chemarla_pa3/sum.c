//Vibhav Chemarla
//cs2750 PA 3
//03/18/2018
#include "sum.h"

double sum(float a[], double b)
{
	double sumTotal;
	for (int i = 0; i < b; i++)
	{
		sumTotal += a[i];
	}
	return sumTotal;

}
