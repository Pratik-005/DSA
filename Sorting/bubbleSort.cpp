#include<iostream>

using namespace std ;

void printArray(int *arr,int n){
    for(int i = 0 ;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void bubbleSort(int *arr,int n){
    for(int i = 0 ;i<n-1;i++){
        for(int j = 0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[] = {1,34,23,4};
    int n = 4 ;
    bubbleSort(arr,n);
    printArray(arr,n);
    return 0;
}