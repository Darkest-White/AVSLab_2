#include <iostream>
#include <omp.h>

int main() 
{
    int m[5] = {0};

#pragma omp parallel num_threads(2) shared(m)
    {
        m[omp_get_thread_num()] = 1;
    }

    for (int i = 0; i < 5; i++) 
    {
        std::cout << m[i] << " ";
    }

    return 0;
}