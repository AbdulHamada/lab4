// Lab 4  - deriv.cpp : Defines the entry point for the console application.
//Visual Studio

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;


void print(double* p, const int N, const double dx, const double xmin)
	{

	for (int i = 0; i<N; i++)
		cout << i*dx + xmin << "\t" << p[i] << endl;
	}
// First step //
void fill(double* arr_x, const int N, const double dx, const double xmin)
	{
	double x;
	x = xmin;
	for (int i = 0; i<N; i++)
		{
		arr_x[i] = exp(-pow(x, 2));
		x = x + dx;
		}
	}
// Second step // 
void deriv_1(double* p, const int N, const double dx)
	{
		double f_1, f0;
		f_1 = 0;
		f0 = p[0];
		for (int i = 0; i<N - 1; i++)
		{
			p[i] = (p[i + 1] - f_1) / (2 * dx);
			f_1 = f0;
			f0 = p[i + 1];
		}
		p[N - 1] = (-f_1) / (2 * dx);
}

int main(){
	const int N = 256;
	double p[N];
	const double xmax = 15;
	const double xmin = -15;
	const double dx = (xmax - xmin) / (N - 1);

// call to function which fills array p here
	fill(p, N, dx, xmin);

// call to functio which calculates the derivative
	deriv_1(p, N, dx);
	
	print(p, N, dx, xmin);

	cin.get();
	return 0;
}
