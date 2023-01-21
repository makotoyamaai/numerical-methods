////////////
// gs.cpp //
////////////

// Solve Ax = b by using Gauss-Seidel Method 

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

///////////////////
// Inner product //
///////////////////
inline double IP(vector<double> &a, vector<double> &b, int &size)
{
	double value = 0;
	int i;
	for (i=0; i<size; i++)
	{
		value += a[i] * b[i];
	}
	return value;
}

/////////////////////////
// Gauss-Seidel method //
/////////////////////////
inline void GS(vector<vector<double>> &A, vector<double> &x, vector<double> &b, int &size, double &eps)
{
	int i, j;
	double in, sum, max;
	
	for (j=0; j<1000000; j++)
	{
		max = 0.0;
		for (i=0; i<size; i++)
		{
			in = x[i];
			x[i] = (b[i] - (IP(A[i], x, size) - A[i][i] * x[i])) / A[i][i];
			if (max<abs(in - x[i]))
			{
				max = abs(in - x[i]);
			}
		}
		if (eps>max)
		{
			break;
		}
	}
}

int main()
{
	int size = 3;
	int i;
	double eps = pow(2.0, -50);
	double in, max;
	vector<double> b(size, 0.0);
	vector<double> x(size, 0.0);
	vector<vector<double>> A(size, (vector<double> (size, 0.0)));
	
	////////////
	// Ax = b //
	////////////
	//
	// / A[0][0] A[0][1] A[0][2] \   / x1 \   / b[0] \
	// | A[1][0] A[1][1] A[1][2] | * | x2 | = | b[1] |
	// \ A[2][0] A[2][1] A[2][2] /   \ x3 /   \ b[2] /
	//
	A[0][0] = 3; A[0][1] = 2; A[0][2] = 1;
	A[1][0] = 1; A[1][1] = 4; A[1][2] = 1;
	A[2][0] = 2; A[2][1] = 2; A[2][2] = 5;
	b[0] = 10; b[1] = 12; b[2] = 21;
	
	GS(A, x, b, size, eps);
	
	for (i=0; i<size; i++)
	{
		cout << x[i] << endl;
	}
}
