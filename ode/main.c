#include <math.h>
#include<stdio.h>

#include "ode.h"

static double fy (double t) {

	return (exp(t*t/2) - t*t - 2);
}

static double dy (double t, double y) {

	return (t*y + t*t*t);
}

int main (void) {

	double M1, M01, M001;

	double y = fy(2.4);

	double tol = pow (10.0, -9.0);

	printf("Ponto Medio \n");

	printf("h     y(2.4)       erro\n");

	printf("- - - - - -\n");

	M1 = PontoMedio(0, 2.4, 0.1, -1, dy);
	M01 = PontoMedio(0, 2.4, 0.01, -1, dy);
	M001 = PontoMedio(0, 2.4, 0.001, -1, dy);

	printf("0.1    %f     %f\n", M1, fabs(y - M1));
	printf("0.01    %f     %f\n", M01, fabs(y - M01));
	printf("0.001    %f     %f\n", M001, fabs(y - M001));
	printf("- - - - - -\n");

	printf("Ponto Medio Adaptativo \n");

	printf("h     y(2.4)       erro\n");

	printf("- - - - - -\n");

	M1 = PontoMedioAdapt(0, 2.4, 0.1, -1, dy,tol);
	M01 = PontoMedioAdapt(0, 2.4, 0.01, -1, dy,tol);
	M001 = PontoMedioAdapt(0, 2.4, 0.001, -1, dy,tol);

	printf("0.1    %f     %f\n", M1, fabs(y - M1));
	printf("0.01    %f     %f\n", M01, fabs(y - M01));
	printf("0.001    %f     %f\n", M001, fabs(y - M001));

	printf("- - - - - -\n");

	return 0;
}
