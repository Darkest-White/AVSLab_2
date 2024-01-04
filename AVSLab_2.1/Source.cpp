#include<iostream>
#include<omp.h>
using namespace std;

int main(int argc, char* argv[])
{
	const int ITER = 1000000000;
	double number1 = 12, number2 = 13;

	double start = omp_get_wtime();
	for (int i = 0; i < ITER; i++)
	{
		double result = number1 * number2;
	}
	double end = omp_get_wtime();
	cout << end - start << endl;

	start = omp_get_wtime();
#pragma omp parallel num_threads(2)
	{
		for (int i = 0; i < ITER; ++i)
		{
			double result = number1 * number2;
		}
	}
	end = omp_get_wtime();
	cout << end - start << endl;
}