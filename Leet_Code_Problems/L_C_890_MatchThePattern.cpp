#include<iostream>
#include<string.h>
#include<vector>
#include <numeric>
using namespace std;

void normalize_mapping(string &str){
    char start = 'a';
    char mapping[300] = {0};

    for(auto ch : str){
        if(mapping[ch] == 0){
            mapping[ch] = start;
            start++;
        }
    }

    for(int i = 0; i< str.length();i++){
        char ch = str[i];
         str[i] = mapping[ch];
    }
}


vector<string> matchPattern(vector<string>& words ,string pattern){

    vector<string> ans;
    normalize_mapping(pattern);


    for(auto s : words){
        string temp = s ;
        normalize_mapping(temp);
        if(temp == pattern){
            ans.push_back(s);
        }
    }
    return ans;
}

int main(){
    vector<string> words = { "mee" , "bee" , "anx" };
    string pattern = "pqq";

    vector<string> ans = matchPattern(words , pattern);
   
    for(auto i : ans){
        cout << i << "  ";
    }
}