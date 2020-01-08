#include "mmq.h"
#include "matriz.h"

int main (void) {

	double **A = matcria(5, 3);
	double **B = matcria(5, 4);
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

	double erro_norma2_1 = MMQ(5, 3, A, b1, x1);
	double erro_norma2_2 = MMQ(5, 4, B, b2, x2);

	printf("Matriz A:\n");

	for(int i=0; i<3; i++){
		printf("x%d: %f\n", i+1, x1[i]);
	}

	printf("erro norma 2: %f\n", erro_norma2_1);

	printf("\nMatriz B:\n");

	for(int i=0; i<4; i++){
		printf("x%d: %f\n", i+1, x2[i]);
	}

	printf("erro norma 2: %f\n", erro_norma2_2);

	matlibera(5, A);
	matlibera(5, B);

	free(x1);
	free(x2);

	double *t = (double *)malloc(24*sizeof(double));
	if(!t) {
		puts("Erro de alocacao na memoria.");
		exit(1);
	}

	double *v = (double *)malloc(24*sizeof(double));
	if(!t) {
		puts("Erro de alocacao na memoria.");
		exit(1);
	}

	double *c = (double *)malloc(5*sizeof(double));
	if(!t) {
		puts("Erro de alocacao na memoria.");
		exit(1);
	}

	t[0] = 0.0 / 24.0;
	t[1] = 1.0 / 24.0;
	t[2] = 2.0 / 24.0;
	t[3] = 3.0 / 24.0;
	t[4] = 4.0 / 24.0;
	t[5] = 5.0 / 24.0;
	t[6] = 6.0 / 24.0;
	t[7] = 7.0 / 24.0;
	t[8] = 8.0 / 24.0;
	t[9] = 9.0 / 24.0;
	t[10] = 10.0 / 24.0;
	t[11] = 11.0 / 24.0;
	t[12] = 12.0 / 24.0;
	t[13] = 13.0 / 24.0;
	t[14] = 14.0 / 24.0;
	t[15] = 15.0 / 24.0;
	t[16] = 16.0 / 24.0;
	t[17] = 17.0 / 24.0;
	t[18] = 18.0 / 24.0;
	t[19] = 19.0 / 24.0;
	t[20] = 20.0 / 24.0;
	t[21] = 21.0 / 24.0;
	t[22] = 22.0 / 24.0;
	t[23] = 23.0 / 24.0;

	v[0] = 13.75;
	v[1] = 14.51;
	v[2] = 14.49;
	v[3] = 13.98;
	v[4] = 12.69;
	v[5] = 11.05;
	v[6] = 8.83;
	v[7] = 5.66;
	v[8] = 4.68;
	v[9] = 7.79;
	v[10] = 10.11;
	v[11] = 12.33;
	v[12] = 13.64;
	v[13] = 14.32;
	v[14] = 14.53;
	v[15] = 13.83;
	v[16] = 12.08;
	v[17] = 10.60;
	v[18] = 8.13;
	v[19] = 5.6;
	v[20] = 4.72;
	v[21] = 6.45;
	v[22] = 9.08;
	v[23] = 12.09;

	double erro = periodico(23, t, v, c);

	printf("\nModelo Periódico:\n");

	for (int i = 0; i < 23; i++){
		printf("%g\n", c[i]);
	}

	printf("Erro: %g\n", erro);

	double prev = previsao(c, t[10]);
	printf("\nPrevisão: \n");
	printf("Para t = %f\n",t[10]);
	printf("Valor dado para o Modelo Periódico: %f\n", v[10]);
	printf("Valor com base no Modelo Periódico: %f\n", prev);

	free(t);
	free(v);
	free(c);

	return 0;
}
