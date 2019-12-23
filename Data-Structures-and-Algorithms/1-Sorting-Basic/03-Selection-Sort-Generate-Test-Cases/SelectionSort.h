#ifndef __SELECTION_SORT__
#define __SELECTION_SORT__
#include <iostream>
#include <cassert>
#include <ctime>
using namespace std;
namespace SortTestTool
{
    int* genTestArray(int from, int to, int amount)
    {
        assert(to >= from);
        int* array = new int[amount];
        srand(time(NULL));
        for(int i = 0; i < amount; i++)
        {
            array[i] = rand() % (to - from + 1) + from;
        }
        return array;
    }
    template<typename T>
    void printArray(T* arr, int amount)
    {
        for(int i =0; i < amount ; i++)
        {
            cout << arr[i] << ",";
        }
        cout << endl;
    }
    template<typename T>
    bool isSorted(T* arr, int amount)
    {
        for(int i=0; i< amount - 1; i++)
        {
            if(arr[i] > arr[i+1])
                return false;
        }
        return true;
    }
};

#endif