#include "mmq.h"
#include "matriz.h"
#include <math.h>
#include <stdio.h>
#define PI 3.14159265359

// INIT --- Funções Auxiliares
void fatoracao(int n, double** a, int* p) {
	int i, j, m, k, t;
	double f, td;

  for (i=0; i<n; ++i){
		p[i] = i;
	}

  for (j=0; j<n-1; ++j) {
    m = j;

    for (i=j+1; i<n; ++i){
			if (fabs(a[i][j]) > fabs(a[m][j])){
				m = i;
			}
		}

    for (k=0; k<n; ++k) {
      td = a[j][k];
      a[j][k] = a[m][k];
      a[m][k] = td;
    }

    t = p[j];
    p[j] = p[m];
    p[m] = t;

    for (i=j+1; i<n; ++i) {
      f = a[i][j]/a[j][j];

		  for (k=j+1; k<n; ++k){
				a[i][k] -= f*a[j][k];
			}

		  a[i][j] = f;
    }
  }
}

void substituicao(int n, double** a, int* p, double* b, double* x) {
	int i, j;
	double s;

  for (i=0; i<n; ++i) {
    s = 0;
    for (j=0; j<i; ++j){
			s += a[i][j]*x[j];
		}
    x[i] = b[p[i]] - s;
  }

  for (i=n-1; i>=0; --i) {
    s = 0;
    for (j=i+1; j<n; ++j){
			s += a[i][j]*x[j];
		}
    x[i] = (x[i] - s) / a[i][i];
  }
}

// END --- Funções Auxiliares


double MMQ (int m, int n, double** A, double* b, double* x) {
	double soma = 0.0;

	double **AT = matcria(n, m);
	double **Aaux = matcria(n, n);

	double *aux = (double *)malloc(n*sizeof(double));
	if(!aux) {
		printf("Erro de alocacao na memoria. \n");
		exit(1);
	}

	int *p = (int *)malloc(n*sizeof(int));
	if(!p) {
		printf("Erro de alocacao na memoria. \n");
		exit(1);
	}

	double *r = (double *)malloc(m*sizeof(double));
	if(!r) {
		printf("Erro de alocacao na memoria. \n");
		exit(1);
	}

 	// Gerando a matriz transposta AT(nxm)
	transposta(m, n, A, AT);

	// Aaux(nxn)
	multmm(n, m, n, AT, A, Aaux);
	fatoracao(n, Aaux, p);

	// b(m), aux(n)
	multmv(n, m, AT, b, aux);

	substituicao(n, Aaux, p, aux, x);

	// Calculando a norma
	for(int i=0; i<m; i++) {
		r[i] = b[i] - r[i];
		soma += r[i]*r[i];
	}

	matlibera(n, AT);
	matlibera(n, Aaux);

	free(aux);
	free(p);

	return sqrt(soma);
}

double periodico (int n, double* t, double* v, double* c) {
	int coluna = 5;

	double erro;

	double** A = matcria(n, coluna);

	for(int i = 0; i < n; i++) {
		A[i][0] = 1;
		A[i][1] = t[i];
		A[i][2] = sin(2 * PI * t[i]);
		A[i][3] = cos(2 * PI * t[i]);
		A[i][4] = cos(4 * PI * t[i]);
	}

	erro = MMQ(n, coluna, A, v, c);

	matlibera(n, A);

	return erro;
}

double previsao (double* c, double t){
	return c[0] + c[1]*t + c[2]*sin(2 * PI * t) + c[3]*cos(2 * PI * t) + c[4]*cos(4 * PI * t);
}
