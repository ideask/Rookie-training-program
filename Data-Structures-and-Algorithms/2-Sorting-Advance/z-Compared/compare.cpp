#include "compare.h"

template <typename T>
void __merge(T *arr, int l, int mid, int r)
{
    T aux[r-l+1];
    for(int i = l; i <= r; i++)
    {
        aux[i - l] = arr[i];
    }
    int i=l;
    int j=mid+1;
    for(int k = l; k <= r; k++)
    {
        if(i > mid){arr[k] = aux[j-l]; j++;}
        else if(j > r){arr[k] = aux[i-l]; i++;}
        else if(aux[i-l] > aux[j-l]){arr[k] = aux[j-l]; j++;}
        else{arr[k] = aux[i-l]; i++;}
    }
}

template <typename T>
void __mergeSort(T *arr, int l, int r)
{
    if(l>=r)
        return;
    int mid = l + (r-l)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    __merge(arr, l, mid, r);
}

template <typename T>
void mergeSort(T *arr, int amount)
{
    __mergeSort(arr, 0, amount-1);
}

template <typename T>
void insertionSort(T *arr, int l, int r)
{
    for(int i = l; i<=r; i++)
    {
        T v = arr[i];
        int j;
        for(j=i; arr[j-1] > v && j > 0; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = v;
    }
}

template <typename T>
void __mergeSortAdvance(T *arr, int l, int r)
{
    if(r-l < 15)
    {
        insertionSort(arr, l, r);
        return;
    }
    int mid = l + (r-l)/2;
    __mergeSortAdvance(arr, l, mid);
    __mergeSortAdvance(arr, mid+1, r);
    if(arr[mid+1] > arr[mid])
        return;
    __merge(arr, l, mid, r);
}

template <typename T>
void mergeSortAdvance(T *arr, int amount)
{
    __mergeSortAdvance(arr, 0, amount-1);
}

template <typename T>
void __mergeSortBU(T *arr, int amount)
{
    for(int sz=1; sz <= amount; sz+=sz)
    {
        /* arr[i,i+sz-1]   arr[i+sz, i+sz+sz-1]*/
        for(int i=0; i+sz-1 < amount-1; i+=sz+sz)
        {
            __merge(arr,i, i+sz-1, min(i+sz+sz-1, amount-1));
        }
    }
}

template <typename T>
void mergeSortBU(T *arr, int amount)
{
    __mergeSortBU(arr, amount);
}

template <typename T>
int partition(T *arr, int l, int r)
{
    T v = arr[l];
    /*arr[l+1, j]  arr[j+1,r]*/
    int j = l;
    int i = l+1;
    while(i<=r)
    {
        if(arr[i] >= v){i++;}
        else if(arr[i] < v){swap(arr[i], arr[j+1]);j++;i++;}
    }
    /*arr[l, j-1] j arr[j+1,r]*/
    swap(arr[l], arr[j]);
    return j;
}

template <typename T>
void __quickSort(T *arr, int l, int r)
{
    if(l>=r)
        return;
    int p = partition(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}

template <typename T>
void quickSort(T *arr, int amount)
{
    __quickSort(arr, 0, amount-1);
}

template <typename T>
int partitionRP(T *arr, int l, int r)
{
    srand(time(NULL));
    swap(arr[l], arr[rand() % (r-l+1) + l]);
    T v = arr[l];
    /*v=arr[l]   arr[l+1, j]   arr[j+1, r]*/
    /*arr[l, j-1]   arr[j+1, r]*/
    int j = l;
    for(int i=l+1; i <= r; i++)
    {
        if(arr[i] < v)
        {
            swap(arr[i], arr[j+1]);
            j++;
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

template <typename T>
void __quickSortRandomPick(T *arr, int l, int r)
{
    if(l >= r)
        return;
    int p = partitionRP(arr, l, r);
    __quickSortRandomPick(arr, l, p-1);
    __quickSortRandomPick(arr, p+1, r);
}

template <typename T>
void quickSortRP(T *arr, int amount)
{
    __quickSortRandomPick(arr, 0, amount-1);
}

template <typename T>
int partitionTW(T *arr, int l, int r)
{
    srand(time(NULL));
    swap(arr[l], arr[rand() % (r-l+1) + l]);
    T v = arr[l];
    /* arr[l+1, j)   arr(k, r]*/
    int j=l+1;
    int k=r;
    while(true)
    {
        while(arr[j] < v){j++;}
        while(arr[k] > v){k--;}
        if(j > k)
            break;
        swap(arr[j], arr[k]);
        j++;
        k++;
    }
    swap(arr[l], arr[k]);
    return k;
}

template <typename T>
void __quickSortTW(T *arr, int l, int r)
{
    if(l >= r)
        return;
    int p = partitionTW(arr, l, r);
    __quickSortTW(arr, l, p-1);
    __quickSortTW(arr, p+1, r);
}

template <typename T>
void quickSortTwoWays(T *arr, int amount)
{
    __quickSortTW(arr, 0, amount-1);
}

template <typename T>
void __quickSortThreeWays(T *arr, int l, int r)
{
    if(l >= r)
        return;
    srand(time(NULL));
    swap(arr[l], arr[rand() % (r-l+1)+l]);
    T v = arr[l];
    /*arr[l+1,lt] arr[lt+1, gt-1]  arr[gt,r]*/
    int i = l+1;
    int lt = l;
    int gt = r+1;
    while(i < gt)
    {
       if(arr[i] > v){swap(arr[i], arr[gt-1]); gt--;}
       else if(arr[i] < v){lt++; i++;}
       else{i++;} 
    }
    swap(arr[l], arr[lt]);
    __quickSortThreeWays(arr, l, lt-1);
    __quickSortThreeWays(arr, gt, r);
}

template <typename T>
void quickSortThreeWays(T *arr, int amount)
{
    __quickSortThreeWays(arr, 0, amount-1);
}


int main()
{
    #define FROM 1
    #define TO 100
    #define AMOUNT 100
    int *arr = sortTestHelper::genRandomArr(FROM,TO,AMOUNT);
    int *arr11 = sortTestHelper::cpyArr(arr, AMOUNT);
    int *arr21 = sortTestHelper::cpyArr(arr, AMOUNT);
    int *arr31 = sortTestHelper::cpyArr(arr, AMOUNT);
    int *arr41 = sortTestHelper::cpyArr(arr, AMOUNT);
    int *arr51 = sortTestHelper::cpyArr(arr, AMOUNT);
    int *arr61 = sortTestHelper::cpyArr(arr, AMOUNT);
    int *arr71 = sortTestHelper::cpyArr(arr, AMOUNT);
    // sortTestHelper::sortBenchMark("Merge Sort base", mergeSort, arr11, AMOUNT);
    // sortTestHelper::sortBenchMark("Merge Sort Advance", mergeSortAdvance, arr21, AMOUNT);
    // sortTestHelper::sortBenchMark("Merge Sort Bottom up", mergeSortBU,arr31,AMOUNT);
    // sortTestHelper::sortBenchMark("Quick Sort base", quickSort,arr41,AMOUNT);
    // sortTestHelper::sortBenchMark("Quick Sort base Random pick", quickSortRP,arr51,AMOUNT);
    sortTestHelper::sortBenchMark("Quick Sort base Two ways", quickSortTwoWays,arr61,AMOUNT);
    sortTestHelper::sortBenchMark("Quick Sort base Three ways", quickSortThreeWays,arr71,AMOUNT);

    return 0;
}