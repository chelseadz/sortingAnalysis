#include <iostream>
#include "sorting.h"
#include <sys/time.h>
#include "arrays.h"
#include <stdlib.h>

/**
 *  \brief imprime cant arreglos de longitud len, en otras palabras una matriz
 */
template <typename T>
void printMat(T *arr, int cant, int len)
{
    for (int i = 0 ; i < cant ; i++)
    {
        for (int j = 0 ; j < len ; j++) std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }
}

/**
 *  \brief imprime un arreglo de longitud len
 */
template <typename T>
void printArr(T *arr, int len)
{
    for(int i = 0; i<len; i++)
    {
        std::cout << " " << arr[i] << " " ;
    }
    std::cout << std::endl;

}

typedef void (*f1)(int*,int,int);

/** \brief Ordena la cantidad de renglones de longitud len que se tienen el la matriz arrs
 *  \param func algoritmo que se utilizara para ordenar
 *  \return arreglo con el tiempo de ordenacion para cada renglon
 */
template <typename T>
double* trySort(f1 func, T *arrs, int cant, int len)
{
    ///////////////////////////////////////////////
    // MEDICIÓN

    double* time = new double[cant];
    //printMat(arrs, cant, len);
    for (int i = 0 ; i < cant ; i++)
    {
        struct timeval inicio, fin;
        gettimeofday(&inicio, NULL);

        func(arrs[i],0,len);

        gettimeofday(&fin, NULL);
        time[i] = (double)(fin.tv_sec - inicio.tv_sec) + (double)(fin.tv_usec - inicio.tv_usec) / 1000000;

        //printMat(arrs, cant, len);
    }
    ///////////////////////////////////////////////
    return time;

}

int main()
{
    int cant = 5, len = 1000000000;

    // Crea cant arreglos de longitud len con una distribución uniforme
    int** arrs = randomArrays<int>(len, cant);

    // Obtener tiempos de ordenacion para los mismos arreglos (reservan memoria)
    double* quickTime = trySort(QuickSort, arrs, cant, len);
    double* mergeTime = trySort(mergeSort, arrs, cant, len);
    double* insertionTime = trySort(insertionSort, arrs, cant, len);


    printArr(quickTime,cant);
    printArr(mergeTime,cant);
    printArr(insertionTime,cant);

    //liberar memoria
    DestruirLs(arrs);
    delete[] quickTime;
    quickTime = NULL;
    delete[] mergeTime;
    mergeTime = NULL;
    delete[] insertionTime;
    insertionTime = NULL;
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

