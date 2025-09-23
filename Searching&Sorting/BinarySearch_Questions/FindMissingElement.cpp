#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int FindMissingBinarySearch( vector<int> &nums ){
    
    int ans = -1;
    int start = 0;
    int end = nums.size() - 1;
    int mid = start + ( end - start )/2;
    
    while( start <= end ){
        int diff = (nums[ mid ] - mid );
        if( diff == 1 ){
            start = mid + 1;
        }
        else{
            ans = mid;
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    if( (ans+1) == 0 )  return nums.size()+1;
    return ans + 1 ;

}

int main(){
    vector<int> nums = { 1,2,8,7,6,3,4,5 };
    //printing before sorting 
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " " ;
    }
    cout << endl;
    sort(nums.begin(),nums.end());
    //sorted in the function as was passed with reference
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " " ;
    }
    cout << endl;
    cout << "the missing element is : " << FindMissingBinarySearch(nums)<< endl ;
}