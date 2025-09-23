#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int FindPair(vector<int> &nums,int k ){
    sort(nums.begin(),nums.end());
    set<pair<int,int>> ans;
    int i = 0,j = 1;
    while(j<nums.size()){
        int diff = nums[j] - nums[i];
        if(diff == k){
            //cout << nums[i] << " , " << nums[j];
            ans.insert({nums[i],nums[j]});                  // O(log n) insertion 
            i++,j++;
        }
        else if(diff > k){
            i++;
        }
        else{
            j++;
        }
        if(i==j){
            j++;
        }
    }
    return ans.size();
}

int bs(vector<int> &nums, int target){
    int s = 0, e = nums.size()-1;
    int mid = s + (e-s)/2;  
    
    while(s <= e){       
        if(nums[mid] == target ){
            return mid;
        }
        else if(nums[mid] > target){
            e = mid-1;
        }
        else{
            s = mid +1;
        }
        mid = s +(s-e)/2;
    }
    return -1;
}


int FindPair_Binary_search(vector<int> &nums,int k){            //O(nlogn)
    sort(nums.begin(),nums.end());
    set<pair<int,int>> ans;
    for(int i = 0 ; i < nums.size(); i++){
        int target = nums[i]+k;
        if(bs(nums,target) != -1){
            ans.insert({nums[i],target});
        }
    }
  

    return ans.size();
}



int main(){
    vector<int> nums = { 3,1,4,1,5 };
    int paircount = FindPair_Binary_search(nums,2);
    cout << " no of pairs : " << paircount << endl;
}
