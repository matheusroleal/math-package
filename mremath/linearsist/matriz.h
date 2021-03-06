#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** mat_cria (int m, int n);

void mat_libera (int m, double** A);

void mat_transposta (int m, int n, double** A, double** T);

void mat_multv (int m, int n, double** A, double* v, double* w);

void mat_multm (int m, int n, int q, double** A, double** B, double** C);

int mat_iguais (int m, int n, double** A, double** B, double tol);  // retorna 0 se for igual e 1 se for diferente

void mat_imprime (int m, int n, double** A, char* format);
