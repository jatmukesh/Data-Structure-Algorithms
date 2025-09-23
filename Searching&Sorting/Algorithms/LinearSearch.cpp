#include<iostream>
#include<vector>

using namespace std;

bool Search(vector<int> &v , int target){
    for( int i = 0; i < v.size(); i++ ){
        if(v[i] == target )
           return true;
        }
    return false;
}

int main(){
    vector<int> v = { 10,20,30,40,50,60,70,80 };
    int target = 50; 
    if(Search(v, target))    cout << "Target found" << endl;
    else                     cout << "Target not found" << endl;
}