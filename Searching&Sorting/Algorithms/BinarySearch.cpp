#include<iostream>
#include<vector>

using namespace std;

int BinarySearch(vector<int> &v , int target){
    int start = 0 , end = v.size() - 1; 
    
    while( start <= end ){
        int mid = (start+end) / 2;
        if(v[mid] == target )          return mid ;
        else if( v[mid] < target )     start = mid + 1;
        else if( v[mid] > target )     end = mid - 1;
    }
    return -1;
}

int main(){
    vector<int> v = { 10,20,30,40,50,60,70,80 };
    int target = 70; 
    int index = BinarySearch(v, target);
    if(index == -1 )    cout << "Target not found" << endl;
    else                     cout << "Target  found at index : "  << index << endl;
}