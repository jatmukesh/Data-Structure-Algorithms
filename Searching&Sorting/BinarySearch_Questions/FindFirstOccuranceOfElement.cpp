#include<iostream>
#include<vector>

using namespace std;

int FirstOccurance(vector<int> &v , int target){
    int start = 0 , end = v.size() - 1; 
    int ans = -1;
    while( start <= end ){
        int mid = (start+end) / 2;
        if(v[mid] == target ){
            ans = mid ;
            end = mid - 1 ;
        }
        else if( v[mid] < target )     start = mid + 1;
        else if( v[mid] > target )     end = mid - 1;
    }
    return ans;
}

int LastOccurance(vector<int> &v , int target){
    int start = 0 , end = v.size() - 1; 
    int ans = -1;
    while( start <= end ){
        int mid = (start+end) / 2;
        if(v[mid] == target ){
            ans = mid ;
            start = mid + 1 ;
        }
        else if( v[mid] < target )     start = mid + 1;
        else if( v[mid] > target )     end = mid - 1;
    }
    return ans;
}

int TotalOccurance( vector<int> v, int target ){
    int First_index = FirstOccurance(v, target);
    int last_index = LastOccurance(v, target);
    int total_occurane = last_index - First_index + 1;
    
    return total_occurane;
}
int main(){
    vector<int> v = { 10,20,30,30,30,30,40,50,60,70,80 };
    int target = 30; 
    int index = FirstOccurance(v, target);
    if(index == -1 )    cout << "Target not found" << endl;
    else                     cout << "First Occurance Target found at index : "  << index << endl;

    int Last_index = LastOccurance(v, target);
    if(Last_index == -1 )    cout << "Target not found" << endl;
    else                     cout << "Last Occurance Target  found at index : "  << Last_index << endl;

cout << "Total Occurance of target " << target << " is : " << TotalOccurance( v, target ) << endl;
}