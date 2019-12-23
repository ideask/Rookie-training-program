 #ifndef __COMPARE__
 #define __COMPARE__
 #include <iostream>
 #include <cassert>
 #include <string.h>
 #include <ctime>
 #include <random>
using namespace std;

namespace sortHelper
{
    int *genRandArr(int from, int to, int amount)
    {
        assert(to >= from);
        int *ret = new int[amount];
        srand(time(NULL));
        for(int i = 0; i < amount; i++)
        {
            ret[i] = rand() % (to - from) + from;
        }
        return ret;
    }

    int *genNearlySortArr(int amount, int swap_time)
    {
        int *ret = new int[amount];
        srand(time(NULL));
        for(int i = 0; i < amount; i++)
        {
            ret[i] = i;
        }

        for(int j = 0; j < swap_time; j++)
        {
            int pos_x = rand() % amount;
            int pos_y = rand() % amount;
            swap(ret[pos_x], ret[pos_y]);
        }
        return ret;
    }

    template <typename T>
    T *cpyArr(T *src, int amount)
    {
        T *ret = new T[amount];
        for(int i = 0; i < amount; i++)
        {
            ret[i] = src[i];
        }
        return ret;
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
    void benchMark(const string name, void (*fun)(T *, int), T* arr, int amount)
    {
        clock_t start_time = clock();
        fun(arr,amount);
        clock_t end_time = clock();
        assert(isSorted(arr,amount));
        cout << name <<"spend time : " << (double)(end_time - start_time) / CLOCKS_PER_SEC << "s" <<endl;
    }
};

 #endif