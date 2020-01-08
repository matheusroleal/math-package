#include "raiz.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static double erro_precisao (double p) {
	return (0.5 * pow(10, -p));
}

int secante (double x0, double x1, int p, double (*f) (double x), double* r){
	int i = 0;

	double x2 = x1 - ( ( f(x1)*(x1 - x0) ) / ( f(x1) - f(x0) ) );

	double e = fabs(f(x2));

	while(e >= erro_precisao(p) && i < 100) {
		i++;

		x0 = x1;
		x1 = x2;

		x2 = x1 - ( ( f(x1)*(x1 - x0) ) / ( f(x1) - f(x0) ) );

		e = fabs(f(x2));
	}

	*r = x2;

	if(i >= 100){
		return 0;
	}

	return i;
}

int IQI(double x0, double x1, double x2, int p, double (*f) (double x), double* r){
	double x3, detA, detAc;

	double A[3][3] = {{0}}, Ac[3][3] = {{0}};
	double e = fabs(f(x2));
	int i = 0;

	while(e > erro_precisao(p) && i < 100){

		A[0][0] = f(x0) * f(x0);
		A[0][1] = f(x0);
		A[0][2] = 1;
		A[1][0] = f(x1) * f(x1);
		A[1][1] = f(x1);
		A[1][2] = 1;
		A[2][0] = f(x2) * f(x2);
		A[2][1] = f(x2);
		A[2][2] = 1;

		detA = A[0][0] * ((A[1][1] * A[2][2]) - (A[2][1] * A[1][2])) - A[0][1] * (A[1][0] * A[2][2] - A[2][0] * A[1][2]) + A[0][2] * (A[1][0] * A[2][1] - A[2][0] * A[1][1]);

		Ac[0][0] = f(x0) * f(x0);
		Ac[0][1] = f(x0);
		Ac[0][2] = x0;
		Ac[1][0] = f(x1) * f(x1);
		Ac[1][1] = f(x1);
		Ac[1][2] = x1;
		Ac[2][0] = f(x2) * f(x2);
		Ac[2][1] = f(x2);
		Ac[2][2] = x2;

		detAc = Ac[0][0] * ((Ac[1][1] * Ac[2][2]) - (Ac[2][1] * Ac[1][2])) - Ac[0][1] * (Ac[1][0] * Ac[2][2] - Ac[2][0] * Ac[1][2]) + Ac[0][2] * (Ac[1][0] * Ac[2][1] - Ac[2][0] * Ac[1][1]);

		x3 = detAc / detA;

		x0 = x1;
		x1 = x2;
		x2 = x3;

		*r = x3;

		e = fabs(f(x2));

		i++;
	}

	if (i >= 100){
		return 0;
	}

	return i;
}
