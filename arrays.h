#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED


#include <stdlib.h>
#include <random>
#include <chrono>

template <typename T>
void randomArray(T arr[], int len) {
    std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<T> dist(1, 100);
    for(int i = 0; i<len; i++)
    {
        arr[i] = dist(gen);
    }
}

template <typename T>
void sortedArray(T arr[], int len) {
    for(int i = 0; i<len; i++)
    {
        arr[i] = i;
    }
}

template <typename T>
void inverseArray(T arr[], int len) {
    len = len-1;
    for(int i = len; i>=0; i--)
    {
        arr[i] = i;
    }
}

//********************************************************************************************

template <typename T>
T** randomArrays(int len, int cant) {
    T** ls = new T* [cant];
    ls[0] = new T[cant * len];

    for (int i = 1; i < cant; i++) ls[i] = ls[i - 1] + len;

    for(int i = 0; i<cant; i++)
    {
        randomArray<T>(ls[i], len);
    }
    return ls;
}

template <typename T>
void DestruirLs(T** ls)
{
    delete[] ls[0];
    delete[] ls;
    ls = NULL;
}


#endif // ARRAYS_H_INCLUDED
