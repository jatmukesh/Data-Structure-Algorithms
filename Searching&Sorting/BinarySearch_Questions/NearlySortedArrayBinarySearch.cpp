#include<iostream>
using namespace std;

int SearchNearlySortedArray(int arr[], int size ,int target ){
    int s = 0 ,e = size-1 ;
    int mid = s + (e-s)/2;
    while(s<=e){
        if( (mid-1)>=0 && arr[mid-1 ] == target)   return (mid-1) ;
        else if(arr[mid] == target) return mid ;
        else if((mid+1) < size && arr[mid +1 ] == target) return (mid+1) ;
        else if(target > arr[mid]){
            s = mid +2;
        }
        else {
            e = mid - 2;
        }
        mid = s + (e-s)/2;
    }
    return -1;

}

int main(){
    int arr[] = {20,10,30,50,40,70,60 };
    int size = 7;
    int target = 60;
    int targetIndex = SearchNearlySortedArray(arr,size,target);
    if(targetIndex != -1){
        cout <<  "target found at : "<< targetIndex << endl;
    }
    else
        cout <<  "target not found " << endl; 
}