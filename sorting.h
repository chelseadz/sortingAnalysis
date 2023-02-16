#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

#include <array>

template <typename T>
void Swap(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void insertionSort (T datos[], int beg, int fin)
{
    for (int i=1 ; i<fin ; i++)
    {
        int s=i;
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
void SelectionSort (T datos[], int beg, int fin)
{
    int aux=fin-1;
    for (int i=0 ; i<aux ; i++)
    {
        int minimo=i;
        for (int j=i+1 ; j<fin ; j++)
        {
            if (datos[j]<datos[minimo]) minimo = j;
        }
        Swap(&datos[i], &datos[minimo]);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void QuickSort (T datos[], int izq, int der)
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
void Merge(T arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    T* L = new T[n1];
    T* R = new T[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

template <typename T>
void mergeSort(T arr[], int beg, int fin) {
    if (beg < fin) {
        int m = beg + (fin - beg) / 2;
        mergeSort(arr, beg, m);
        mergeSort(arr, m + 1, fin);
        Merge<T>(arr, beg, m, fin);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif // SORTING_H_INCLUDED
