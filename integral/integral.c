#include "integral.h"
#include <math.h>

double derivada (double (*f) (double x), double x, double h){
	return (f(x+h) - f(x-h))/(2*h);
}

double h_otimo (double (*f) (double x), double (*fl) (double x), double x){
	double h, deri_num, deri_anal, erro;

	for(int i = 12; i > 0; i--){
		h = pow(10.0,-i);

		deri_num = derivada(f, x, h);

		deri_anal = fl(x);

		erro = fabs(deri_num - deri_anal);

		if (erro <= h){
			break;
		}
	}

	return h;
}

double richardson (double (*f) (double x), double x, double h){
	return (4*derivada(f,x,h/2) - derivada(f,x,h)) / 3;
}

double simpson (double (*f) (double), double a, double b, int n){
	double h = (b-a)/n;
	double soma = 0.0;
	double ini = a;
	double fim = a+h;

	for(int i=0; i < n; i++) {
		soma += (h/6)*(f(ini)+4*f((ini+fim)/2)+f(fim));
		ini += h;
		fim += h;
	}

	return soma;
}

double pontomedio (double (*f) (double), double a, double b, int n){
	double h = (b-a)/n;
	double soma = 0.0;
	double ini = a;
	double fim = a+h;

	for(int i=0; i < n; i++) {
		soma += h*f((ini+fim)/2);
		ini += h;
		fim += h;
	}

	return soma;
}
