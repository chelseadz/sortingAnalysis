#include <iostream>
#include "sorting.h"
#include <sys/time.h>
#include "arrays.h"
#include <stdlib.h>

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
    int cant = 3, len = 7;

    // Crea cant arreglos de longitud len con una distribución uniforme
    int** arrs = randomArrays<int>(len, cant);

    int** arrs1 = arrs;
    int** arrs2 = arrs;
    /*
    std::cout << std::endl;
    printMat(arrs, cant, len);
    std::cout << std::endl;
    printMat(arrs1, cant, len);
    std::cout << std::endl;
    printMat(arrs2, cant, len);
    std::cout << std::endl << std::endl;
    // Obtener tiempos de ordenacion para los mismos arreglos (reservan memoria)
    double* quickTime = trySort(QuickSort, arrs, cant, len);
    */

    std::cout << std::endl;
    printMat(arrs, cant, len);
    std::cout << std::endl;
    printMat(arrs1, cant, len);
    std::cout << std::endl;
    printMat(arrs2, cant, len);
    std::cout << std::endl << std::endl;

    double* mergeTime = trySort(mergeSort, arrs1, cant, len);

    std::cout << std::endl;
    printMat(arrs, cant, len);
    std::cout << std::endl;
    printMat(arrs1, cant, len);
    std::cout << std::endl;
    printMat(arrs2, cant, len);
    std::cout << std::endl << std::endl;

    double* insertionTime = trySort(insertionSort, arrs2, cant, len);
    printMat(arrs2, cant, len);

    std::cout << std::endl;
    printMat(arrs, cant, len);
    std::cout << std::endl;
    printMat(arrs1, cant, len);
    std::cout << std::endl;
    printMat(arrs2, cant, len);
    std::cout << std::endl << std::endl;

/*
    printArr(quickTime,cant);
    delete[] quickTime;
    quickTime = NULL;
*/
    printArr(mergeTime,cant);
    delete[] mergeTime;
    mergeTime = NULL;

    printArr(insertionTime,cant);
    delete[] insertionTime;
    insertionTime = NULL;

    DestruirLs(arrs);
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

