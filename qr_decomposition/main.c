#include "qr.h"
#include "matriz.h"

int main (void) {

	double **A = matcria(5, 3);
	double **B = matcria(5, 4);

	double **Qa = matcria(5, 3);
	double **Ra = matcria(3, 3);

  double **Qb = matcria(5, 4);
  double **Rb = matcria(4, 4);

	double b1[] = {10, 10, -5, 15, 0};
	double b2[] = {10, 0, 2, 0, 5};

	double *x1 = (double *)malloc(3*sizeof(double));
	if(!x1) {
		puts("Erro de alocacao na memoria.");
		exit(1);
	}

	double *x2 = (double *)malloc(4*sizeof(double));
	if(!x2) {
		puts("Erro de alocacao na memoria.");
		exit(1);
	}

	A[0][0] = 3;
	A[0][1] = -1;
	A[0][2] = 2;
	A[1][0] = 4;
	A[1][1] = 1;
	A[1][2] = 0;
	A[2][0] = -3;
	A[2][1] = 2;
	A[2][2] = 1;
	A[3][0] = 1;
	A[3][1] = 1;
	A[3][2] = 5;
	A[4][0] = -2;
	A[4][1] = 0;
	A[4][2] = 3;

	B[0][0] = 4;
	B[0][1] = 2;
	B[0][2] = 3;
	B[0][3] = 0;
	B[1][0] = -2;
	B[1][1] = 3;
	B[1][2] = -1;
	B[1][3] = 1;
	B[2][0] = 1;
	B[2][1] = 3;
	B[2][2] = -4;
	B[2][3] = 2;
	B[3][0] = 1;
	B[3][1] = 0;
	B[3][2] = 1;
	B[3][3] = -1;
	B[4][0] = 3;
	B[4][1] = 1;
	B[4][2] = 3;
	B[4][3] = -2;

	QR(5, 3, A, Qa, Ra);

  double chegou_ao_fim_a = mmqQR(5, 3, Qa, Ra, b1, x1);

	printf("mmqQR Matriz A:\n");

  printf("Executado com sucesso? (0.000000 = Sim) --> %f\n", chegou_ao_fim_a);

	for(int i = 0; i < 3; i++){
		printf("x%d: %.12f\n", i+1, x1[i]);
	}

  QR(5, 4, B, Qb, Rb);

  double chegou_ao_fim_b = mmqQR(5, 4, Qb, Rb, b2, x2);

	printf("\nmmqQR  Matriz B:\n");

  printf("Executado com sucesso? (0.000000 = Sim) --> %f\n", chegou_ao_fim_b);

	for(int i = 0; i < 4; i++){
		printf("x%d: %.12f\n", i+1, x2[i]);
	}

	matlibera(5, A);
	matlibera(5, B);

	matlibera(5, Qa);
	matlibera(5, Qb);

	matlibera(3, Ra);
	matlibera(4, Rb);

	free(x1);
	free(x2);

	return 0;
}
