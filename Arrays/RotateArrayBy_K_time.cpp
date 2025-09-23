#include<iostream>
using namespace std;

// Rotate using temp array
void RotateUsingTemp(int arr[], int size, int k  ){
    int temp[ k ];
    for( int i = 0 ;i < k; i++){
        temp[ i ] = arr[ size - k + i];
    }
    for( int i = size-1; i >= 0; i-- ){
        arr[ i ] = arr[ i - k ];
    }
    for(int i = 0; i < k; i++){
        arr[ i ] = temp[ i ];
    }


    cout << " \n After Rotating : ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " " ;
    }
}

//using Modulus operator 
void RotateUsingModulus( int arr[] , int size , int k ){
    int ans[ size ] ;
    for( int index = 0; index < size; index++){
        int newIndex = (index + k ) % size ;
        ans[newIndex] = arr[ index ]; 
    }

    arr = ans;

    cout << " \nAfter Rotating : ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " " ;
    }
}


int main(){
    int arr[] = { 1,2,3,4,5,6 };
    int size = sizeof(arr)/ sizeof( arr[0]);
    int k = 2;
   cout << " \nBefore Rotating : ";
   for(int i = 0; i < size; i++){
        cout << arr[i] << " " ;
    }
   // RotateUsingTemp(arr, size , k); 
    RotateUsingModulus(arr, size , k); 
}