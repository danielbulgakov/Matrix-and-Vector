#include <iostream>
#include "TVector.h"
#include "TMatrix.h"
#include <ctime> 

int StandartMatrix(size_t size) {
    int** a = new int* [size];
    int** b = new int* [size];
    int** c = new int* [size];

    for (size_t i = 0; i < size; i++) {
        a[i] = new int[size];
        b[i] = new int[size];
        c[i] = new int[size];
    }

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++)
        {
            a[i][j] = 0;
            b[i][j] = 0;
            c[i][j] = 0;
        }
    }

    for (size_t i = 0; i < size; i++) {
        for (size_t j = i; j < size; j++)
        {
            a[i][j] = (i * 10 + 18) * 2;
            b[i][j] = (i * 10 + 7) * 2;
            c[i][j] = 0;
        }
    }
    

    int start, end;

    start = clock();
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            for (int k = 0; k < size; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
    end = clock();

    /*for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++)
        {
            std::cout << c[i][j] << " ";
        }
        std::cout << std::endl;
    }*/

    return end - start;


}

int OurMatrix(size_t size) {
    TMatrix<int> a(size), b(size), c(size);
    int i, j;
    for (i = 0; i < size; i++)
        for (j = 0; j < size - i; j++)
        {
            a[i][j] = (i * 10 + 18) * 2;
            b[i][j] = (i * 10 + 7) * 2;
        }
    int start, end;
    start = clock();
    c = a * b;
    end = clock();
    //std::cout << a * b;
    return end - start;

}

void main()
{
    //TMatrix<int> a(5), b(5), c(5);
    //int i, j;
    //setlocale(LC_ALL, "Russian");
    //std::cout << "Тестирование программ поддержки треугольных матриц" << std::endl;
    //std::cout << "Введите матрицу a =" << std::endl;
    //std::cin >> a;
    //for (i = 0; i < 5; i++)
    //    for (j = 0; j < 5-i; j++)
    //    {
    //        a[i][j] = (i * 10 + 18) * 100;
    //        b[i][j] = (i * 10 + 7) * 100;
    //    }

    //c = a + b;
    //std::cout << "Matrix a = " << std::endl << a << std::endl;
    //std::cout << "Matrix b = " << std::endl << b << std::endl;
    //std::cout << "Matrix c = a + b" << std::endl << c << std::endl;
    //std::cout << "Matrix a * b" << std::endl << (a * b) << std::endl;
    //std::cout << "Matrix b - a" << std::endl << (b - a) << std::endl;

    size_t size = 5000;

    std::cout << std::endl << std::endl << std::endl;
    std::cout << "Standart Matrix time  for  size = " << size << "     = " << StandartMatrix(size)  << "msec" << std::endl;
    std::cout << "Our Matrix time  for  size = " << size << "     = " << OurMatrix(size) << "msec" << std::endl;
}