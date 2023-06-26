#include<iostream>
#include<limits.h>

using namespace std ;

void printArray(int *arr ,int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int maximum(int *arr ,int  n ){
    int max = INT_MIN ;

    for(int i = 0 ;i<n;i++){
        if(arr[i+1]>arr[i]){
            max = arr[i+1];
        }
    }

    return max ;
}

void countSort(int* arr ,int n)
{
    int maxsize  = maximum(arr,n);

    int* countArray = (int*)malloc((maxsize+1)*sizeof(int));

    for(int i = 0 ;i<=maxsize;i++){
        countArray[i]=0;
    }


    for(int i = 0 ;i<n;i++){
        countArray[arr[i]]++;
    }

    int i = 0, j=0 ;
    
    while(i<=maxsize){
        if(countArray[i]>0){
            arr[j]=i;
            countArray[i]--;
            j++;
        }else{
            i++;
        }
    }
}

int main()
{
    int arr[] = {4, 36, 9, 8};
    int n = 4;
    countSort(arr,n);
    printArray(arr, n);
    return 0;
}

