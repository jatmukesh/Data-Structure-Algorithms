#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int expand( string s , int i , int j){
    int count = 0; 
    while( i >= 0 && j < s.length() && s[i] == s[j]){
        count++;
        i--;
        j++;
    }
    return count ;
}

int countPalindromicSubString(string s){
    int totalcount = 0;

    for(int center =0; center < s.length(); center++){
        //for odd substrings 
        int odd_ans = expand( s , center , center );
        //for even  substrings 
        int even_ans = expand( s , center , center+1 );
        totalcount = totalcount + odd_ans+ even_ans;
    }
    return totalcount;

}


int main(){

    string s = "aaa";

    cout << " No of palindromic substrings : " << countPalindromicSubString(s)  << endl;
}