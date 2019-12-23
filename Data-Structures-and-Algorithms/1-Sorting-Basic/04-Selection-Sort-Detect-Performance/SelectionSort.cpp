#include "SelectionSort.h"

void SelectionSort(int *arr, int amount)
{
    for(int i=0; i < amount; i++)
    {
        int min_index = i;
        for(int j = i+1; j<amount; j++)
        {
            if(arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
    }
}

int main()
{
    int *intarr = SortTestTool::genTestArray(1,1000,20000);
    SortTestTool::testSpendTimePrint("selection sort", SelectionSort, intarr, 20000);
    return 0;
}