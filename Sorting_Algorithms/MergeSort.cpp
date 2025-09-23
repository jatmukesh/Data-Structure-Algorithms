#include<iostream>
#include<vector>
using namespace std;


void merge(int arr[], int start , int end ){
    int mid = start+(end - start)/2;
    int lenLeft = mid- start+1;
    int lenRight = end -mid;

    int* left = new int[lenLeft];
    int* right = new int[lenRight];

    int k = start ;
    for(int i = 0 ; i< lenLeft ; i++){
        left[i] = arr[k];
        k++;
    }

    k = mid+1 ;
    for(int i = 0 ; i< lenRight ; i++){
        right[i] = arr[k];
        k++;
    }

    // actual merge
    int leftIndex = 0;
    int rightIndex = 0;
    int mainIndex = start ;

    while(leftIndex < lenLeft && rightIndex < lenRight){
       if(left[leftIndex] < right[rightIndex]){
        arr[mainIndex] =  left[leftIndex];
        mainIndex++;
        leftIndex++;
       }
       else{
       arr[mainIndex] =  right[rightIndex];
        mainIndex++;
        rightIndex++;
       }
    }

    while(leftIndex < lenLeft){
         arr[mainIndex] =  left[leftIndex];
        mainIndex++;
        leftIndex++;
    }
     while(rightIndex < lenRight){
        arr[mainIndex] =  right[rightIndex];
        mainIndex++;
        rightIndex++;
    }

    delete[] left;
    delete[] right;

}

void mergeSort(int arr[], int start , int end ){
    
    //base case 
    if(start > end || start== end)      return;
    // divide the array with mid -> left part [start, mid]    -> rightpart [ mid+1 , end]
    int mid = start + (end-start)/2;

    //recursion for sorting the arrays
    //for left 
    mergeSort(arr,start, mid);
    // for right
    mergeSort(arr, mid+1, end);

    //merge sorted array
    merge(arr,start ,end);
}
int main(){
    int arr[ ]= { 1,3,2,5,4,7,1 };
    int start = 0 ;
    int end = 6;
    mergeSort(arr, start , end);

    for(auto i : arr){
        cout << i << "  ";
    }
    
}