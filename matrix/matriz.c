#include "matriz.h"

double* vetcria (int n) {

	int i;
	double *A = (double *)malloc(n * sizeof(double));

	if(!A) {
		puts("Erro de alocacao na memoria.");
		exit(1);
	}

	for(i = 0; i < n; i++) {
		A[i] = (double *)malloc(n * sizeof(double));

		if(!A[i]) {
		puts("Erro de alocacao na memoria.");
		exit(1);
		}

		A[i] = 0;
	}

	return A;
}

void vetlibera (double* v) {
	free(A);
}

double** matcria (int m, int n) {  // m = linhas, n = colunas

	int i, j;
	double **A = (double **)malloc(m * sizeof(double));

	if(!A) {
		puts("Erro de alocacao na memoria.");
		exit(1);
	}

	for(i=0; i<m; i++) {
		A[i] = (double *)malloc(n * sizeof(double));

		if(!A[i]) {
		puts("Erro de alocacao na memoria.");
		exit(1);
		}

		for(j=0; j<n; j++)
			A[i][j] = 0;
	}

	return A;
}

void matlibera (int m, double** A) {

	int i;

	for(i=0; i<m; i++)
		free(A[i]);

	free(A);
}

void transposta (int m, int n, double** A, double** T) {

	int i, j;

	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			T[j][i] = A[i][j];
}

void multv (int m, int n, double** A, double* v, double* w) {

	// v tem dimensão n e w tem dimensão m

	int i, j;

	for(i=0; i<m; i++) {
		w[i] = 0;

		for(j=0; j<n; j++)
			w[i] += A[i][j]*v[j];
	}
}

void multm (int m, int n, int q, double** A, double** B, double** C) {

	// A->mxn, B->nxq, C->mxq

	int i;

	double **aux1 = matcria(q, n);  // aux1->qxn
	double **aux2 = matcria(m, q);
	transposta(n, q, B, aux1);  // aux1 é a transposta de B

	for(i=0; i<q; i++)  // aux1[i] tem dimensão n para todo i
		multv(m, n, A, aux1[i], aux2[i]);

	transposta(m, q, aux2, C);

	matlibera(q, aux1);
	matlibera(m, aux2);
}

int mat_iguais (int m, int n, double** A, double** B, double tol) {

	int i, j;

	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			if( fabs(fabs(A[i][j]) - fabs(B[i][j])) > tol )
				return 1;
	return 0;
}

void mat_imprime (int m, int n, double** A, char* format) {

	int i, j;

	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			printf(format, A[i][j]);
			printf(" ");
		}
		printf("\n");
	}
}
