#include "sistlinear.h"
#include "matriz.h"

int main (void) {

	double** A1 = mat_cria(3, 3);
	double** A2 = mat_cria(6, 6);

	double b1[] = {3, 3, -6};
	double b2[] = {2.5, 1.5, 1, 1, 1.5, 2.5};

	double *x1;
	double *x2;

	// Inicializando os vetores
	x1 = (double *)malloc(5 * sizeof(double));
	if(!x1) {
		puts("Erro de alocacao na memoria.");
		exit(1);
	}

	x2 = (double *)malloc(2 * sizeof(double));
	if(!x2) {
		puts("Erro de alocacao na memoria.");
		exit(1);
	}

	// Dando valores das matrizes 3x3 e 6x6
	A1[0][0] = 1;
	A1[0][1] = 2;
	A1[0][2] = -1;
	A1[1][0] = 2;
	A1[1][1] = 1;
	A1[1][2] = -2;
	A1[2][0] = -3;
	A1[2][1] = 1;
	A1[2][2] = 1;

	A2[0][5] = A2[1][4] = A2[4][1] = A2[5][0] = 0.5;
	A2[0][0] = A2[1][1] = A2[2][2] = A2[3][3] = A2[4][4] = A2[5][5] = 3;
	A2[0][1] = A2[1][0] = A2[2][1] = A2[1][2] = A2[3][2] = A2[2][3] = A2[4][3] = A2[3][4] = A2[4][5] = A2[5][4] = -1;
	A2[0][2] = A2[0][3] = A2[0][4] = A2[1][3] = A2[1][5] = A2[2][0] = A2[2][4] = A2[2][5] = A2[3][0] = A2[3][1] = A2[3][5] = A2[4][0] = A2[4][2] = A2[5][1] = A2[5][2] = A2[5][3] = 0;

	printf("------- Gauss -------\n");
	mat_imprime(3, 3, A1, "%f");
	gauss(3, A1, b1, x1);
	printf("\n");
	mat_imprime(3, 3, A1, "%f");

	printf("------- Cholesky -------\n");
	mat_imprime(6, 6, A2, "%f");
	cholesky(6,A2);
	printf("\n");
	mat_imprime(6, 6, A2, "%f");

	printf("------- Substituicoes -------\n");
	substituicoes(3, A1, b1, x1);
	substituicoes(6, A2, b2, x2);

	mat_libera(3, A1);
	mat_libera(6, A2);

	for(int i=0; i<3; i++)
		printf("%f ", x1[i]);
	printf("\n");

	for(int i=0; i<6; i++)
		printf("%f ", x2[i]);
	printf("\n");

	free(x1);
	free(x2);

	return 0;
}
