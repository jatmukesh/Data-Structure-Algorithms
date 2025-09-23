#include<iostream>
using namespace std;

int unique_element( int arr[], int size){
    int ans = 0;
    for( int i = 0; i < size; i++){
        ans ^= arr[ i ]; 
    }
    return ans;
}

int main(){

    int arr[] = { 2,10,11,13,10,15,2,13,15 };
    int size = 9;

    int UE = unique_element( arr, size);
    cout << " The unique element is : " << UE << endl;
}