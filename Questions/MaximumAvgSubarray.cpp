#include<iostream>
#include<vector>

using namespace std;

double MaximumAvgSubarrayBruteForce( vector<int>&nums , int k ){            // Time complexity -> O(n^2)
    int maxSum = INT_MIN;
    int start = 0 , end  = k-1;
    while( end < nums.size() ){
        int sum = 0 ;
         for(int y = start; y <= end; ++y ){
            sum += nums[y]; 
        }
        maxSum = max( maxSum,sum );
        ++start,++end;
    }
    double Avg = maxSum/(double)k;
    return Avg;
}

double MaximumAvgSubarraySlidingWindowMethod( vector<int>&nums , int k ){
    int start = 0, end = k-1;
    int sum = 0;
    for(int i = start; i <= end; ++i ){
        sum += nums[i];
    }
    int maxSum = sum;
    end++;
    while( end < nums.size()){
        sum -= nums[start++];
        sum += nums[end++];
        maxSum = max(maxSum, sum);
    }
    double Avg = maxSum/(double)k;
    return Avg;
}
int main(){
    vector<int> nums = { 1,12,-5,-6,50,3 };
    int k = 4;
    cout << "The Maximum Average is : "<< MaximumAvgSubarraySlidingWindowMethod(nums , k );
}