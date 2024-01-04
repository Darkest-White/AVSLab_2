#include <iostream>
#include <omp.h>
using namespace std;

int main() 
{
    int total_threads = 0;

#pragma omp parallel reduction(+:total_threads)
    {
        total_threads += 1;
        cout << "Thread " << omp_get_thread_num() << ", Total threads: " << total_threads << endl;
    }

    cout << "Total threads: " << total_threads << endl;

    return 0;
}