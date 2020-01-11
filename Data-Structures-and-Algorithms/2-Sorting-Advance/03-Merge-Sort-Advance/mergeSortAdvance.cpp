#include "mergeSortAdvance.h"

template <typename T>
void insertionSortLR(T *arr, int l, int r)
{
    for(int i = l + 1; i <= r; i++)
    {
        T tempVal = arr[i];
        int j;
        for(j = i; j > 0 && tempVal < arr[j - 1]; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = tempVal;
    }
}

template <typename T>
void insertionSortAdvance(T *arr, int amount)
{
    for(int i = 1; i < amount; i++)
    {
        T tempVal = arr[i];
        int j;
        for(j = i; j > 0 && tempVal < arr[j - 1]; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = tempVal;
    }
}

template <typename T>
void __merge(T *arr, int l, int r, int mid)
{
    T *aux = new T[r - l + 1];
    for(int i = l; i <= r; i++)
    {
        aux[i - l] = arr[i];
    }
    int i = l;
    int j = mid + 1;
    for(int k = l; k <= r; k++)
    {
        if(i > mid)                 {arr[k] = aux[j - l]; j++;}
        else if(j > r)              {arr[k] = aux[i - l]; i++;}
        else if(aux[i-l] > aux[j-l]){arr[k] = aux[j-l]; j++;}
        else                        {arr[k] = aux[i-l]; i++;}
    }
}

/*
归并排序初级版本：
*/
template <typename T>
void __mergesort(T *arr, int l, int r)
{
    if(l >= r)
        return;
    int mid = (l + r) / 2;
    __mergesort(arr, l, mid);
    __mergesort(arr, mid+1, r);
    __merge(arr, l, r, mid);
}
template <typename T>
void mergeSortBase(T *arr, int amount)
{
    __mergesort(arr, 0, amount - 1);
}

/*
归并排序
第一个优化改进：
对于将近有序的数组进行排序，效率高
*/
template <typename T>
void __mergesortAdv(T *arr, int l, int r)
{
    if(l >= r)
        return;
    int mid = (l + r) / 2;
    __mergesortAdv(arr, l, mid);
    __mergesortAdv(arr, mid+1, r);
    if(arr[mid] > arr[mid + 1])
        __merge(arr, l, r, mid);
}
template <typename T>
void mergeSortAdvance(T *arr, int amount)
{
    __mergesortAdv(arr, 0, amount - 1);
}

/*
归并排序
第二个优化改进：
归并排序在左右部分的数组达到一定小的时候可以直接使用insertion sort 
因为当数组少到一定程度时候有序的几率很高
*/
template <typename T>
void __mergesortadv2(T *arr, int l, int r)
{
    if(r - l <= 15)
    {
       insertionSortLR(arr, l, r);
       return;
    }
    int mid = (l + r) / 2;
    __mergesort(arr, l, mid);
    __mergesort(arr, mid+1, r);
    if(arr[mid] > arr[mid + 1])
        __merge(arr, l, r, mid);
}

template <typename T>
void mergeSortAdvance2(T *arr, int amount)
{
    __mergesortadv2(arr, 0, amount - 1);
}


int main()
{
    #define AMOUNT 1000000
    #define FROM 1
    #define TO 10000

    int *arr = sortTestHelper::genRandomArr(FROM,TO,AMOUNT);
    int *arrcpy = sortTestHelper::arrCpy(arr, AMOUNT);
    int *arrcpy1 = sortTestHelper::arrCpy(arr, AMOUNT);
    int *arrcpy2 = sortTestHelper::arrCpy(arr, AMOUNT);
    cout << "Random arr test:" << endl;
    // sortTestHelper::sortBenchMark("insertion Sort advance", insertionSortAdvance, arrcpy2, AMOUNT);
    sortTestHelper::sortBenchMark("mergeSort", mergeSortBase, arr, AMOUNT);
    sortTestHelper::sortBenchMark("mergeSort Advance", mergeSortAdvance, arrcpy, AMOUNT);
    sortTestHelper::sortBenchMark("mergeSort Advance2", mergeSortAdvance2, arrcpy1, AMOUNT);//小数组时直接使用insertion sort进行排序


    int *arrN = sortTestHelper::genNearlyArr(AMOUNT, 0);
    int *arrNcpy2 = sortTestHelper::arrCpy(arrN, AMOUNT);
    int *arrNcpy1 = sortTestHelper::arrCpy(arrN, AMOUNT);
    int *arrNcpy3 = sortTestHelper::arrCpy(arrN, AMOUNT);
    int *arrNcpy4 = sortTestHelper::arrCpy(arrN, AMOUNT);
    cout << "Nearly sorted arr test:" << endl;
    sortTestHelper::sortBenchMark("insertion Sort advance", insertionSortAdvance, arrNcpy2, AMOUNT);//这个在有序数组可以退化成O(N)
    sortTestHelper::sortBenchMark("mergeSort base", mergeSortBase, arrNcpy4, AMOUNT);
    sortTestHelper::sortBenchMark("mergeSort Advance", mergeSortAdvance, arrNcpy1, AMOUNT);//这个在有序数组不可以退化成O(N)，最多是O(logN)
    sortTestHelper::sortBenchMark("mergeSort Advance2", mergeSortAdvance2, arrNcpy3, AMOUNT);//小数组时直接使用insertion sort进行排序
    return 0;
}