///////////////
// lsm1d.cpp //
///////////////

// y = a_{0} + a_{1} x

#include <stdio.h>

/////////////////////////////////
// least squares method -> lsm //
/////////////////////////////////
void lsm(double x[], double y[], int N, double *a0, double *a1)
{
	int i;
	double A00 = 0.0, A01 = 0.0, A02 = 0.0, A11 = 0.0, A12 = 0.0;
	
	for (i=0; i<N; i++)
	{
		A00 += 1.0;
		A01 += x[i];
		A02 += y[i];
		A11 += x[i] * x[i];
		A12 += x[i] * y[i];
	}
	*a0 = (A02*A11 - A01*A12) / (A00*A11 - A01*A01);
	*a1 = (A00*A12 - A01*A02) / (A00*A11 - A01*A01);
}

int main()
{
	double x[] = {0.50, 1.00, 1.50, 2.00, 2.50};
	double y[] = {80.0, 110.0, 133.3, 165.0, 196.0};
	double a0 = 0.0, a1 = 0.0;
	
	///////////////
	// Data size //
	///////////////
	int N = sizeof(x) / sizeof(x[0]);
	
	///////////////////
	// Calculate lsm //
	///////////////////
	lsm(x, y, N, &a0, &a1);
	
	printf("a0 = %f\na1 = %f\n", a0, a1);
	
	return 0;
}
