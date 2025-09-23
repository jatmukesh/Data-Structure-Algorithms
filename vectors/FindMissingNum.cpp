#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int FindMissingNum_SortMethod( vector<int> &nums ){
    /*
    using nums and index method 
    i.e, sort nums first and then check whether nums[ i ] == i or not if not then the missing num is i itself return i
    it leaves the bug of corner case i.e, the value of size say range of 0-n is [ 0,2 ] the size ==2 is left in the iteration 
    thus if all the cases match then return size as missing value
    */
   sort(nums.begin() , nums.end());
   for( int i = 0; i < nums.size(); ++i){
        if( i == nums[ i ]) continue;
        else    return i;
   }
   return nums.size();
}

int FindMissingNum_XOR( vector<int> &nums ){
    /*
    when we XOR A^A = 0 thus if the array elements are XORed with the complete range i.e, [ 0,n ] 
    now we will be left with only the element that appeared only once from the range thus giving the answer
    example - arr-> [ 0 , 1 , _ , 3 ] ->> 2 is missing 
            index-> [ 0 , 1 , 2 , 3]  on XORing all will cancel out and only 2 will be left
    */

    int ans = 0;
    for( int i = 0; i < nums.size(); ++i ){
    ans ^= nums[i];         //XOR of all the elements of array
    }
    for( int i = 0; i <= nums.size(); ++i ){
        ans ^= i;           // XOR of all the index value i.e, complete range of n elements 
        }
    return ans ;

}

int main(){
    vector<int> nums = { 0,1,2,6,7,9,3,4,5 };
    //printing before sorting 
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " " ;
    }
    cout << "\n Using sort method " << endl;
    cout << " The missing number from vector-array is : " << FindMissingNum_SortMethod( nums ) << endl;
    
    cout << " Using XOR method " << endl;
    cout << " The missing number from vector-array is : " << FindMissingNum_XOR( nums ) << endl;
   
    //sorted in the function as was passed with reference
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " " ;
    }
}