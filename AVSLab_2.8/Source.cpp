#include <iostream>
#include <omp.h>
using namespace std;

int main() 
{
    int sum_of_thread_nums = 0;

#pragma omp parallel reduction(+:sum_of_thread_nums)
    {
        sum_of_thread_nums += omp_get_thread_num();
#pragma omp barrier
        cout << "Thread " << omp_get_thread_num() << ", Sum: " << sum_of_thread_nums << endl;
    }

    cout << "Final sum: " << sum_of_thread_nums << endl;

    return 0;
}