#ifndef __BUBBLE_SORT__
#define __BUBBLE_SORT__
#include <iostream>
#include <random>
#include <cassert>
#include <ctime>
#include <string.h>
#include <string>
using namespace std;
namespace sortHelper
{
    int *genRanArr(int from, int to, int amount)
    {
        assert(to >= from);
        srand(time(NULL));
        int *ret = new int[amount];
        for(int i = 0; i < amount; i++)
        {
            ret[i] = rand() % (to - from) + from;
        }
        return ret;
    }

    template <typename T>
    bool isSorted(T *arr, int amount)
    {
        for(int i =0; i < amount - 1; i++)
        {
            if(arr[i] > arr[i+1])
                return false;
        }
        return true;
    }

    template <typename T>
    void printArr(T *arr, int amount)
    {
        for(int i = 0; i < amount; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    template <typename T>
    void sortBenchMark(const string name, void (*fun)(T* , int), T *arr, int amount)
    {
        clock_t start_time = clock();
        fun(arr, amount);
        clock_t end_time = clock();
        assert(isSorted(arr, amount));
        cout << name << " spend time : " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " s" <<endl;
    }

    template <typename T>
    T *cpyArr(T* src, int amount)
    {
        T *ret = new T[amount];
        for(int i = 0; i < amount; i++)
        {
            ret[i] = src[i];
        }
        return ret;
    }



};

#endif