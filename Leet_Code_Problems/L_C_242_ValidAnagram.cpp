/*

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

*/    


#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;


                                        // Complexity is O(n^2) //
bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        else{
           
            int index = 0;
            while(s.find(t[index]) != string:: npos){
                s.erase(s.find(t[index]),1);
                index++;
            
            }

          //one liner
          //  for(int i =0 ; i< t.length(); (s.find(t[i]) != string:: npos) ? s.erase(s.find(t[i]),1),i++  : i++){}
          
            // for(int i = 0; i < t.length(); i++){         //same logic but with for loop
            //     int index = s.find(t[i]);
            //     if( index != string::npos){
            //         s.erase(index,1);
            //     }
            // }
            return s.empty();
        }
        
    }

                                        // Complexity is O(n) //
                                        // Frequency Hashing Method  
/*

1) way:
here we count the char in 's' string and store in an array at the corresponding ascii valued index 
say the size of array is [256 ] to hold ascii all the 256 ascii chars and symbols.    
i.e, -> int freqTable[256] = {0};   // all initialized to 0 as count 
     -> after updating count of char from "s" string then decrement the count of same element in 't' string continue till t.size
     -> if(freqTable[s[i]] != 0 )   return false ; matlab agar koi bhi index pe zero ke alawa kuch hai toh false bolo

2) way:
we can initialze a vector of size 26 as index and all value to '0' to hold all letters 
how -> humlog joh bhi ith index pe element hoga 's' ke i.e, s[i] isse minus kardenge ascii char 'a' 
       to aapneko corresponding index mil jayega in range [0,25] , or waha increment kardenge 
    -> compare logic same vector ke koi bhi index pe except zero value nhi honi chahiye  

*/                                        

bool isAnagram_freqTable(string s, string t) {
        if(s.length() != t.length())
            return false;
        else{
           int freqTable[256] ={0};
           for(int i = 0 ; i < s.size(); i++){
            freqTable[s[i]]++; 
           }
           for(int i = 0 ; i < t.size(); i++){
            freqTable[t[i]]--; 
           }
           
           for(int i = 0 ; i< 256;i++){
             if(freqTable[i] != 0 )
                return false;
           }
           return true;
        }
        
    }    
//instead of this array of size 256 we can create a vector of size 26 just to hold letters at index [0 -25]

bool isAnagram_vectorTable(string s, string t) {
        if(s.length() != t.length())
            return false;
        else{
            vector<int> map(26,0);
            for(int i = 0; i< s.length();i++){
                int index = s[i]-'a'; 
                map[index]++;
            }
            for(int i = 0; i< t.length();i++){
                int index = t[i]-'a'; 
                map[index]--;
            }
            for(int i = 0; i< map.size();i++){
                if(map[i] != 0 )
                    return false;
            }
            return true;
        }
      
    }    

int main(){
    string s1 = "bat";
    string s2 = "tab";

    if(isAnagram_vectorTable(s1,s2))
            cout << "Valid" ;
    else 
            cout << "not Valid" ;
    }