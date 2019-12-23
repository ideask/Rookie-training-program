#include "shellSort.h"
template <typename T>
void shellSort(T *arr, int amount, int gap)
{
    for(int i = gap; i > 0; i = i/2)
    {
        for(int j = i; j < amount; j++)
        {
            for(int k = j-i; k >= 0 && arr[k] > arr[k+i]; k-=i)
            {
                swap(arr[k] ,arr[k+i]);
            }
        }
    }
}

int main()
{
    int *arr = sortTestTool::genTestArr(1,10,10);
    sortTestTool::printArr(arr,10);
    shellSort(arr,10,10/2);
    sortTestTool::printArr(arr,10);
    // sortTestTool::sortSpendTime("shell sort algorithm",shellSort,arr,10,10/2);
    return 0;
}