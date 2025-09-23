#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

void DecodedMessage(string message ,string key){
    //creating a mapping for key chars to letters in order
    char mapping[300] = {0}; // 0 to keep track of only one time mapping of chars  & arr length is greater then 256 cause 'a' -> 97 ascii and 'z' -> 122
    char start = 'a';

    for(auto ch : key){
        if( ch != ' ' && mapping[ch] == 0 ){
            mapping[ch] = start ;
            start++;
        }
    } 
    for(auto ch :mapping){
        cout << ch << "  " ;
    }
    cout << endl;
    //using the mapping for decoding using substitution 
    string ans ;
    for(auto ch : message){
        if(ch == ' '){
            ans.push_back(' ');
        }
        else{
            char decode = mapping[ch];
            ans.push_back(decode);
        }
    }

    cout << "Decoded message : " << ans << endl;

}


int main(){

    string message = "vkbs bs t suepuv";
    string key = "the quick brown fox jumps over the lazy dog";
    string message2 = "fiebgc dah";
    string key2 = "aehjkm stu";
    cout << "Message : " << message2 << endl;
    cout << "Key : " << key2 << endl;

   DecodedMessage(message ,key);
}