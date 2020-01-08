#include <stdio.h>
#include <math.h>

#include "otimizacao.h"

static double f1 (double x) {

	return pow(x,2)+sin(x);
}

static double f2 (double x) {

	return pow(x,6)-11*pow(x,3)+17*pow(x,2)-7*x+1;
}

int main (void) {
	int inte;
	double xmin;

	printf("Metodo Secao Aurea\n");
	printf("\n");
	printf("##### f1(x) = x^2+sin(x) para x e [-1.5, 1] ##### \n");
	inte = secaoaurea(-1.5,1,f1,pow(10,-4),&xmin);
	printf("xmin: %.8f - interacao: %d \n", xmin, inte);

	printf("\n##### f2(x) = x^6-11x^3+17x^2-7x+1 para x e [0, 1.5] ##### \n");
	inte = secaoaurea(0,1.5,f2,pow(10,-4),&xmin);
	printf("xmin: %.8f - interacao: %d \n", xmin, inte);
	printf("\n");
	printf("\n");

	printf("Metodo da Interpolacao Parabolica Sucessiva\n");
	printf("\n");
	printf("##### f1(x) = x^2+sin(x) com os pontos de (-1.5, 0, 1) ##### \n");
	inte = parabolica(-1.5,0,1,f1,pow(10,-4),&xmin);
	printf("xmin: %.8f - interacao: %d \n", xmin, inte);

	printf("\n##### f2(x) = x^6-11x^3+17x^2-7x+1 com os pontos de (0, 1, 1.5) ##### \n");
	inte = parabolica(0,1,1.5,f2,pow(10,-4),&xmin);
	printf("xmin: %.8f - interacao: %d \n", xmin, inte);

	return 0;
}
