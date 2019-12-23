#include "SelectionSort.h"

void SelectionSort(int* arr, int amount)
{
    for(int i = 0; i < amount; i++)
    {
        int min_index = i;
        for(int j = i + 1; j < amount; j++)
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
    int* darr = SortTestTool::genTestArray(1, 100, 1000);
    SortTestTool::printArray(darr, 1000);
    SelectionSort(darr, 1000);
    assert(SortTestTool::isSorted(darr, 1000));
    SortTestTool::printArray(darr, 1000);

}