#include "quickSortNearlyOrdered.h"

template <typename T>
int partition2(T *arr, int l, int r)
{
    swap(arr[l], arr[rand() % (r-l) + l]);
    T val = arr[l];
    int j = l;
    for(int i = l+1; i <= r; i++)
    {
        if(arr[i] < val)
        {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

template <typename T>
void __quickSort2(T *arr, int l, int r)
{
    if(l >= r)
        return;
    int p = partition2(arr, l, r);
    __quickSort2(arr, l, p-1);
    __quickSort2(arr, p+1, r);
}


template <typename T>
void quickSortNearlyOrdered(T *arr, int amount)
{
    __quickSort2(arr, 0, amount-1);
}


template <typename T>
int partition(T *arr, int l, int r)
{
    T val = arr[l];
    int j = l;
    for(int i = l+1; i <= r; i++)
    {
        if(arr[i] < val)
        {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

template <typename T>
void __quickSort(T *arr, int l, int r)
{
    if(l >= r)
        return;
    int p = partition(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}

template <typename T>
void quickSortBase(T *arr, int amount)
{
    __quickSort(arr, 0, amount-1);
}

int main()
{
    int *arr = sortTestHelper::genNearlyArr(1000,0);
    int *arrcpy = sortTestHelper::arrCpy(arr, 1000);

    sortTestHelper::sortBenchMark("Quick Sort Base", quickSortBase, arrcpy, 1000);
    sortTestHelper::sortBenchMark("Quick Sort Nearly Ordered", quickSortNearlyOrdered, arr, 1000);
    return 0;
}