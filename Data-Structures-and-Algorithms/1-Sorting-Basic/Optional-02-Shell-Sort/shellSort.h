#ifndef __SHELL_SORT__
#define __SHELL_SORT__
#include <iostream>
#include <cassert>
#include <ctime>
#include <random>
#include <string.h>
using namespace std;

namespace sortTestTool
{
    int* genTestArr(int from, int to, int amount)
    {
        assert(to >= from);
        srand(time(NULL));
        int *arr = new int[amount];
        for(int i=0; i < amount; i++)
        {
            arr[i] = rand() % (to - from + 1) + from;
        }
        return arr;
    }

    int *genNearlySortArr(int amount, int swap_time)
    {
        srand(time(NULL));
        int *ret = new int[amount];
        for(int i=0; i<amount; i++)
        {
            ret[i] =  i;
        }
        for(int i=0; i < swap_time; i++)
        {
            int pose_x = rand() % amount;
            int pose_y = rand() % amount;
            swap(ret[pose_x], ret[pose_y]);
        }
        return ret;
    }

    template <typename T>
    void printArr(T arr, int amount)
    {
        for(int i = 0; i < amount; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    template <typename T>
    bool isSorted(T* arr, int amount)
    {
        for(int i = 0; i < amount - 1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                return false;
            }
        }
        return true;
    }

    template <typename T>
    void sortSpendTime(const string fun_name, void (*fun)(T*, int,int), T* arr, int amount, int gap)
    {
        clock_t start_time = clock();
        fun(arr, amount,gap);
        clock_t end_time = clock();
        assert(isSorted(arr, amount));
        cout << fun_name << "spend: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;
    }

    template <typename T>
    T *cpyArr(const T *src, int amount)
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