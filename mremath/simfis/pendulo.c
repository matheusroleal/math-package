#include <stdio.h>
#include <math.h>

#include "pendulo.h"

#define PI 3.141592653589793238

double pendulo (double t, double h, double* theta, double* w){
  double k_theta_1 = h*(*w);
  double k_w_1 = -(10.0/15.0)*sin((*theta))*h;

  double k_theta_2 = h*( *w + k_w_1/2.0 );
  double k_w_2 = -(10.0/15.0)*sin( (*theta) + k_theta_1 )*h;

  double k_theta_3 = h*( *w + k_w_2/2.0 );
  double k_w_3 = -(10.0/15.0)*sin( (*theta) + k_theta_2 )*h;

  double k_theta_4 = h*( *w + k_w_3/2.0 );
  double k_w_4 = -(10.0/15.0)*sin( (*theta) + k_theta_3 )*h;

  double new_w = (*w) + (k_w_1 + 2*k_w_2 + 2*k_w_3 + k_w_4)/6;
  double new_theta = (*theta) + (k_theta_1 + 2*k_theta_2 + 2*k_theta_3 + k_theta_4)/6;

  *w = new_w;
  *theta = new_theta;

  return t+h;
}

double periodo (double theta_0){
  double theta = theta_0, w = 0, t = 0;
  int inversoes = 0;

  double t1, t2, w1, w2;

  while( inversoes < 20 ) {
    w1 = w;
    t1 = t;

    t = pendulo( t , pow(10.0,-3) , &theta, &w );

    if( w1*w < 0 || ( w1*w == 0 && ( w1 > w ) ) ) {
      inversoes++;
    }

    w2 = w;
    t2 = t;
  }

  return (2*(t1+(fabs(w1)/(fabs(w1)+fabs(w2))*(t2-t1))))/(20);
}

double periodo_simplificado (double theta0){
  return 2*PI*sqrt(15.0/10.0);
}
