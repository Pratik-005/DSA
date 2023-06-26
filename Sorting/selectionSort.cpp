#include<iostream>

using namespace std ;

void printArray(int*arr,int  n ){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void selectionSort(int*arr,int  n ){
   int minIndex ;
    for(int i = 0 ;i<n-1;i++){
        minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}

int main(){
    int arr[]= {10,3,6,1,5};
    int  n = 5 ;
    selectionSort(arr,n);
    printArray(arr,n);
    return 0 ;

}
