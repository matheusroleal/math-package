#include "matriz.h"

double* vetcria(int n)
{
    if (n < 0)
        return NULL;
    
    return (double*) malloc (n * sizeof(double));
}

void vetlibera(double* v)
{
    free(v);
}

double escalar(int n, double* v, double* w)
{
    double produtoEscalar = 0.0;
    
    int i = 0;
    
    if (v == NULL || w == NULL)
    {
        printf("Um dos vetores passados é nulo. Não é possível calcular o produto escalar.");
        return produtoEscalar;
    }
    
    while (i<n) {
        produtoEscalar += v[i] * w[i];
        i++;
    }
    
    return produtoEscalar;
}

double norma2(int n, double* v)
{
    double norma2 = 0.0;
    double expoente = 2.0;
    
    int i = 0;
    
    while (i<n) {
        norma2 += pow(v[i], expoente);
        i++;
    }
    
    return sqrt(norma2);
}

double** matcria (int m, int n) {
    int i;
    double ** matriz;
    
    matriz = malloc(m * sizeof(double *));
    
    for (i = 0; i < m; i++) {
        matriz[i] = malloc(n * sizeof(double));
    }
    
    return matriz;
}

void matlibera (int m, double** A) {
    int i;
    
    for (i = 0; i < m; i++) {
        free(A[i]);
        A[i] = NULL;
    }
    
    free(A);
}

void transposta (int m, int n, double** A, double** T) {
    int i, j;
    
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            T[j][i] = A[i][j];
}

void multmv (int m, int n, double** A, double* v, double* w) {
    int i, j;
    double aux = 0.0;
    
    for (i = 0; i < m; i++) {
        aux = 0.0;
        
        for (j = 0; j < n; j++) {
            aux += A[i][j] * v[j];
        }
        
        w[i] = aux;
    }
}

void multmm (int m, int n, int q, double** A, double** B, double** C) {
    int i, j, k;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            C[i][j] = 0;
            
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

void imprime (int m, int n, double** A, char* format) {
    int i, j;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf(format, A[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}

