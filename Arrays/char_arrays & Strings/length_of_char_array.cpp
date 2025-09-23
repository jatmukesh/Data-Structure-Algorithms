#include<iostream>
#include<string.h>

using namespace std;

int find_length(char ch[] , int  size){
    int index = 0 ;
    while(ch[index] != '\0'){
        index++;
    }
    return index;
}

int main(){
    char ch[100];
    cout << "enter ch : " ;
   // cin >> ch;

    //we can even take  long string lines as input that contains tabs and spaces using this
    cin.getline(ch ,100);    


    // int len = find_length(ch , 100 );
    int len = strlen(ch);                           // inbuild function to give len of strings 
    cout << "the entered ch is : " << ch << endl;
    cout << "length of ch is : " << len << endl ;
}