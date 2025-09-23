#include<iostream>
#include<vector>
using namespace std;

int BruteForce(vector<int>&nums){                       //Time Complexity -> O(n^2)
    for( int i = 0 ; i < nums.size(); i++){
        int lsum = 0; 
        int rsum = 0;

        for( int j = 0; j < i; j++)
            lsum += nums[ j ];
        
        for(int j = i+1; j < nums.size(); j++)
            rsum += nums[ j ];
    cout << " For index : " << i << " left-sum : " << lsum << " right-sum : " << rsum << endl;   
    if( lsum == rsum)   return i;
    }
    return -1;
}


int PrefixSumApproach( vector<int> &nums){          //Time Complexity -> O(n)

    /*
    This method uses 2 vectors initialized with 0 values and of the size as nums
    the lsum vector calculates and adds all the values starting from left side similarly the rsum do it from right side
                        index-> [ 0 1 2 3 4 5 ]       nums-> { 1,7,3,6,5,6 }                index-> [ 0 1 2 3 4 5 ]     
                        lsum -> { 0 0 0 0 0 0 }                                             rsum -> { 0 0 0 0 0 0 } 
    1st iteration            -> { 0 1 0 0 0 0 }                                                  -> { 0 0 0 0 6 0 }
    2st iteration            -> { 0 1 8 0 0 0 }                                                  -> { 0 0 0 11 6 0 }
    3st iteration            -> { 0 1 8 11 0 0 }                                                 -> { 0 0 17 11 6 0 }
    4st iteration            -> { 0 1 8 11 17 0 }                                                -> { 0 20 17 11 6 0 }
    5st iteration            -> { 0 1 8 11 17 22 }                                               -> { 27 20 17 11 6 0 }
    
    Now the sums at index 3 of lsum and rsum are matched thus 3 is the pivot point
    
    */

    vector<int> lsum( nums.size(),0 );
    vector<int> rsum( nums.size(),0 );

    for( int i = 1 ; i < nums.size(); ++i){         
        lsum[ i ] = lsum[ i - 1 ] + nums[ i - 1];                
        cout << " For index : " << i << " left-sum : " << lsum[ i ]  << endl;   
    }
    for( int i = nums.size()-2 ; i >= 0 ; --i){
        rsum[ i ] = rsum[ i+1 ]+ nums[ i+1 ];
        cout << " For index : " << i << " right-sum : " << rsum[ i ]  << endl;   
    }
    for(int index = 0; index < nums.size(); ++index){
        if( lsum[ index ] == rsum[ index ])
            return index;
    }
    return -1 ;
}

int main(){

    vector<int> vect ={ 1,7,3,6,5,6 };
    
    int ans = PrefixSumApproach(vect);
    if( ans == -1 ) cout << " No Pivot found ";
    else cout << " the Pivot is at : " << ans << endl; 
}