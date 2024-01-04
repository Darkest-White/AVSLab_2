#include <iostream>
#include <omp.h>
using namespace std;

int main() 
{
    system("chcp 1251");
    int n = 10;

    cout << "���������������� �������, �������� ���������� n: " << n << endl;

#pragma omp parallel num_threads(2) private(n)
    {
#pragma omp barrier
        cout << "������������ �������, ����: " << omp_get_thread_num() << ", �������� ���������� n: " << n << endl;

        n = omp_get_thread_num();

#pragma omp barrier
        cout << "������������ �������, ����: " << omp_get_thread_num() << ", ����� �������� ���������� n: " << n << endl;
    }

    cout << "���������������� �������, �������� ���������� n: " << n << endl;

    return 0;
}