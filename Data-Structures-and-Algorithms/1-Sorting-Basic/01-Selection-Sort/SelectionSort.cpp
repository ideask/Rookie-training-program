#include "SelectionSort.h"

void selection_sort(int *arr, int nums)
{
    for(int i=0; i < nums; i++)
    {
        int min_index = i;
        for(int j = i+1; j < nums; j++)
        {
            if(arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

int main()
{
    int array[10] = {2,3,4,1,2,3,5,6,5,8};
    cout << "origin:";
    for(int i=0; i < 10; i++)
    {
        cout << array[i];
    }
    cout << endl;
    selection_sort(array, 10);
    cout << "sorted:";
    for(int i=0; i < 10; i++)
    {
        cout << array[i];
    }
    cout << endl;
    return 0;
}