
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

void digit_to_num(vector<int> &digit,int &num,int index){
    if(index >= digit.size())       return ;

    digit_to_num(digit, num, index+1);
    num += digit[index]*pow(10,digit.size() - index-1);

}
void num_to_digit(int n, vector<int> & ans){
    
    if(n == 0 )     return ;
    num_to_digit(n/10,ans);
    ans.push_back( n % 10);
    
}

int main(){
    int n = 4215;
    vector<int> digit ={ 4,2,1,5 };
    int num =0;
    //  vector<int> ans;
//    num_to_digit(n,ans);
  
//    for(auto i : ans ){
//     cout << i << " " ;
//    }
    int index = 0;
    digit_to_num(digit, num , index);
    cout << num <<endl;
}