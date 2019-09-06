#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* vetcria (int n);

void vetlibera (double* v);

double** matcria (int m, int n);

void matlibera (int m, double** A);

void transposta (int m, int n, double** A, double** T);

void multv (int m, int n, double** A, double* v, double* w);

void multm (int m, int n, int q, double** A, double** B, double** C);

int mat_iguais (int m, int n, double** A, double** B, double tol);  // retorna 0 se for igual e 1 se for diferente

void mat_imprime (int m, int n, double** A, char* format);
