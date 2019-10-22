#include <stdio.h>
#include <math.h>

#include "simpson.h"

#define PI 3.14159265358979323846264

double f1(double x) {
	return x / sqrt(x * x + 9.0);
}

double f2(double x) {
	return (1.0 / sqrt(2.0 * PI)) * exp((-x*x) / 2.0);
}

double f3(double x) {
	return (2.0 / sqrt(PI)) * exp(-x*x);
}

int main(void) {
	double a = 0, b = 1, tol = 1e-7;

	printf("f1(x)=> Adaptive Simpson: %g\tQuadratura2: %g\tQuadratura3: %g\n", AdaptiveSimpson(a, b, f1, tol), Quadratura2(a, b, f1), Quadratura3(a, b, f1));

	a = -1;

	printf("f2(x)=> Adaptive Simpson: %g\tQuadratura2: %g\tQuadratura3: %g\n", AdaptiveSimpson(a, b, f2, tol), Quadratura2(a, b, f2), Quadratura3(a, b, f2));

	a = 0;
	b = 3;

	printf("f3(x)=> Adaptive Simpson: %g\tQuadratura2: %g\tQuadratura3: %g\n", AdaptiveSimpson(a, b, f3, tol), Quadratura2(a, b, f3), Quadratura3(a, b, f3));

	return 0;
}
