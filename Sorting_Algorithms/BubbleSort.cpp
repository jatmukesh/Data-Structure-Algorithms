#include<iostream>
using namespace std;

void BubbleSortIncreasing(int arr[], int n){

    for( int i = 0 ; i < (n-1); i++){
        for( int j = 0; j < (n-1-i);j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void BubbleSortDecreasing(int arr[], int n){

    for( int i = 0 ; i < (n-1); i++){
        for( int j = 0; j < (n-1-i);++j){
            if(arr[j] < arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}


int main(){
    int arr[] = { 5,4,2,1,3 };
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Array before sorting : " ;
    for(auto i: arr){
        cout << i << "  ";
    }
    BubbleSortDecreasing(arr,size);
    cout << "\n Array After sorting : " ;
    for(auto i: arr){
        cout << i << "  ";
    }
    
}