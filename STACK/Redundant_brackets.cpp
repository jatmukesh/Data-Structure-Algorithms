#include<iostream>
#include<stack>
#include<string>
using namespace  std ;
bool check_redundant(string s) {
    stack<char> temp;
    for (char ch : s) {
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            temp.push(ch);
        } 
        else if (ch == ')') {
            bool operator_found = false;

            // Pop until '('
            while (!temp.empty() && temp.top() != '(') {
                char top = temp.top();
                if (top == '+' || top == '-' || top == '*' || top == '/')
                    operator_found = true;
                temp.pop();
            }

            // Pop the '('
            if (!temp.empty()) temp.pop();

            // If no operator found → redundant brackets
            if (!operator_found) return true;
        }
    }
    return false;
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
    string s = "(((a+b)(a+b)))" ;

    if(check_redundant(s))  cout << "redundant brackets" ;
    else                    cout << " no redundant brackets ";  
}