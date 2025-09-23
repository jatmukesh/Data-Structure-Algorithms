#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){
    string name ;

    cout << "Enter name : " ;
    //cin >> name;
    
    //taking input as a whole line or with spaces and tabs
    //use getline function --> getline( cin , string_name );
    
    getline(cin , name);
    
    
    cout << "Name : " << name << endl;
    cout << "Name at index 0 : " << name[0] << endl;

    int index = 0;

    while(name[index] != '\0'){
        cout << index << name[index] << endl;
        index ++;
    }
    cout << "Char at index : " << index << " is " << name[index] << endl;
    int value_of_null = (int)name[index]; 
    cout << " null char ascii value : " << value_of_null << endl;

}