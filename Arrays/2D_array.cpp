#include<iostream>
using namespace std;

void printArray_row_wise( int arr[][4], int row , int col){
    for( int i = 0; i < row; i++){
        for( int j = 0;j < col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void printArray_col_wise( int arr[][4], int row,int col){
    for( int i = 0; i < col; i++){
        for( int j = 0;j < row; j++){
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}

bool findTarget( int arr[][4], int row ,int col, int target){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if( arr[i][j] == target ){
            return true;
            }
        }
    }
     
    return false;
}

int findMax(int arr[][4], int row ,int col ){
    int maxAns = INT_MIN; 
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if( arr[i][j] > maxAns ){
            maxAns = arr[i][j];
            }
        }
    }
    return maxAns;
    
}

void SumRow_wise(int arr[3][4], int row ,int col ){
    for(int i = 0; i < row; i++){
        int sum = 0; 
        for(int j = 0; j < col; j++){
            sum+= arr[i][j];
            }
            cout << " Sum of row: " << i << " is: " << sum << endl;
        }
    }
    
    void SumCol_wise(int arr[][4], int row ,int col ){
        for(int i = 0; i < col; i++){
            int sum = 0; 
            for(int j = 0; j < row; j++){
                sum+= arr[j][i];
                }
                cout << " Sum of col: " << i << " is: " << sum << endl;
            }
        }
    

int main(){

    // cout << "creating a 2D array" << endl;
    // int arr[ 3 ][ 4 ] = {
    //     { 1,2,3,4 },
    //     { 5,6,7,8 },
    //     { 10,20,30,40 }
    // };

    // /*
    //  initializing array with mentioning row size is possible but col has to be mentioned
    //  2D array is allocated as a linear array only the mapping of values from 2D to 1D is done by : ( place_at = col_size*i +j )
    // */

    // int arr2[][4] = {           // here size of col is mentioned without rows 
    //     { 1,2,3,4 },
    //     { 5,6,7,8 },
    // };

    // int row = 2,col = 4;
    // printArray_row_wise( arr2, row, col );
    // cout << " colwise access" << endl;
    // printArray_col_wise( arr, 3, 4 );


    //input for 2D array

    // int arr[3][4];
    // int row = 3, col = 4;
    // for(int i = 0; i < row; i++){
    //     for(int j = 0; j < col; j++){
    //         cout << "enter the element for row : " << i <<" col: " << j << endl;
    //         cin >> arr[i][j];
    //     }
    // }

    // cout << " Printing the input taken" <<endl;
    // printArray_row_wise(arr, row , col);

    //linear search in 2D array
    int arr[ 3 ][ 4 ] = {
            { 1,2,3,4 },
            { 5,6,7,8 },
            { 10,20,30,40 }
        };
        
        int row = 3, col = 4;
       
    //     if( findTarget(arr, row , col, 60)){

    //     cout << " target found"<< endl;
    //    }
    //    else cout << "not found ";

 //   cout << " max number : " << findMax(arr ,row ,col);

    // row wise addition of elements
    SumRow_wise(arr,row ,col);
    SumCol_wise(arr,row ,col);
}