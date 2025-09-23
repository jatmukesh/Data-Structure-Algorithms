#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool valid_Parenthesis(string &s){
    stack<char> st ;
    for(auto ch : s){
        if(ch== '{' || ch== '(' || ch== '['){
            st.push(ch);
        }
        else{
            if(st.empty())  return false ;
            else{
                if(ch == ')' && st.top() == '(')        st.pop();
                else if(ch == ']' && st.top() == '[')   st.pop();
                else if(ch == '}' && st.top() == '{')   st.pop();
                        
                else                                    return false;
            }
        }
    }
    return st.empty() ;
}

int main(){
    string s = "{{([{}])}}";
    
    cout << (valid_Parenthesis(s) ? "Valid parenthesis" : "Invalid parenthesis") << endl;
}