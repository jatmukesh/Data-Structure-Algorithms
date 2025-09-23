#include<iostream>
#include<vector>
using namespace std;

int FindPivot(vector<int> nums ){
    int start = 0 , end = nums.size()-1;
    int mid = start + (end- start)/2;
    while( start<= end ){
        if( start==end) return start;
        else if(nums[mid]> nums[mid+1])     return mid;
        else if(nums[mid-1] > nums[mid])    return mid-1;
        else if( nums[start]> nums[mid]){
            end = mid-1; 
        }
        else {
            start = mid + 1;
        }
        mid = start + (end- start)/2;
    }
    return -1;
}

//Search the target in sorted and rotated array
int findTarget(vector<int> nums, int start,int end, int target ){
    int mid = start + (end-start)/2;
    while(start <=end ){
        if(nums[mid] == target)     return mid;
        else if(nums[mid] < target) start = mid+1;
        else end = mid -1;
        mid = start + (end-start)/2;

    }
    return -1;
}

int main(){
    vector<int> nums = { 6,7,8,2,3,4,5};
    int target = 9;
    int ans = -1;
    int n =nums.size();
    int PivotIndex = FindPivot( nums);
    cout << "pivot is :" << PivotIndex << endl;

    if( target >= nums[0] &&  target <= nums[PivotIndex]) {
         ans = findTarget(nums, 0 , PivotIndex, target);
    }
    else 
         ans = findTarget(nums, PivotIndex + 1, n-1, target);
    cout << "target at :" << ans << endl;
}
