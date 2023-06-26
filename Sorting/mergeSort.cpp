#include <iostream>

using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void merge(int* arr ,int low,int mid,int high){
    int i = low;
    int j = mid+1 ;
    int k = low ;
    int tempArray[100];

    while(i<=mid && j<=high){

        if(arr[i]<arr[j]){
            tempArray[k++] =  arr[i++];
        }else{
               tempArray[k++] =  arr[j++]; 
        }
    }

    while(i<=mid){
          tempArray[k++] =  arr[i++];
    }

      while(j<=high){
          tempArray[k++] =  arr[j++];
    }

    for(int i = low;i<=high;i++){
        arr[i] = tempArray[i];
    }
}

void mergeSort(int* arr ,int low,int high){

    if(low < high){
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main()
{
    int arr[] = {4, 36, 9, 8};
    int n = 4;
    mergeSort(arr, 0,n-1);
    printArray(arr, n);
    return 0;
}


