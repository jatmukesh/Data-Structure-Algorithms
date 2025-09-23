#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

string removeAjacentDuplicates( string s){
    string temp = "";

    //    one liner same logic
    //    for(int i = 0; i < s.length(); (temp.back() != s[i]) ? temp.push_back(s[i]) : temp.pop_back() ,i++);
    for(int i = 0; i< s.length(); i++){
        if(temp.back() != s[i])
            temp.push_back(s[i]);
        else temp.pop_back();
    }
    return temp;
}


void remove_K_AjacentDuplicates( string s, int k){
    string ans ;
    vector<int> count ;
      for(int i = 0; i< s.size(); i++){
        ans.push_back(s[i]);
        if(ans.size() == 1 || ans[ans.size()-1] != ans[ans.size()-2])
            count.push_back(1);
        else 
            count.push_back(count.back()+ 1);
        if(count.back() == k){
            ans.erase(ans.end()- k ,ans.end());
            count.erase(count.end()-k ,count.end());

        }
    }
    cout << "The resultant string is : " << ans;
}


int main(){

    string s = "abbbaaca";

 //remove_K_AjacentDuplicates(s, 3);


    cout << "The resultant string is : " << removeAjacentDuplicates(  s);
}