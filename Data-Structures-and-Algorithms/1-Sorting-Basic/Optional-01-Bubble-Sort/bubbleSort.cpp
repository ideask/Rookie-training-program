#include "bubblesort.h"
template <typename T>
void selectionSort(T *arr, int amount)
{
    for(int i = 0; i < amount; i++)
    {
        int min_index = i;
        for(int j = i; j < amount; j++)
        {
            if(arr[min_index] > arr[j])
                min_index = j;
        }
        swap(arr[min_index],arr[i]);
    }
}
template <typename T>
void bubbleSort(T *arr, int amount)
{
    for(int i = amount - 1; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}
template <typename T>
void insertionSort(T *arr, int amount)
{
    for(int i = 1; i < amount; i++)
    {
        for(int j = i; j > 0 && arr[j] < arr[j-1] ; j--)
        {
            swap(arr[j], arr[j-1]);
        }
    }
}

template <typename T>
void insertionSortAdvance(T *arr, int amount)
{
    for(int i = 1; i < amount; i++)
    {
        T tempValue = arr[i];
        int j;
        for(j = i; j > 0 && tempValue < arr[j-1] ; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = tempValue;
    }
}

int main()
{
    int *Arr1 = sortHelper::genRanArr(1,1000,10000);
    int *Arr2 = sortHelper::cpyArr(Arr1,10000);
    int *Arr3 = sortHelper::cpyArr(Arr1,10000);
    int *Arr4 = sortHelper::cpyArr(Arr1,10000);
    sortHelper::sortBenchMark("bubbleSort Algorithm", bubbleSort ,Arr1,10000);
    sortHelper::sortBenchMark("insertionSort Algorithm", insertionSort ,Arr2,10000);
    sortHelper::sortBenchMark("insertionSort Algorithm Advance", insertionSortAdvance ,Arr3,10000);
    sortHelper::sortBenchMark("selectionSort Algorithm ", selectionSort ,Arr4,10000);
    return 0;
}