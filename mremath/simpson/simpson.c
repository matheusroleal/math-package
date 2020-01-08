#include "simpson.h"
#include <math.h>

double DoubleSimpson (double a, double b, double (*f) (double x), double* v) {

	double erro;
	double h = b-a;
	double c = (a+b)/2;
	double Sab, Sac, Scb;

	Sab = (h/6)*(f(a)+4*f((a+b)/2)+f(b));
	Sac = ((h/2)/6)*(f(a)+4*f((a+c)/2)+f(c));
	Scb = ((h/2)/6)*(f(c)+4*f((c+b)/2)+f(b));

	erro = (Sab-Sac-Scb)/15;

	*v = Sac + Scb - erro;

	return fabs(erro);
}

double AdaptiveSimpson (double a, double b, double (*f) (double x), double tol) {

	double v;
	double erro;
	double c = (a+b)/2;

	erro = DoubleSimpson(a, b, f, &v);

	if(erro < tol) {
		return v;
	} else {
		return AdaptiveSimpson(a, c, f, tol/2)+AdaptiveSimpson(c, b, f, tol/2);
	}
}

double Quadratura2 (double a, double b, double (*f) (double x)) {
	double r = (b-a)/2.0;

	double x1 = ((b-a)*sqrt(1.0/3.0) + b + a)/2.0;

	double x2 = ((-1.0)*(b-a)*sqrt(1.0/3.0) + b + a)/2.0;

	return r*(f(x1) + f(x2));
}

double Quadratura3 (double a, double b, double (*f) (double x)) {
	double r = (b-a)/2.0;

	double x1 = ((b-a) * (-sqrt(3.0 / 5.0)) + b + a) / 2.0;

	double x2 = ((b-a) * (0.0) + b + a) / 2.0;

	double x3 = ((b - a) * (sqrt(3.0 / 5.0)) + b + a) / 2.0;

	return ((5.0 / 9.0) * f(x1) + (8.0 / 9.0) * f(x2) + (5.0 / 9.0) * f(x3)) * r;
}
