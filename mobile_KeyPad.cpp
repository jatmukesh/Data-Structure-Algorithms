#include<iostream>
#include<string.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

void recursive_sol(string digits,string output, int index, vector<string> &ans ){
   
    //base case 
    if( index >= digits.size()){
        ans.push_back(output);
        return ;
    }

    //processing 
    string mapping[10] = { "", "", "abc", "def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    int equi_num = digits[index] - '0';
    string value = mapping[equi_num];
    
    for(int i = 0 ; i < value.size(); i++){
        output.push_back(value[i]);
        recursive_sol(digits , output , index+1 ,ans);   //recursion calling
        output.pop_back();
    }

}

vector<string> solve(string digits){
     vector<string > ans ;          // ans will stored in this vector
     string output ="";             // every string that can be formed using the digits will be created here and pushed to ans 
     int index = 0;
   recursive_sol(digits,output,index ,ans );
    return ans;
}

int main (){

    string digits = "23";
    vector<string > ans = solve(digits);
     
    for(auto i : ans){
        cout << i << "  " ;
    }
}