#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

void rev_string(char ch[]){
    int len = strlen(ch);
    int i = 0 , j = len-1;
    while(i <= j){
        swap(ch[i],ch[j]);
        i++;
        j--;
    }
    cout << ch;
}

void lowerCaseToUpperCase(char ch2[]){
       int len = strlen(ch2);
       int index = 0 ;
       
       while(ch2[index] != '\0'){
            char currentChar = ch2[index];
            if(currentChar >= 'a' && currentChar <= 'z'){
                ch2[index] = currentChar - 'a' + 'A';            //  m - a + A --> 'M'
            }
            index++;
       }
       cout << ch2;
}

void replace_Space(char ch2[]){
    int index = 0;
    while(ch2[index] != '\0'){
        if(ch2[index] == '@'){
            ch2[index] = ' ';
        }
        index++;
    }
    cout << ch2;

}
int main(){
    char ch[100] ,ch2[100];
    cout << "Enter string : "  ;
   // cin >> ch;
    cin.getline(ch2, 100);
   // rev_string(ch);

    //  int len = strlen(ch);  
    //  reverse(ch ,ch+len);       // inbuild stl function to reverse a string in algorithm library
    //  cout << ch;

     lowerCaseToUpperCase(ch2);
     cout << endl;
     replace_Space(ch2);
}