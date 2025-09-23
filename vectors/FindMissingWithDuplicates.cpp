#include<iostream>
#include<vector>

using namespace std;

void FindMissingNum( vector<int> &nums ){
    for( int i = 0; i < nums.size(); i++ ){
        int index = abs(nums[ i ]);
        if(nums[index-1] > 0 ){
            nums[ index -1 ] *= -1;
        }
    }
    for( int i = 0; i < nums.size(); i++ ){
        cout << nums[ i ] << " " ;
    } 

    cout << endl;
    for( int i = 0; i < nums.size(); i++ ){
        if( nums[ i ] > 0 ){
            cout << i+1 << " ";
        }
    }
}


void FindMissingNumSortSwap( vector<int> & nums ){

    /*
    we have nums -> {  1 , 3 , 5 , 3 , 4 } --> {  1 , 3 , 3 , 4 , 5 }
            index-> [  0 , 1 , 2 , 3 , 4 ] --> [  0 , 1 , 2 , 3 , 4 ] 
                                        if nums[ i ] != i+1  then return the " i+1 " value as answer

    */
    int i = 0;
    
    while( i < nums.size() ){
        int index = nums[ i ] - 1;
        if( nums[ i ] != nums[ index ] ){
            swap( nums[ i ],nums[ index ]);
        }
        else        ++i;
    }
    for( int i = 0; i < nums.size(); i++ ){
        cout << nums[ i ] << " " ;
    } 
    cout << endl;
    for( int i = 0; i < nums.size(); i++ ){
        if( nums[ i ] != i+1 ) 
            cout << i+1 << " " ;
    } 
}

int main(){

    vector<int> nums = { 1,3,5,3,4 };
  
    cout << endl;
    FindMissingNumSortSwap( nums );
}