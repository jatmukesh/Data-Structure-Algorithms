#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

//                                     !!TWO pointer approach!! 
string reverseOnlyLetters(string s) {
       
        int i = 0 , j = s.length()-1;
       
        while( i <= j ){
            if(!((s[i] >= 'A' && s[i] <= 'Z' ) ||(s[i] >= 'a' && s[i] <= 'z' ) ))  i++; //can use both letter 
            else if(!((s[j] >= 65 && s[j] <= 90 ) ||(s[j] >= 97 && s[j] <= 122 ) ))  j--; // and ascii value
            else{
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }

        //using inbuilt function isaplha() that checks if the char is a alphabet or not
        //directly without manual conditioning  i.e, checks s[i] ->[A-Z] || [a-z]
        // while(i <= j ){
        //     if(!isalpha(s[i])) i++;
        //     else if(!isalpha(s[j])) j--;
        //     else{
        //         swap(s[i],s[j]);
        //         i++;
        //         j--;
        //     }
        // }

        return s;
    }


int main(){
    string s = "ab-cd";
    cout << " Given string : "<< s<< endl;

    string rev_s = reverseOnlyLetters(s);
    cout << " Reveresed string : "<< rev_s<< endl;
}