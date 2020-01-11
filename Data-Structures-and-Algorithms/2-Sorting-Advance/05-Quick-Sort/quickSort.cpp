#include "quickSort.h"

template <typename T>
int partition(T *arr, int l, int r)
{
    T val = arr[l];
    // arr[l+1, j]  arr[j+1,i)
    int i ,j = l;
    for(i = l+1; i <= r; i++)
    {
        if(arr[i] < val)
        {
            j++;
            swap(arr[j], arr[i]);
            
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
void quickSort(T *arr, int amount)
{
    __quickSort(arr, 0, amount-1);
}

int main()
{
    int *arr = sortTestHelper::genRandomArr(1,10,10000);
    sortTestHelper::sortBenchMark("Quick Sort", quickSort, arr, 10000);
    return 0;
}