#include "compare.h"
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
        swap(arr[i], arr[min_index]);
    }
}

template <typename T>
void insertionSort(T *arr, int amount)
{
    for(int i = 1; i < amount; i++)
    {
        for(int j = i; j > 0 && arr[j] < arr[j-1]; j--)
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
        int j;
        T temp_value = arr[i];
        for(j = i; j > 0 && temp_value < arr[j - 1]; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp_value;
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
void shellSort(T *arr, int amount)
{
    for(int gap = amount/2; gap > 0; gap = gap / 2)
    {
        for(int i = gap; i < amount; i ++)
        {
            for(int j = i - gap; j >= 0 && arr[j] > arr[gap + j]; j -= gap)
            {
                swap(arr[j], arr[j + gap]);
            }
        }
    }
}

int main()
{
    int amount = 100000;
    int from = 1, to = 100;
    int swap_times = 6;
    int *arr1 = sortHelper::genRandArr(from, to, amount);
    int *arr2 = sortHelper::cpyArr(arr1, amount);
    int *arr3 = sortHelper::cpyArr(arr1, amount);
    int *arr4 = sortHelper::cpyArr(arr1, amount);
    int *arr5 = sortHelper::cpyArr(arr1, amount);

    int *Narry1 = sortHelper::genNearlySortArr(amount, swap_times);
    int *Narry2 = sortHelper::cpyArr(Narry1, amount);
    int *Narry3 = sortHelper::cpyArr(Narry1, amount);
    int *Narry4 = sortHelper::cpyArr(Narry1, amount);
    int *Narry5 = sortHelper::cpyArr(Narry1, amount);

    cout << "Random array test:" << endl;
    sortHelper::benchMark("Selection Sort Algorithm", selectionSort,arr1,amount);
    sortHelper::benchMark("Insertion Sort Algorithm", insertionSort,arr2,amount);
    sortHelper::benchMark("Insertion Sort Advance Algorithm", insertionSortAdvance,arr3,amount);
    sortHelper::benchMark("Bubble Sort Algorithm", bubbleSort,arr4,amount);
    sortHelper::benchMark("Shell Sort Algorithm", shellSort,arr5,amount);

    cout << "Nearly sorted array test:" << endl;
    sortHelper::benchMark("Selection Sort Algorithm", selectionSort,Narry1,amount);
    sortHelper::benchMark("Insertion Sort Algorithm", insertionSort,Narry2,amount);
    sortHelper::benchMark("Insertion Sort Advance Algorithm", insertionSortAdvance,Narry3,amount);
    sortHelper::benchMark("Bubble Sort Algorithm", bubbleSort,Narry4,amount);
    sortHelper::benchMark("Shell Sort Algorithm", shellSort,Narry5,amount);

    return 0;
}