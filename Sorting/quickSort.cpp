#include <iostream>

using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (j > i)
        {
            swap(arr[i], arr[j]);
        }

    } while (i < j);

    swap(arr[j], arr[low]);

    return j;
}



void quickSort(int *arr, int low, int high)
{
    int partionIndex;
    if (low < high)
    {
        int partionIndex = partition(arr, low, high);
        quickSort(arr, partionIndex + 1, high);
        quickSort(arr, low, partionIndex - 1);
    }
}

int main()
{
    int arr[] = {4, 36, 9, 8};
    int n = 4;
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}