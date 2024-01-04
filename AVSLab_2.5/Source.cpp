#include <iostream>
#include <omp.h>
using namespace std;

int main() 
{
    system("chcp 1251");
    int n = 10;

    cout << "ѕоследовательна€ область, значение переменной n: " << n << endl;

#pragma omp parallel num_threads(2) private(n)
    {
#pragma omp barrier
        cout << "ѕараллельна€ область, нить: " << omp_get_thread_num() << ", значение переменной n: " << n << endl;

        n = omp_get_thread_num();

#pragma omp barrier
        cout << "ѕараллельна€ область, нить: " << omp_get_thread_num() << ", новое значение переменной n: " << n << endl;
    }

    cout << "ѕоследовательна€ область, значение переменной n: " << n << endl;

    return 0;
}