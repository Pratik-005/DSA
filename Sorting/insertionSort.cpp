#include<iostream>

using namespace std ;

void printArray(int*arr,int  n ){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void insertionSort(int*arr,int  n ){
   
    for(int i = 1;i<=n-1;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
    int arr[]= {10,3,6,1,5};
    int  n = 5 ;
    insertionSort(arr,n);
    printArray(arr,n);
    return 0 ;

}

