#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

bool isVowel(char ch){
    ch = tolower(ch);
    return ch == 'a' || ch== 'e' ||ch == 'i' || ch== 'o' || ch == 'u';
}

string  rev_Vowels(string& str){
    int i  = 0 , j = str.length()-1; 
    while(i < j){
        if(isVowel(str[i]) && isVowel(str[j])){
            swap(str[i],str[j]);
            i++;
            j--;
        }
        else if(!isVowel(str[i]) )   i++;
        else                        j--;
    }
    return str;
}

int main(){
    string str = "Hello";
    cout << str << endl;
    string rev_str = rev_Vowels(str);
    cout << rev_str << endl;
}