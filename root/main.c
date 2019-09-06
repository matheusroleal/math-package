# include <math.h>
# include <stdio.h>
#include "raiz.h"
// ##################################### AUX FUNC - INIT ######################################

static double f (double x) {
	return (cos(x) - x*x*x + x);
}

static double velocidade_pqd(double x){
	return (( (9.8 * x) / 15000 ) * ( 1 - exp( -(15000/x) ) ));
}

// ##################################### AUX FUNC - END #######################################

int main (void) {

	double r0, r1;
	int val;

	printf(" ----- Usando f(x) = cos(x) - x ^ 3 + x ----- \n\n");

	val = secante(0.0, 23.0, 6, &f, &r0);
	printf(" ----- Secante ----- \n");
	printf(" ----- Tentativas: %d ----- Valor: %.6g ----- \n\n",val, r0);

	val = IQI(0.0, 23.0, 120.0, 6, &f, &r1);
	printf(" ----- Interpolacao Quadratica Inversa ----- \n");
	printf(" ----- Tentativas: %d ----- Valor: %g ----- \n\n\n",val, r1);

	printf(" ----- Usando v = gm/c * ( 1 − e ^(− ct/m) ) ----- \n\n");

	val = secante(10.0, 100.0, 6, &velocidade_pqd, &r0);
	printf(" ----- Secante ----- \n");
	printf(" ----- Tentativas: %d ----- Valor: %.6g ----- \n\n",val, r0);

	val = IQI(10.0, 100.0, 200.0, 6, &velocidade_pqd, &r1);
	printf(" ----- Interpolacao Quadratica Inversa ----- \n");
	printf(" ----- Tentativas: %d ----- Valor: %g ----- \n\n",val, r1);

	return 0;
}
