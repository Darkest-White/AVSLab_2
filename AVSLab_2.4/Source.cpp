#include <iostream>
#include <omp.h>
using namespace std;

int main() 
{
    system("chcp 1251");
    omp_set_num_threads(3);

#pragma omp parallel shared(cout)
    {
#pragma omp master
        {
            std::cout << "������� �����, ����: " << omp_get_thread_num() << std::endl;
        }

#pragma omp barrier

        std::cout << "������, ����: " << omp_get_thread_num() << std::endl;

#pragma omp master
        {
            std::cout << "������� �����, ����: " << omp_get_thread_num() << std::endl;
        }

#pragma omp barrier

        std::cout << "��������, ����: " << omp_get_thread_num() << std::endl;

#pragma omp master
        {
            std::cout << "������� �����, ����: " << omp_get_thread_num() << std::endl;
        }

#pragma omp barrier

        std::cout << "�����, ����: " << omp_get_thread_num() << std::endl;

#pragma omp master
        {
            std::cout << "������� �����, ����: " << omp_get_thread_num() << std::endl;
        }
    }

    return 0;
}