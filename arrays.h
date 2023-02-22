#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED


#include <stdlib.h>
#include <random>
#include <chrono>
#include <iomanip>


/**
 *  \brief imprime un arreglo de longitud len
 */
template <typename T>
void printArr(T arr[], unsigned long int len)
{
    std::cout << std::fixed;
    for(unsigned long int i = 0; i<len; i++)
    {
        std::cout << " " << std::setprecision(9) << arr[i] << ",";
    }
    std::cout << std::endl;

}

/**
 *  \brief imprime cant arreglos de longitud len, en otras palabras una matriz
 */
template <typename T>
void printMat(T *arr, int cant, int len)
{
    for (int i = 0 ; i < cant ; i++)
    {
       printArr(arr[i],len);
    }
}

/** \brief  Reserva memoria dinámica para una matriz (cant x len)
 *  \param  cant:   cantidad de renglones
 *          len:    cantidad de columnas
 *  \return la media de tiempo utilizado para ordenar los arreglos
 */
template <typename T>
T** reserveMatrix(int cant, unsigned long int len) {
    T** ls = new T* [cant];
    ls[0] = new T[cant * len];

    for (int i = 1; i < cant; i++) ls[i] = ls[i - 1] + len;
    return ls;
}

template <typename T>
void deleteMatrix(T** ls)
{
    delete[] ls[0];
    delete[] ls;
    ls = NULL;
}

template <typename T>
void randomArray(T arr[], unsigned long int len) {
    std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<T> dist(1, 100);
    for(unsigned long int i = 0; i<len; i++)
    {
        arr[i] = dist(gen);
    }
}

template <typename T>
void sortedArray(T arr[], unsigned long int len) {
    for(unsigned long int i = 0; i<len; i++)
    {
        arr[i] = i;
    }
}

template <typename T>
void inverseArray(T arr[], unsigned long int len) {
    len = len-1;

    for(unsigned long int i = len; i>0; i= i-1)
    {
        arr[i] = i;
    }
}

template <typename T>
void copyArr(T arr[], T newAr[], unsigned long int len)
{
    for (unsigned long int j = 0 ; j < len ; j++)
    {
       newAr[j] = arr[j];
    }
}

template <typename T>
T** copyMat(T** arrs, int cant, unsigned long int len)
{
    //crear matriz
    T** newM = new T* [cant];
    newM[0] = new T[cant * len];

    for (int i = 1; i < cant; i++) newM[i] = newM[i - 1] + len;

    // copiar matrices
    for (int i = 0 ; i < cant ; i++)
    {
        copyArr(arrs[i], newM[i], len);
    }
    return newM;
}



//********************************************************************************************

template <typename T>
T** randomArrays(unsigned long int len, int cant) {
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
T** sortedArrays(unsigned long int len, int cant) {
    T** ls = new T* [cant];
    ls[0] = new T[cant * len];

    for (int i = 1; i < cant; i++) ls[i] = ls[i - 1] + len;

    for(int i = 0; i<cant; i++)
    {
        sortedArray<T>(ls[i], len);
    }
    return ls;
}

template <typename T>
T** inverseArrays(unsigned long int len, int cant) {
    T** ls = new T* [cant];
    ls[0] = new T[cant * len];

    for (int i = 1; i < cant; i++) ls[i] = ls[i - 1] + len;

    for(int i = 0; i<cant; i++)
    {
        inverseArray<T>(ls[i], len);
    }
    return ls;
}




#endif // ARRAYS_H_INCLUDED
