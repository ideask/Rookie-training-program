#include "mergeSortBU.h"

template <typename T>
void __merge(T *arr, int l, int mid, int r)
{
    T aux[r-l+1];
    for(int i = l; i <= r; i++)
    {
        aux[i-l] = arr[i];
    }
    int i = l;
    int j = mid + 1;
    for(int k = l; k <= r; k++)
    {
        if(i > mid){arr[k] = aux[j - l]; j++;}
        else if(j > r){arr[k] = aux[i-l]; i++;}
        else if(aux[i-l] > aux[j-l]){arr[k] = aux[j-l]; j++;}
        else {arr[k] = aux[i-l]; i++;}
    }
}

template <typename T>
void mergeSortBU(T *arr, int amount)
{
    for(int i = 1; i <=amount; i+=i)
    {
        for(int j = 0; j + i < amount; j += i + i)
        {
            __merge(arr, j, j+i-1, min(j+i+i-1, amount - 1));
        }
    }
}

int main()
{
    #define FROM 1
    #define TO 100
    #define AMOUNT 10000
    int *arr = sortTestHelper::genRandomArr(FROM, TO, AMOUNT);
    sortTestHelper::sortBenchMark("MergeSort Bottom Up", mergeSortBU, arr, AMOUNT);
    return 0;
}