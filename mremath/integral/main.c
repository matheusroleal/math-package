#include <math.h>
#include <stdio.h>
#include "integral.h"

#define PI 3.14159265358979323846264
#define INT1 2.0
#define INT2 6.9986217091241
#define INT3 5.8696044010894

static double f(double x) {
	return cos(x) - 2 * sin(x);
}

static double f1(double x) {
	return -sin(x) - 2 * cos(x);
}

static double fi1 (double x) {

	return (x/pow(x*x+9, 0.5));
}

static double fi2 (double x) {

	return (x*x*log(x));
}

static double fi3 (double x) {

	return (x*x*sin(x));
}

int main (void) {
	double resp;

	double h = h_otimo(f, f1, 0);
	printf("h otimo de f'(0): %.16g \n", h);

	printf("\n");
	resp = simpson(fi1, 0, 4, 16);
	printf("S1 n=16: %.16f;   Erro: %.16g\n", resp, fabs(resp-INT1));
	resp = simpson(fi1, 0, 4, 32);
	printf("S1 n=32: %.16f;   Erro: %.16g\n", resp, fabs(resp-INT1));
	resp = pontomedio(fi1, 0, 4, 16);
	printf("M1 n=16: %.16f;   Erro: %.16g\n", resp, fabs(resp-INT1));
	resp = pontomedio(fi1, 0, 4, 32);
	printf("M1 n=32: %.16f;   Erro: %.16g\n", resp, fabs(resp-INT1));

	printf("\n");
	resp = simpson(fi2, 1, 3, 16);
	printf("S2 n=16: %.16f;   Erro: %.16g\n", resp, fabs(resp-INT2));
	resp = simpson(fi2, 1, 3, 32);
	printf("S2 n=32: %.16f;   Erro: %.16g\n", resp, fabs(resp-INT2));
	resp = pontomedio(fi2, 1, 3, 16);
	printf("M2 n=16: %.16f;   Erro: %.16g\n", resp, fabs(resp-INT2));
	resp = pontomedio(fi2, 1, 3, 32);
	printf("M2 n=32: %.16f;   Erro: %.16g\n", resp, fabs(resp-INT2));

	printf("\n");
	resp = simpson(fi3, 0, PI, 16);
	printf("S3 n=16: %.16f;   Erro: %.16g\n", resp, fabs(resp-INT3));
	resp = simpson(fi3, 0, PI, 32);
	printf("S3 n=32: %.16f;   Erro: %.16g\n", resp, fabs(resp-INT3));
	resp = pontomedio(fi3, 0, PI, 16);
	printf("M3 n=16: %.16f;   Erro: %.16g\n", resp, fabs(resp-INT3));
	resp = pontomedio(fi3, 0, PI, 32);
	printf("M3 n=32: %.16f;   Erro: %.16g\n", resp, fabs(resp-INT3));

	return 0;
}
