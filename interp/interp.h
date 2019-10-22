void Chebyshev (int n, double a, double b, double* xi);

void NewtonCoef (int n, double* xi, double (*f) (double), double* bi);

double NewtonAval (int n, double* xi, double* bi, double x);
