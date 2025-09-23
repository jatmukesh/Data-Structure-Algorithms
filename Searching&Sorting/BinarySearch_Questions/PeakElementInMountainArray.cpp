#include<iostream>
#include<vector>
using namespace std;

int PeakElement( int arr[],int n ){
    int start = 0 ,end = n-1;
    int mid = start + ( end- start)/2;

    while( start < end ){
        if( arr[mid] < arr[ mid+1]){
            start = mid + 1;
        }
        else{
            end = mid ;
        }
        mid = start + (end - start)/2;
    }
    return arr[mid];
}

int main(){
    int arr[] = { 10,20,50,40,30 };
   int n = sizeof(arr)/sizeof(int);
   int ans = PeakElement(arr, n);
    cout << " The peak is :" << ans << endl;
}