#include "SelectionSort.h"
template <typename T>
void SelectionSort(T arr, int amount)
{
    for(int i = 0; i < amount; i++)
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
    Student mark[5] = {{"jason",110.2},{"kay",110.2},{"colin",100},{"may",56.2},{"ben",150.6}};
    SelectionSort(mark, 5);
    for(int i = 0; i < 5; i++)
    {
        cout << mark[i];
    }
    char chr[6] = {'a','d','z','e','f','a'};
    SelectionSort(chr, 6);
    for(int i = 0; i < 6; i++)
    {
        cout << chr[i];
    }
    cout << endl;
    int num[6] = {1,5,6,7,89,8};
    SelectionSort(num, 6);
    for(int i = 0; i < 6; i++)
    {
        cout << num[i];
    }
    cout << endl;
    double dnum[6] = {0.2,0.3,0.1,0.2,0.8,0.9};
    SelectionSort(dnum, 6);
    for(int i =0; i < 6; i++)
    {
        cout << dnum[i];
    }
    cout << endl;
}