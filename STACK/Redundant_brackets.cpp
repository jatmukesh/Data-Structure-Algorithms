#include<iostream>
#include<stack>
#include<string>
using namespace  std ;

bool check_redundant(string s){
    stack<int> temp ;
    for(char ch : s){
        if(ch == '(' || ch == '+' || ch == '-' ||ch == '*' || ch == '/'){
            temp.push(ch);
        }
        else{
            int count = 0;
            if(ch ==')' && temp.top() != '('){
                count++;
                temp.pop();
            }
            // yaha pe close bracket ke liye opening milega 
            if(count ==0  ) return true ;
            temp.pop();
        }
    }
    return false ;

}

bool isRedundant(string &s) {
    stack<char> st;

    for (char ch : s) {
        // push operators and '(' onto stack
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else if (ch == ')') {
            bool hasOperator = false;

            // check inside the brackets
            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/')
                    hasOperator = true;
                st.pop();
            }

            // pop the opening bracket
            if (!st.empty()) st.pop();

            // if no operator found → redundant
            if (!hasOperator) return true;
        }
    }
    return false;
}


int main(){
    string s = "((a+b)+(a+b))" ;

    if(isRedundant(s))  cout << "redundant brackets" ;
    else                    cout << " no redundant brackets ";  
}