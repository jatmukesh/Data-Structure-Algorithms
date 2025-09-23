#include<iostream>
using namespace std;

void InsertionSortIncreasing(int arr[], int n){

    for( int i = 1 ; i < n; i++){
        int key = arr[i];
        int j = i-1; 
       while( j>=0 && arr[j] > key){
        arr[j+1] = arr[ j ];
        j--;
       }
       arr[j+1] = key;
}
}

int main(){
    int arr[] = { 44,33,55,22,11 };
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Array before sorting : " ;
    for(auto i: arr){
        cout << i << "  ";
    }
    InsertionSortIncreasing(arr,size);
    cout << "\n Array After sorting : " ;
    for(auto i: arr){
        cout << i << "  ";
    }
    
}