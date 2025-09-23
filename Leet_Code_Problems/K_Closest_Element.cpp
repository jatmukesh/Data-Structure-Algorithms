#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<int> TwoPntr(vector<int> &nums ,int k ,int x){
    int l = 0 , h = nums.size()-1;
    while((h-l) >= k){
        if((x - nums[l] ) > (nums[h] - x )){
            l++;
        }
        else{
            h--;
        }
    }
    return vector<int> (nums.begin()+l,(nums.begin()+h+1));

}

int main(){
    vector<int> nums = { 12,16,22,30,35,39,42,45,48,50,53,55,56 };
    int k = 4 , x = 35;
    vector<int> ans = TwoPntr(nums,k,x);
    for(auto i : ans){
        cout << i << "  "; 
    }
}