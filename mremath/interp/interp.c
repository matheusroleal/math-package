#include "interp.h"
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265359

void Chebyshev (int n, double a, double b, double* xi){

	for(int i = 0; i < n; i++){
		int beta = (2 * (i+1)) - 1;
		xi[i] = ((b-a)/2)*cos((beta*PI)/(2*n))+((a+b)/2);
	}
}

static double F (int i, int j, double* xi, double (*f) (double)){

	if(i == j){
		return f(xi[i]);
	}
	else if(i < j){
		return (F(i+1, j, xi, f) - F(i, j-1, xi, f))/(xi[j] - xi[i]);
	}else{
		return 0.0;

	}
}

void NewtonCoef (int n, double* xi, double (*f) (double), double *bi){

	for(int j = 0; j < n; j++){
		bi[j] = F(0, j, xi, f);
	}

}

double NewtonAval (int n, double* xi, double* bi, double x){
	double p = bi[0];

	for(int i = 1; i < n-1; i++){
		double val = 1;

		for (int j = i;  j > 0; j--){
			val = val * (x - xi[j-1]);
		}

		p += bi[i]*val;
	}

	return p;
}

