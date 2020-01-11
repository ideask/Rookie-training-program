#ifndef __MERGE_SORT_ADVANCE__
#define __MERGE_SORT_ADVANCE__
#include <iostream>
#include <cassert>
#include <ctime>
#include <string.h>
#include <string>
#include <random>
using namespace std;

namespace sortTestHelper
{
    template <typename T>
    bool isSorted(T *arr, int amount)
    {
        for(int i = 0; i < amount - 1; i++)
        {
            if(arr[i] > arr[i+1])
                return false;
        }
        return true;
    }

    template <typename T>
    void arrPrint(T *arr, int amount)
    {
        for(int i = 0; i < amount; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    template <typename T>
    T *arrCpy(T *src, int amount)
    {
        T *ret = new T[amount];
        for(int i = 0; i < amount; i++)
        {
            ret[i] = src[i];
        }
        return ret;
    }

    int *genRandomArr(int from, int to, int amount)
    {
        assert(to >= from);
        int *ret = new int[amount];
        srand(time(NULL));
        for(int i = 0; i < amount; i++)
        {
            ret[i] = rand() % (from - to) + from;
        }
        return ret;
    }

    int *genNearlyArr(int amount, int swaptime)
    {
        int *ret = new int[amount];
        srand(time(NULL));
        for(int i = 0; i < amount; i++)
        {
            ret[i] = i;
        }
        for(int j = 0; j < swaptime; j++)
        {
            int pos_x = rand() % amount;
            int pos_y = rand() % amount;
            swap(ret[pos_x], ret[pos_y]);
        }
        return ret;
    }

    template <typename T>
    void sortBenchMark(const string name, void (*fun)(T *, int), T *arr, int amount)
    {
        clock_t start_time = clock();
        fun(arr, amount);
        clock_t end_time = clock();
        assert(isSorted(arr, amount));
        cout << name << " Algorithm spend time : " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " s" <<endl;
    }
};

#endif