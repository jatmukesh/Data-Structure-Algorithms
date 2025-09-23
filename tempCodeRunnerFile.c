#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

string longestCommon_Prefix(vector<string>& strs) {
        string ans ;
        int i = 0 ;
        while(true){
            char curr_ch = 0;
            for(int j = 0 ; j < strs.size(); j++){
                string curr_str = strs[j]; // currently for j = 0 at flower next j = 1 -> flow
               
                if( i >= curr_str.size() ){
                    // out of bound
                    curr_ch = 0;
                    break;
                }

                if( curr_ch == 0 ){
                    //just started          initializing the process with 1st char of 1st string
                     curr_ch = curr_str[i];
                }

                else if(curr_str[i] != curr_ch){
                    curr_ch = 0;
                    break;
                }
            }
            //here the for loop rotates and j++ happens

            if(curr_ch == 0){
                break;
            }
            // till here curr_ch -> has 'f' in it 
            ans.push_back(curr_ch);
            i++;    //  i++ will get the next 
        }
        return ans;        
    }


int main(){

    vector<string> strs = { "mukesh" ,"mukeshjat", "mukeshj" };

    string ans = longestCommon_Prefix(strs);

    cout << " longest common prefix : " << ans;
}