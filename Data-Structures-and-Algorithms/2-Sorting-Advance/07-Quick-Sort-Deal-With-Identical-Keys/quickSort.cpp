#include "quickSort.h"

template <typename T>
int partition(T *arr, int l, int r)
{
    int i = l+1, j= r;
    swap(arr[l], arr[rand() % (r - l) + l]);
    T val = arr[l];
    while(true)
    {
        while(i <=r && arr[i] < val){i++;}
        while(j >= l+1 && arr[j] > val){j--;}
        if(i > j)
            break;
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    swap(arr[l],arr[j]);
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
void quickSortDealWithIdenticalKey(T *arr, int amount)
{
    __quickSort(arr, 0, amount-1);
}

int main()
{
    int *arr = sortTestHelper::genRandomArr(1,10,10);
    sortTestHelper::arrPrint(arr,10);
    quickSortDealWithIdenticalKey(arr,10);
    sortTestHelper::arrPrint(arr,10);
    // sortTestHelper::sortBenchMark("quick Sort Deal With Identical Key", quickSortDealWithIdenticalKey, arr, 10);
    return 0;
}