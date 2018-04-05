/*Vibhav Chemarla
 * cs2750 PA 3
 * date 03/18/2018
 */


#include "sum.h"
#include "avg.h"

double avg(float a[], double b){
	double avgTotal = sum(a,b) /b;
	return avgTotal;
}
