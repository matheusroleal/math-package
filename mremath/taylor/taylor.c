# import "taylor.h"

double cos2 (double x){
	// cos^2(0) -2 cos(0) sin(0) (x - 0)

	return 1.0;
}

double cos2_rmax (double x){
	double f;

	// ( 2(sin(PI) - cos^2(PI))(x - 0)^3 ) / 6 
	f = ( 2.0 * (0.0 - 1.0) / 6.0 )*(x - 0.0)*(x - 0.0)*(x - 0.0);

	return f;
}

double raiz (double x){
	double f;

	// sqrt(1) + 1/(2 sqrt(1))(x - 1) - 1/(4 x^(3/2)) (x - 1)^2
	f = 1.0 + ( ( ( (1.0 / 2.0) * (1.0) ) * (x - 1.0) ) - ((1.0 / 4.0) * (1.0) ) ) * (x - 1.0) * (x - 1.0);

	return f;
}

double raiz_rmax (double x){
	double f;

	// (3/(8 2^(5/2)))(x - 1)^4 ) / 24 
	// 2^(5/2) = 5.656854249492380195206754896838792314278687501507792292706
	f = ((3.0/(8.0 * 5.656854249492380195206754896838792314278687501507792292706))) * ((x - 1)*(x - 1)*(x - 1)*(x - 1)) / 24;

	return f;
}
