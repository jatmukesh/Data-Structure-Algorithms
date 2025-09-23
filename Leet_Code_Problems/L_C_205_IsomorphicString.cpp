/*

                                                    205. Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character, but a character may map to itself
Example 1:
Input: s = "egg", t = "add"     Output: true

Example 2:
Input: s = "foo", t = "bar"     Output: false



*/


#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

void mapping(string& s){
    char mapping[300] = {0};
    char start = 'a';
    for(int i = 0 ; i <s.length();i++ ){
        cout << s[i] << endl;
        if(mapping[s[i]] == 0){
            mapping[s[i]] = start;
            start++ ;
        }   
    }
    for(int i = 0 ; i <s.length();i++ ){
        s[i] = mapping[s[i]];
        cout << s[i] << endl;
    }
}

bool isomorphic(string s , string t){
    mapping(s);
    mapping(t);
    if( s == t){
        return true;
    }
    else return false;
}

int main(){
    string s = "gff", t = "add";
    if(isomorphic(s,t))     cout << "valid";
    else                    cout << "not valid"; 

}