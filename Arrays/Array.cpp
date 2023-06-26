#include <iostream>

using namespace std;

class Myarray
{

    typedef struct elementArray
    {
        int used_size;
        int total_size;
        int *ptr;
    } arr;

    arr myarr;


public:

    Myarray(int used_size, int total_size)
    {
        myarr.used_size = used_size;
        myarr.total_size = total_size;
        myarr.ptr = (int *)malloc(total_size * sizeof(int));
    }

    void insertion(int, int);
    void display(void);
    void deletion(int);
    void setVal();
    int used_size();
    int total_size();
    int search_linear(int);
    int search_binary(int);

};




void Myarray::insertion(int pos, int ele)
{
    if (pos > myarr.total_size)
    {
        cout << "size exceeded";
        return;
    }

    if (myarr.used_size < pos && pos < myarr.total_size)
    {
        myarr.used_size = pos;
    }

    for (int i = myarr.used_size - 1; i >= pos; i--)
    {
        myarr.ptr[i + 1] = myarr.ptr[i];
    }
    myarr.ptr[pos] = ele;


    myarr.used_size++;
}



void Myarray::deletion(int pos)
{
    if (pos > myarr.total_size)
    {
        cout << "Not in range";
        return;
    }

    if (myarr.used_size < pos && pos < myarr.total_size)
    {

        //  myarr.total_size--;
        cout<<"No element at the index"<<endl;
    }


     for (int i=pos; i <myarr.used_size; i++)
    {
        myarr.ptr[i] = myarr.ptr[i+1];
    }

    myarr.used_size--;

}

void Myarray::display()
{
    cout << "The array is " << endl;
    for (int i = 0; i < myarr.used_size; i++)
    {
        cout << myarr.ptr[i] << " ";
    }
    cout << endl;
}



void Myarray::setVal()
{
    for (int i = 0; i < myarr.used_size; i++)
    {
        cout << "Enter the element " << i + 1 << endl;
        cin >> myarr.ptr[i];
    }
}


int Myarray::used_size()
{
    return myarr.used_size;
}


int Myarray::total_size()
{
    return myarr.total_size;
}


int Myarray::search_linear(int ele){
    for(int i=0;i<myarr.used_size;i++){
        if (myarr.ptr[i] == ele){
             return i;
        }
    }
    return -1;
}


int Myarray::search_binary(int ele){
    int low=0;
    int high =myarr.used_size-1;
    
    while(low<=high){
        int mid=(low+high)/2;
        if(myarr.ptr[mid]==ele){
            return mid;
        }
        if(myarr.ptr[mid] < ele ){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    return -1;
}



int main()
{

    Myarray arr(5, 40);
    arr.setVal();
    arr.display();
    // cout << arr.used_size() << endl;
    // cout << arr.total_size() << endl;
    // arr.insertion(5, 78);
    // arr.display();
    arr.deletion(2);
    arr.display();
    // cout << arr.used_size() << endl;
    // cout << arr.total_size() << endl;
    // cout<<arr.search_binary(50);
    // cout<<arr.search_linear(20);
    return 0;
}




