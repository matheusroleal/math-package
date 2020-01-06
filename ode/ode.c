#include<stdio.h>
#include<math.h>

#include "ode.h"

double PontoMedio (double t0, double t1, double h, double y0, double (*f) (double t, double y)) {
	double yt,k;

	yt = y0;

	for(double t = t0; t < t1; t+=h){
		if(t+h > t1){
			h = t1 -t;
		}

		k =  h*f(t0,yt);
		yt = yt + h*f(t + h/2.0, yt + k/2.0);

	}

	return yt;
}

double PontoMedioAdapt (double t0, double t1, double h0, double y0, double (*f) (double t, double y), double tol) {
	double yt, ym, t, h, delta, gamma;
	double y1, y2;

	t = t0;
	h = h0;

	while(t < t1){

		y1 = yt + h*f(t,yt);
		ym = yt + (h/2.0)*f(t,yt);
		y2 = ym + (h/2.0)*f(t+(h/2.0),ym);

		delta = y2 - y1;
		gamma = pow(tol/fabs(delta/3.0),1.0/3.0);

		h = gamma * h;

		if(gamma >= 1){
			yt = y2 + (delta/3.0);
			t += h;
		}
	}

	return yt;
}
