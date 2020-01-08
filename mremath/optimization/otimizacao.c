#include <math.h>

#include "otimizacao.h"

int secaoaurea (double a, double b, double (*f) (double x), double tol, double* xmin){
	double g = (sqrt(5.0) - 1.0) / 2.0;

	double x1 = a + (1 - g)*(b-a);
	double x2 = a + g*(b-a);

	int interacoes = 0.0;

	while (fabs(f(x1) - f(x2)) > tol){
		if (f(x1) < f(x2)){
			b = x2;

			x2 = x1;
			x1 = a + (1 - g)*(b - a);
		} else {
			a = x1;

			x1 = x2;
			x2 = a + g*(b - a);
		}


		interacoes++;
	}

	*xmin = (x1 + x2) / 2.0;

	return interacoes;
}

int parabolica (double r, double s, double t, double (*f) (double x), double tol, double* xmin){
	double x;

	int interacoes = 0.0;

	while (fabs(f(s) - f(t)) > tol){
		x = ( (r + s) / 2.0 ) - ( ( f(s) - f(t) )*( t - r )*( t - s ) ) / (2*( ( s - r )*( ( f(t) - f(s) )-( f(s) - f(r) )*( t - s ) ) ) );

		r = s;
		s = t;
		t = x;

		interacoes++;
	}

	*xmin = (s + t) / 2.0;

	return interacoes;
}
