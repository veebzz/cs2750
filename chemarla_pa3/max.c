//Vibhav Chemarla
//cs2750 PA 3
//03/18/2018

#include "max.h"

double max(float a[], double b){

	double maxTotal;
	for (int i = 0; i < b; i++){

		if (a[i] > maxTotal)
		maxTotal = a[i];
	}
	return maxTotal;
}
