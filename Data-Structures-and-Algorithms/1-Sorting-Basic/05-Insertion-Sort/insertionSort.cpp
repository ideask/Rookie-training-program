#include "insertionSort.h"
template <typename T>
void insertionSort(T *arr, int amount)
{
    for(int i = 1; i < amount; i++)
    {
        for(int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
        {
            swap(arr[j], arr[j-1]);
        }
    }
}

template <typename T>
void insertionSortAdvance(T *arr, int amount)
{
    for(int i = 0; i<amount; i++)
    {
        T temp_val = arr[i];
        int j ;
        for(j=i; j > 0 && temp_val < arr[j-1]; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = temp_val;
    }
}
template <typename T>
void selectionSort(T *arr, int amount)
{
    for(int i=0; i < amount; i++)
    {
        int min_index = i;
        for(int j = i; j < amount; j++)
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
    cout << "array copy arry test:" <<endl;
    int *test_cparr = sortTestTool::genTestArr(1, 10, 10);
    sortTestTool::printArr(test_cparr, 10);
    int *test_cparrc = sortTestTool::cpyArr(test_cparr, 10);
    sortTestTool::printArr(test_cparrc, 10);

    cout << "random arry test:" <<endl;
    int *test_arr = sortTestTool::genTestArr(1, 100, 40000);
    int *cpy_test_arr = sortTestTool::cpyArr(test_arr, 40000);
    int *cpy_test_arr1 = sortTestTool::cpyArr(test_arr, 40000);
    sortTestTool::sortSpendTime("insertion sort algorithm", insertionSort, test_arr, 40000);
    sortTestTool::sortSpendTime("selection sort algorithm", selectionSort, cpy_test_arr, 40000);
    sortTestTool::sortSpendTime("insertion sort algorithm advance", insertionSortAdvance, cpy_test_arr1, 40000);
    cout << "nearly sorted arry test:" <<endl;
    int *nearlysort = sortTestTool::genNearlySortArr(40000, 5);
    int *nearlysort_cp = sortTestTool::cpyArr(nearlysort, 40000);
    int *nearlysort_cp1 = sortTestTool::cpyArr(nearlysort, 40000);
    sortTestTool::sortSpendTime("insertion sort algorithm", insertionSort, nearlysort, 40000);
    sortTestTool::sortSpendTime("selection sort algorithm", selectionSort, nearlysort_cp, 40000);
    sortTestTool::sortSpendTime("insertion sort algorithm advance", insertionSortAdvance, nearlysort_cp1, 40000);
    return 0;
}