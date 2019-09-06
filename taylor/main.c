# include <math.h>
# include <stdio.h>
#include "taylor.h"

int main (void) {

	printf("######### f(x): cos^2(x) #########\n");
	printf("%f (Cosseno de 0)\n", cos(0));
	printf("%f (Aproximacao de cosseno de 0)\n", cos2(0));
	printf("%f (Residuo maximo da aproximacao)\n", cos2_rmax(0));
	printf("%f (Diferenca do cosseno pela aproximacao)\n\n", cos(0) - cos2(0));

	printf("######### f(x): sqrt(x) #########\n");
	printf("%f (f(1))\n", sqrt(1));
	printf("%f (Aproximacao de f(1))\n", raiz(1));
	printf("%f (Residuo maximo da aproximacao)\n", raiz_rmax(1));
	printf("%f (Diferenca de f(1) pela aproximacao)\n\n", sqrt(1) - raiz(1));

	return 0;
}
