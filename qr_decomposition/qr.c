#include "qr.h"
#include "matriz.h"

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

double* sub_aux(int n, double *w, double r, double *q){
	double *aux = vetcria(n);

	for(int j = 0; j < n; j++){
		aux[j] = w[j] - ( q[j] * r );
	}

	return aux;
}

double* div_aux(int n, double *w, double r){
	double *aux = vetcria(n);

	for(int j = 0; j < n; j++){
		aux[j] = w[j] / r;
	}

	return aux;
}

double* preenche_vet(int n, double **a, int j){
	double *aux = vetcria(n);

	for(int i = 0; i < n; i++){
		aux[i] = a[i][j];
	}

	return aux;
}
// END --- Funções Auxiliares

void QR (int m, int n, double** A, double** Q, double** R){
	for(int j = 0; j < n; j++){
		double *w = preenche_vet(m, A, j);

		for(int i = 0; i < j; i++){
			R[i][j] = escalar(m, w, Q[i]);
			w = sub_aux(m, w, R[i][j], Q[i]);
		}

		R[j][j] = norma2(m, w);
		Q[j] = div_aux(m, w, R[j][j]);
	}
}

double mmqQR (int m, int n, double** Q, double** R, double* b, double* x){
	double **QT = matcria(n, m);

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

 	// Gerando a matriz transposta QT(nxm)
	transposta(m, n, Q, QT);

	// Fatoração de R(nxn)
	fatoracao(n, R, p);

	// b(m), aux(n)
	multmv(n, m, QT, b, aux);

	substituicao(n, R, p, aux, x);

	return 0.0;
}
