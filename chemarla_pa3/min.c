//Vibhav Chemarla
//cs2750 PA 3
//03/18/2018
//min.c

#include "min.h"

double min(float a[], double b)
{
	double minTotal = a[0];
	for (int i = 0; i < b; i++){
		if (a[i] < minTotal)
		minTotal = a[i];
	}
	return minTotal;
}
