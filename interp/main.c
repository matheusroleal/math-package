#include "interp.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265359

int Fact (int x){
	if (x == 1){
		return 1;
	}
	return (x * Fact(x-1));
}

int main (void) {
	int n = 6;

	double *xi = (double *)malloc(n*sizeof(double));

	if(!xi) {
		printf("Erro de alocacao na memoria.");
		exit(1);
	}

	Chebyshev(n, 0, PI/2, xi);

	printf("------ Chebyshev ------\n");

	for(int i=0; i<n; i++)
		printf("%f\n", xi[i]);

	printf("\n");

	double *bi = (double *)malloc(n*sizeof(double));

	if(!bi) {
		printf("Erro de alocacao na memoria.");
		exit(1);
	}

	printf("------ Coeficiente de Newton ------\n");

	NewtonCoef(n, xi, sin, bi);

	for(int i=0; i<n; i++)
		printf("%f\n", bi[i]);

	printf("\n");

	printf("------ Avaliação de Newton ------\n");

	double x = 1;
	double aval = NewtonAval(n, xi, bi,x);

	printf("%f\n", aval);

	double erro = aval - sin(x);
	double max = (pow(PI/4,n)/pow(2,n-1))*(1/Fact(n));

	printf("Erro: %f < %f\n", erro, max);

	free(xi);
	free(bi);

	return 0;
}
