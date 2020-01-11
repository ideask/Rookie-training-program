#include "mergeSort.h"

/* 
    left_arr[left,middle]    i 
    right_arr[middle+1, right]  j
    k arr
*/
template <typename T>
void __sort(T *arr, int left, int right, int middle)
{
    T aux[right - left + 1];
    for(int i = left; i <= right; i++)
    {
        aux[i - left] = arr[i];
    }
    int i = left, j = middle + 1;
    for(int k = left; k <= right; k++)
    {
        if(i > middle){arr[k] = aux[j - left]; j++;}
        else if(j > right){arr[k] = aux[i - left]; i++;}
        else if(aux[i - left] < aux[j - left]){arr[k] = aux[i - left]; i++;}
        else {arr[k] = aux[j - left]; j++;}
    }

}
template <typename T>
void __mergeSort(T *arr, int left, int right)
{
    if(left >= right)
        return;
    int middle = (right + left) / 2;
    __mergeSort(arr, left, middle);
    __mergeSort(arr, middle + 1, right);
    __sort(arr, left, right, middle);

}
template <typename T>
void mergeSort(T *arr, int amount)
{
    __mergeSort(arr, 0, amount - 1);
}

int main()
{
    int *arr = sortHelper::genRandArr(1,1000,100000);
    int *narr = sortHelper::genNearlySortArr(100000, 5);
    sortHelper::benchMark("Merge Sort Algorithm random test ", mergeSort, arr, 100000);
    sortHelper::benchMark("Merge Sort Algorithm nearly sorted test ", mergeSort, narr, 100000);
    return 0;
}