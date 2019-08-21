#include "matriz.h"

int main (void) {

	double** A = mat_cria(2, 3);
	double** B = mat_cria(2, 3);
	double** C = mat_cria(2, 2);
	double** T = mat_cria(3, 2);

	double* v = (double *)malloc(3 * sizeof(double));
	double* w = (double *)malloc(2 * sizeof(double));

	if(!v || !w) {
		puts("Erro de alocacao na memoria");
		exit(1);
	}

	A[0][0] = 1;
	A[0][1] = 2;
	A[0][2] = 3;
	A[1][0] = 4;
	A[1][1] = 5;
	A[1][2] = 6;

	B[0][0] = 1;
	B[0][1] = 2;
	B[0][2] = 3;
	B[1][0] = 5;
	B[1][1] = 7;
	B[1][2] = 6;

	v[0] = 3;
	v[1] = 2;
	v[2] = 1;

	mat_transposta(2, 3, B, T);

	printf("\n");
	mat_imprime(2, 3, A, "%f");
	printf("\n");
	mat_imprime(2, 3, B, "%f");
	printf("\n");
	mat_imprime(3, 2, T, "%f");
	printf("\n");

	printf("%d\n", mat_iguais(2, 3, A, B, 1));  // tol = 1
	printf("%d\n", mat_iguais(2, 3, A, B, 2));  // tol = 2

	mat_multv(2, 3, A, v, w);

	printf("\n");

	printf("%f %f %f\n", v[0], v[1], v[2]);
	printf("%f %f\n", w[0], w[1]);

	mat_multm(2, 3, 2, A, T, C);

	printf("\n");
	mat_imprime(2, 2, C, "%f");
	printf("\n");

	mat_libera(2, A);
	mat_libera(2, B);
	mat_libera(3, T);

	free(v);
	free(w);

	return 0;
}
