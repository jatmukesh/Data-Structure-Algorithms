#include<iostream>
using namespace std;


//Brute Force 
int Brute_Force(int arr[], int n, int target){
    
    int i = 0 ;
    while(1){
        if(arr[i] == target )   return i ;
        if(arr[i] > target )    return -1;
        i++;
    }
}


int B_S(int arr[], int start, int end, int target){
    
    while(start <= end){
        int mid = start+ (end-start )/2;
        if(arr[mid] == target)  return mid ;
        else if(arr[mid] < target ){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
}


int Expo_search(int arr[], int n , int target){
    int i = 0,j = 1;
    while(arr[j] < target){
        i = j;
        j = j*2;
    }

    return B_S(arr, i, min(j, n) ,target);  //boundary case has to be considered at index 8 next index will be 16 so min(j,n) will handle the end case
}

int main(){
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 10;

    
    int ans = Brute_Force(arr, n ,target);
   // int ans = Expo_search(arr, n ,target);
    cout << "The element found at index : " << ans;
}