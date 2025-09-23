#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

bool isPalindrome(char ch[]){
    //length of string -->  strlen()
    int n = strlen(ch);
    int i = 0 , j = n-1;

    while(i <= j){
        if(ch[i] == ch[j]){
            i++, j--;
        }
        else    return false;

    }
    return true;

}

int main(){

     char ch[100];
    cout << "enter string : " ;
    cin >> ch;
    if(isPalindrome(ch)){
        cout << "The entered string " << ch << " is Valid Palindrome " ;

    }
    else
        cout << "The entered string " << ch << " is Not a Valid Palindrome " ;

}