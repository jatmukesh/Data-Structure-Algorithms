#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int  B_S(vector<int> &nums, int start, int end ,int target){
    int mid = start+ (end-start)/2;
    
    while(start<=end){
        if(nums[mid] == target)  return mid;
        else if(nums[mid] > target){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
       mid = start + (end-start)/2;
    }
    return -1;
}  

int Exponential_search(vector<int> &nums,int target){
    if(nums[0] == target)   return 0;
    int i = 1;
    int n = nums.size();
    while( i < n && nums[i]<=target){
    i*=2;
    }
    return B_S(nums, i/2,min(i,n-1), target);
}

int main(){
    vector<int> nums = { 2,3,4,5,7,11,13,14,15,17,56,70 };
    int target =13;

    int ans = Exponential_search(nums,target);
    cout << " the element found at index : "<< ans;
} 