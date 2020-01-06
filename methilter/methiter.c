#include <stdio.h>
#include <math.h>

#include "methiter.h"
#include "matriz.h"

void vetsum (int n, double* a, double* b, double* v, double sinal) {
    for (int i = 0; i < n; i++) {
        v[i] = a[i] + (sinal * b[i]);
    }
}

void residuo (int n, double** A, double* b, double* x, double* r) {
    double* Ax = vetcria(n);

    multmv(n, n, A, x, Ax);

    for (int i = 0; i < n; i++) {
        r[i] = b[i] - Ax[i];
    }

    vetlibera(Ax);
}

void multdv (int n, double d, double* v, double* dv) {
    for (int i = 0; i < n; i++) {
        dv[i] = d * v[i];
    }
}

int Jacobi (int n, double** A, double* b, double* x, double tol){
	int i, j, cont = 0;

	double *v = vetcria(n);
	double *d = vetcria(n);

	if(v == NULL || d == NULL){
		printf("Erro de alocacao na memoria.\n");
		exit(1);
	}

	while(1) {
		for(i=0; i<n; i++) {
			v[i] = x[i];
			x[i] = 0;

			for(j=0; j<n; j++){
				if(i!=j){
					x[i] += A[i][j]*v[j];
				}

			}
		}

		for(i=0; i<n; i++) {
			x[i] = b[i] - x[i];
			x[i] = (1/A[i][i])*x[i];
		}

		cont++;

		for(i=0; i<n; i++) {
			d[i] = x[i] - v[i];
		}

		if(norma2(n, d) <= tol) {
			break;
		}
	}

	free(v);
	free(d);

	return cont;

}

int GradConj (int n, double** A, double* b, double* x, double tol){
	int num_iteracoes = 0;

	double erro;
	double alpha = 0;
	double beta = 0;

	double* r = vetcria(n);
	residuo(n, A, b, x, r);

	double* d = vetcria(n);
	residuo(n, A, b, x, d);

	double* Ad = vetcria(n);
	double* alphad = vetcria(n);
	double* betad = vetcria(n);
	double* alphaAd = vetcria(n);

	do {
		double rtr = escalar(n, r, r);

		multmv(n, n, A, d, Ad);

		alpha = rtr / escalar(n, d, Ad);

		multdv(n, alpha, d, alphad);

		vetsum(n, x, alphad, x, 1); // chances de dar merda

		multdv(n, alpha, Ad, alphaAd);

		vetsum(n, r, alphaAd, r, -1); // chances de dar merda

		beta = escalar(n, r, r) / rtr;

		multdv(n, beta, d, betad);

		vetsum(n, r, betad, d, 1);

		erro = norma2(n,r);

		num_iteracoes++;

	} while( erro > tol ); /* do-while */

	vetlibera(r);
	vetlibera(d);
	vetlibera(Ad);
	vetlibera(alphad);
	vetlibera(betad);
	vetlibera(alphaAd);

	return num_iteracoes;
}
