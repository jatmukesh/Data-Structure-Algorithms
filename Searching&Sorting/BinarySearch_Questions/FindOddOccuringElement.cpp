#include<iostream>
using namespace std;

int FindOdd(int arr[], int size){
    int s = 0, e= size-1;
    int mid = s+ (e-s)/2;
    while(s<=e){
        if(s==e)    return s;
        if (mid & 1)  // this shows the mid is at odd position
        {
            if((mid-1) >= 0 && arr[mid] == arr[mid-1]){
                s = mid + 1;   
            }
            else{
                e = mid-1;
            }
        } 

        else{
           if((mid-1)< size && arr[mid] == arr[mid+1]){
                s= mid + 2;   
            }
            else{
                e = mid;
            }
            
        }
        mid = s +(e-s)/2;
    }
    return -1;
}

int main(){
    int arr[]= {1,1,2,2,3,3,4,4,5,5,7,8,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    int targetIndex = FindOdd(arr,size);
    if(targetIndex!= -1){
        cout << "target found at index: " << targetIndex << endl;
    }
    else{
        cout << "target not found "<< endl;
    }
}