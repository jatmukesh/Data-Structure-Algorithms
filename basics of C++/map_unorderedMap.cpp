#include<iostream>
#include<string.h>
#include<map>
#include<algorithm>
#include <unordered_map>
using namespace std;

int main(){
    map< string ,int > mp = {{"mukesh" , 4},{ "xyz" , 5}};


    mp.insert({"abc" ,7});
    pair<string ,int> pair1 = make_pair("rahul", 6);
    pair<string , int> pair2( "aa" , 12);
    mp.insert(pair1);
    mp.insert(pair2);

    cout << mp.at("abc") << endl;
    cout << mp["aa"] << endl;
    
    cout << mp.count("mukesh") << endl;

    if( mp.find("mukesh")!= mp.end()){
        cout << (*(mp).find("mukesh")).second << endl;

    }

}