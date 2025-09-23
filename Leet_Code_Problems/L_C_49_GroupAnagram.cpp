
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

vector<vector<string>> groupAnagram(vector<string>& strs){
    vector<vector<string>> ans;
    map<string, vector<string> > mp;
    for(auto str : strs){
        string key = str;
        sort(key.begin(),key.end());
        mp[key].push_back(str); 
    }
    for(auto it = mp.begin(); it != mp.end();it++){
        ans.push_back(it->second);
    }

    return ans;
}

int main(){
    vector<string> strs = { "tea", "eat","ate", "tan","ant","bat" };
    vector<vector<string>> ans = groupAnagram(strs);
    for(auto group : ans ){
        for(auto word : group){
            cout << word << " ";
        }
        cout << endl;
    }
}