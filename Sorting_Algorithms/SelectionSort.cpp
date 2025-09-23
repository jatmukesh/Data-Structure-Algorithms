#include<iostream>
using namespace std;

void SelectionSortIncreasing(int arr[], int n){

    for( int i = 0 ; i < n; i++){
        int minIndex = i; 
        for( int j = i+1; j < n;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}


int main(){
    int arr[] = { 5,4,2,1,3 };
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Array before sorting : " ;
    for(auto i: arr){
        cout << i << "  ";
    }
    SelectionSortIncreasing(arr,size);
    cout << "\n Array After sorting : " ;
    for(auto i: arr){
        cout << i << "  ";
    }
    
}