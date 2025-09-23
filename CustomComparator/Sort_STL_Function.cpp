#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printvv(vector<vector<int>>&v){
    for(int i=0 ; i < v.size(); i++){
        vector<int>temp = v[i];
         cout << temp[0] <<" " << temp[1] << endl; 
    }
}

bool mycomp(vector<int>&a,vector<int>&b){
    return a[1] < b[13];
}

int main(){
   vector<vector<int>> v;
   int n ;
   cin >> n;
   for(int i = 0 ; i< n; i++){
       int a,b;
    cout << "enter a & b :" << endl;
    cin >> a >> b;
    vector<int>temp;
    temp.push_back(a);
    temp.push_back(b);
    v.push_back(temp);
   }

   
   //sort the vector by 2nd value; 
   sort(v.begin(),v.end(),mycomp);
   printvv(v);
}