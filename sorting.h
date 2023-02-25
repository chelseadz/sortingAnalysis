#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

#include "arrays.h"

template <typename T>
void Swap(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void insertionSort (T datos[], unsigned long int beg, unsigned long int fin, unsigned long int len)
{
    for (unsigned long int i=1 ; i<fin ; i++)
    {
        unsigned long int s=i;
        int aux=datos[i];
        while ( (s>0) && (datos[s-1]>aux) )
        {
            datos[s]= datos[s-1];
            s--;
        }
        datos[s] = aux;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
void selectionSort(T arr[], unsigned long int beg, unsigned long int fin, unsigned long int n)
{
    unsigned long int i, j, min_idx;
    
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
          if (arr[j] < arr[min_idx])
              min_idx = j;
        }
        // Swap the found minimum element with the first element
        if (min_idx!=i)
           Swap(&arr[min_idx], &arr[i]);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void QuickSort (T datos[], unsigned long int izq, unsigned long int der, unsigned long int len)
{
    int i = izq, j=der;
    int piv = datos[(i+j)/2];
    do
    {
        while (datos[i] < piv && i<der) i++;
        while (datos[j] > piv && j>izq) j--;
        if (i <= j)
        {
            if (i!=j)
            {
                Swap(&datos[i], &datos[j]);
            }
            i++;
            j--;
        }
    }
    while (i < j);
    if (izq < j) QuickSort(datos, izq, j);
    if (i < der) QuickSort(datos, i, der);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
void merge(T arr[], unsigned long int left, unsigned long int middle, unsigned long int right, unsigned long int len) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    T L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1+ j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeSort(T arr[], unsigned long int left, unsigned long int right, unsigned long int len) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, middle,len);
        mergeSort(arr, middle + 1, right, len);

        merge(arr, left, middle, right, len);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif // SORTING_H_INCLUDED
