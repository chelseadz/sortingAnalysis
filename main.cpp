#include <iostream>
#include "sorting.h"
#include <sys/time.h>
#include "arrays.h"
#include <stdlib.h>


//firma para algoritmos de ordenacion

typedef void (sorter)(int[],unsigned long int,unsigned long int,unsigned long int);

/** \brief Ordena la cantidad de renglones de longitud len que se tienen en la matriz arrs
 *  \param func algoritmo que se utilizara para ordenar
 *  \return la media de tiempo utilizado para ordenar los arreglos
 */
template <typename T>
double trySort(sorter func, T arr[], int len)
{
    ///////////////////////////////////////////////
    // MEDICIÓN

    struct timeval inicio, fin;
    gettimeofday(&inicio, NULL);

    func(arr,0,len,len);

    gettimeofday(&fin, NULL);
    //printMat(arrs, cant, len);

    return (double)(fin.tv_sec - inicio.tv_sec) + (double)(fin.tv_usec - inicio.tv_usec) / 1000000;;
}


#include <cmath>

void trySortByLen(unsigned long int len)
{
    int cantAlgorithms = 3;

    //double* comparison = new double [cantAlgorithms];

    int* arr0 = new int[len]();
    int* arr1 = new int[len]();
    int* arr2 = new int[len]();
    double* timesM = new double[cantAlgorithms]();
    double* timesI = new double[cantAlgorithms]();
    double* timesS = new double[cantAlgorithms]();

    //caso promedio
    randomArray(arr0,len);
    copyArr(arr0,arr1,len);
    copyArr(arr0,arr2,len);
/*
    printArr(arr0,len);
    std::cout << std::endl;
    printArr(arr1,len);
    std::cout << std::endl;
    printArr(arr2,len);
    std::cout << std::endl;
*/
    timesM[0] = trySort(mergeSort,arr0,len);
    timesI[0] = trySort(insertionSort,arr1,len);
    timesS[0] = trySort(selectionSort,arr2,len);

    //peor caso
    inverseArray(arr0,len);
    copyArr(arr0,arr1,len);
    copyArr(arr0,arr2,len);

    timesM[1] = trySort(mergeSort,arr0,len);
    timesI[1] = trySort(insertionSort,arr1,len);
    timesS[1] = trySort(selectionSort,arr2,len);

    //mejor caso
    sortedArray(arr0,len);
    copyArr(arr0,arr1,len);
    copyArr(arr0,arr2,len);

    timesM[2] = trySort(mergeSort,arr0,len);
    timesI[2] = trySort(insertionSort,arr1,len);
    timesS[2] = trySort(selectionSort,arr2,len);

    std::cout << "\t promedio \tpeor  \tmejor \t len: " << len << std::endl;
    std::cout << "Merge: ";
    printArr(timesM,cantAlgorithms);
    std::cout << "Insertion";
    printArr(timesI,cantAlgorithms);
    std::cout << "Selection";
    printArr(timesS,cantAlgorithms);
    std::cout << std::endl;


    delete[] arr0;
    delete[] arr1;
    delete[] arr2;
    delete[] timesM;
    delete[] timesI;
    delete[] timesS;

    //delete[] comparison;
}


int main()
{
    unsigned long int len =1000;
    for(int i = 0; i<10; i++){
        trySortByLen(len);
        len = len+1000;

    }

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

