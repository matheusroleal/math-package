#include "sistlinear.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void gauss(int n, double** A, double* b, double* x){
	int i, j, k, p;
	double s, f, temp;

	for(j = 0; j < n; j++){
		x[j] = 0.0;
	}

	for(j = 0; j < n - 1; j++){
		// PIVOTAMEnTO
		p = j;

		for(k = j + 1; k < n; k++){
			if(fabs(A[k][j]) > fabs(A[p][j])){
				p = k;
			}
		}

		for(k = j; k < n; k++){
			temp = A[p][k];
			A[p][k] = A[j][k];
			A[j][k] = temp;
		}

		temp = b[p];
		b[p] = b[j];
		b[j] = temp;
		// FIM PIVOTAMEnTO

		for(i = j + 1; i < n; i++){
			f = A[i][j] / A[j][j];

			for(k = j; k < n; k++){
				A[i][k] = A[i][k] - A[j][k] * f;
			}

			b[i] = b[i] - b[j] * f;
		}
	}

	for(i = n - 1; i >= 0; i--){
		s = 0.0;
		for(j = i + 1; j <= n - 1; j++){
			s = s + A[i][j] * x[j];
		}

		x[i] = (b[i] - s) / A[i][i];
	}
}

void cholesky(int n, double** A){
	int i, j;
	double **lower = (double **)malloc(n * sizeof(double));

	if(!lower) {
		puts("Erro de alocacao na memoria.");
		exit(1);
	}

	for(i=0; i<n; i++) {
		lower[i] = (double *)malloc(n * sizeof(double));

		if(!lower[i]) {
		puts("Erro de alocacao na memoria.");
		exit(1);
		}

		for(j=0; j<n; j++)
			lower[i][j] = 0;
	}

	// Decomposing a matrix into Lower Triangular
	for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
					int sum = 0;

					if (j == i) {
							for (int k = 0; k < j; k++)
									sum += pow(lower[j][k], 2);
							lower[j][j] = sqrt(A[j][j] - sum);
					} else {
							// Evaluating L(i, j) using L(j, j)
							for (int k = 0; k < j; k++){
								sum += (lower[i][k] * lower[j][k]);
							}
							lower[i][j] = (A[i][j] - sum) / lower[j][j];
					}
			}
	}

	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			A[i][j] = lower[i][j];
			if(lower[i][j] == 0.0){
				A[i][j] = lower[j][i];
			}
		}
	}
	
}

void substituicoes(int n, double** A, double* b, double* x){
	int i, j;
	double s;

	// forward substitution
	for (i=0; i<n; ++i) {
		s = 0;
		for (j=0; j<i; ++j){
			s += A[i][j]*x[j];
		}
		x[i] = b[i] - s;
	}

	// backward substitution
	for (i=n-1; i>=0; --i) {
		s = 0;
		for (j=i+1; j<n; ++j) {
			s += A[i][j]*x[j];
		}
		x[i] = (x[i] - s) / A[i][i];
	}
}
