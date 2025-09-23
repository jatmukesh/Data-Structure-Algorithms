    
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int find_K_diff_pair(int arr[], int size ,int k){
    sort( arr,arr+size);
    int count = 0;
    for(int i =0 ;i < size-1;i++){
        int start = i+1 ;
        int end = size-1;
        int target = arr[i]+k;
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        while( start <= end){
            int mid = start + (end-start)/2;
            if(target == arr[mid]) {
                count++;
                break;
            }
            else if(target > arr[mid]) start = mid +1;
            else end = mid-1;
        }
         
    }
    return count ;

}

int main(){
    int arr[] = { 3,7,2,1,5 };
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
  
    int ans = find_K_diff_pair(arr,size,k);
    
  
    cout << ans << "  ";
}