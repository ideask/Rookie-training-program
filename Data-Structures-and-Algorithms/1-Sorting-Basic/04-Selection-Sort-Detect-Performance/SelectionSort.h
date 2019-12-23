#ifndef __SELECTION_SORT__
#define __SELECTION_SORT__
#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;
namespace SortTestTool
{
    int* genTestArray(int from, int to, int amount)
    {
        assert(from <= to);
        srand(time(NULL));
        int* ret = new int[amount];
        for(int i = 0; i < amount; i++)
        {
            ret[i] = rand() % (to - from + 1) + from;
        }
        return ret;
    }
    void printArray(int* arr, int amount)
    {
        for(int i = 0; i < amount; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }
    template <typename T>
    bool isSorted(T* arr, int amount)
    {
        for(int i = 0; i< amount - 1; i++)
        {
            if(arr[i] > arr[i+1])
                return false;
        }
        return true;
    }
    template <typename T>
    void testSpendTimePrint(const string& sortname, void (*fun)(T* , int), T* arr, int amount)
    {
        clock_t start_time = clock();
        fun(arr, amount);
        clock_t end_time = clock();
        assert(isSorted(arr, amount));
        double spendtime = double(end_time - start_time) / CLOCKS_PER_SEC;
        cout << sortname << " spend: " << spendtime << 's' << endl;
        
    }
};
#endif