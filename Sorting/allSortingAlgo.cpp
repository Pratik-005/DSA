#include <iostream>
#include <limits.h>

using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int maximum(int *arr, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i + 1] > arr[i])
        {
            max = arr[i + 1];
        }
    }
    return max;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (arr[i] < pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }

    } while (i < j);

    swap(arr[j], arr[low]);

    return j;
}

void merge(int *arr, int low, int mid, int high)
{

    int i = low;
    int j = mid + 1;
    int k = low;
    int *tempArray = (int*)malloc((high + 1) * sizeof(int));

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            tempArray[k++] = arr[i++];
        }
        else
        {
            tempArray[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        tempArray[k++] = arr[i++];
    }

    while (j <= high)
    {
        tempArray[k++] = arr[j++];
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = tempArray[i];
    }
}


void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int *arr, int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void selectionSort(int *arr, int n)
{
    int minIndex;
    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

void mergeSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void countSort(int *arr, int n){
    int max = maximum(arr,n);
    int* countArray = (int*)malloc((max+1)*sizeof(int));

    for(int  i = 0;i<=max;i++){
        countArray[i]=0;
    }

    for(int  i = 0;i<n;i++){
        countArray[arr[i]]++;
    }

    int i = 0;
    int j = 0;

    while(i<=max){
        if(countArray[i]>0){
            arr[j] = i;
            j++;
            countArray[i]--;
        }else{
            i++;
        }
    }

    
}

int main()
{
    int A[] = {1, 45, 23, 56, 96};
    int n = 5;
    countSort(A,n);
    printArray(A, n);
    return 0;
}



