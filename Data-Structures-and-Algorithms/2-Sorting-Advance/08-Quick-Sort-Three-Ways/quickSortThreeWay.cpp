#include "quickSortThreeWay.h"

template <typename T>
void insertionSort(T *arr, int l, int r)
{
    for(int i = 1; i <= r; i++)
    {
        T val = arr[i];
        int j;
        for(j = i; arr[j - 1] > val && j > 0; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = val;
    }
}

template <typename T>
void __quickSort(T *arr, int l, int r)
{
    if(r-l < 15)
    {
        insertionSort(arr,l,r);
        return;
    }
    //partition three ways
    swap(arr[l], arr[rand() % (r -l) + l]);
    T val = arr[l];
    int lt = l;
    int gt = r + 1;
    int i = l + 1;
    while(i < gt)
    {
        if(arr[i] > val)
        {
            swap(arr[gt-1], arr[i]);
            gt--;
        }
        else if(arr[i] == val)
        {
            i++;
        }
        else
        {
            swap(arr[lt+1], arr[i]);
            lt++;
            i++;   
        }
    }
    swap(arr[l], arr[lt]);
    __quickSort(arr, l, lt);
    __quickSort(arr, gt, r);

}

template <typename T>
void quickSortThreeWay(T *arr, int amount)
{
    srand(time(NULL));
    __quickSort(arr, 0, amount-1);
}

int main()
{
    int *arr = sortTestHelper::genRandomArr(1,1000,100000);
    sortTestHelper::sortBenchMark("quickSortThreeWay", quickSortThreeWay, arr, 100000);
    return 0;
}