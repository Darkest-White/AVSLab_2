#include <iostream>
#include <omp.h>
using namespace std;

int main() 
{
    omp_set_num_threads(32);

    double start = omp_get_wtime();
    
#pragma omp parallel
    {

    }

    double end = omp_get_wtime();
    cout << end - start << endl;

    return 0;
}