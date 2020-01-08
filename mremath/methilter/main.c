#include <math.h>
#include "methiter.h"
#include "matriz.h"

int main (void) {
	double **A1 = matcria(2, 2);
	double **A2 = matcria(6, 6);

	double b1[] = {5, 5};
	double b2[] = {2.5, 1.5, 1.0, 1.0, 1.5, 2.5};

	double x1[] = {0, 0};
	double x2[] = {0, 0, 0, 0, 0, 0};

	int i1, i2;

	A1[0][0] = 3;
	A1[0][1] = A1[1][0] = 1;
	A1[1][1] = 2;

	A2[0][5] = A2[1][4] = A2[4][1] = A2[5][0] = 0.5;
	A2[0][0] = A2[1][1] = A2[2][2] = A2[3][3] = A2[4][4] = A2[5][5] = 3;
	A2[0][1] = A2[1][0] = A2[2][1] = A2[1][2] = A2[3][2] = A2[2][3] = A2[4][3] = A2[3][4] = A2[4][5] = A2[5][4] = -1;
	A2[0][2] = A2[0][3] = A2[0][4] = A2[1][3] = A2[1][5] = A2[2][0] = A2[2][4] = A2[2][5] = A2[3][0] = A2[3][1] = A2[3][5] = A2[4][0] = A2[4][2] = A2[5][1] = A2[5][2] = A2[5][3] = 0;

	i1 = Jacobi(2, A1, b1, x1, pow(10, -7));
	i2 = Jacobi(6, A2, b2, x2, pow(10, -7));

	printf("Jacobi A1: interacoes = %d\nx = %f %f\n", i1, x1[0], x1[1]);
	printf("\n");
	printf("Jacobi A2: interacoes = %d\nx = %f %f\n", i2, x2[0], x2[1]);
	printf("\n");
	printf("\n");

	x1[0] = 0;
	x1[1] = 0;

	x2[0] = 0;
	x2[1] = 0;
	x2[2] = 0;
	x2[3] = 0;
	x2[4] = 0;
	x2[5] = 0;

	i1 = GradConj(2, A1, b1, x1, pow(10, -7));
	i2 = GradConj(6, A2, b2, x2, pow(10, -7));

	printf("GradConj A1: interacoes = %d\nx = %f %f\n", i1, x1[0], x1[1]);
	printf("\n");
	printf("GradConj A2: interacoes = %d\nx = %f %f\n", i2, x2[0], x2[1]);

	matlibera(2, A1);
	matlibera(6, A2);

	return 0;
}
