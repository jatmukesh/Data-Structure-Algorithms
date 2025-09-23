#include<iostream>
using namespace std;


int find_Min(int arr[], int size){
    int minAns = INT_MAX;
    for(int i = 0; i < size; i++){
         if(arr[i] < minAns){
            minAns = arr[i];
         }
    }
    return minAns;
}

int main(){
    
    // //Array Creation 
    // int num[ 5 ];
    // char ch[ 5 ];
    // bool flag1[ 5 ];
    // short snum[ 5 ];
    // long lnum[ 5 ];

    // // Address of any variable using & operator
    // int n = 5;
    // cout << " value of n : " << n << endl;
    // cout << " address of n : " << &n << endl;
    // cout << " size of n : " << sizeof( n ) << endl;

    // // Address of any array using & operator
    // int arr[ 5 ];
    // cout << " base address of arr: " << &arr << endl;
    // cout << " base address of arr: " << arr << endl;   // &arr and arr both represent the same address 
    // cout << " size of arr : " << sizeof( arr ) << endl;

    // //taking input values of array
    // int array1[ 5 ] ;
    // for( int i =0 ; i < 5; i++){
    //      cin >> array1[ i ] ;
    // }
    
    // for( int i =0 ; i < 5; i++){
    //     cout  << array1[ i ] << " ";
    // }    
    
    // //printing values of array
    // int array[ 5 ] = { 20,21,22,23,24};
    // for( int i =0 ; i < 5; i++){
    //     cout <<"The array[ " << i << " ] " << array[ i ] << endl;
    // }

    // //Linear search in array
    // int find_in[5] = { 1,3,5,7,9 };
    // int target = 5;
    // bool flag = 0 ;
    // int position = 0;

    // for( int i=0 ; i < 5; i++){
    //     if( find_in[i] == target){
    //         position = i;
    //         flag = 1;
    //         break; 
    //     }
    // }

    // if(flag)
    //     cout << " target found at '" << position << "' position" <<endl;
    // else
    //     cout << " target not found in arr" << endl;

    //find the minimum value in array
    int arr[5] = { 50,20,10,1,90 };
    int size = 5 ;

    int minvalue = find_Min( arr , size);
    cout << " the minimum value in array is: " << minvalue << endl;

}