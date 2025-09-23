#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int FindMissingNum_Adjacent( vector<int> &nums){
    sort( nums.begin(), nums.end());
    for( int i = 0; i < (nums.size()-1); i++){
        if( nums[ i ] == nums[ i+1 ])   return nums[i];
    }
    return -1;
}

int FindMissingNum_NegativeFLAG( vector<int> &nums){
    int ans = -1;
    for( int i = 0; i < nums.size(); i++ ){
        int index = abs(nums[i]);
        
        //checking already visited or not 
        if( nums[ index ] < 0 ){
            ans = index ;
            break; 
        }
        //marking visited
        nums[index] *= -1; 
    }
    return ans;
}

//Positioning method 
int FindMissingNum_Position_0( vector<int> &nums){
    int ans = -1;
    while( nums[0] != nums[nums[0]]){
        swap( nums[0],nums[nums[0]]);
    }
    ans = nums[0];
    return ans;
}

int main(){
    vector<int> nums = { 1,2,4,3,3 };
    cout << " The duplicate number is : " << FindMissingNum_Position_0(nums) << endl;
    cout << " The duplicate number is : " << FindMissingNum_Adjacent(nums) << endl;
    cout << " The duplicate number is : " << FindMissingNum_NegativeFLAG(nums) << endl;
}