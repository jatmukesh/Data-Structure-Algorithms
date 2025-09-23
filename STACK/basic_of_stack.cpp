#include<iostream>
#include<stack>
using namespace std;

int main(){
    // creating stack with name st
    stack<int> st ;

    // inserting element in stack 
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    
    // size of stack 
    cout << "Size of stack is : " << st.size() << endl;

    // top most element in the stack
    cout << "top most element in stack is : " << st.top() << endl;

    // removal of element always happens from the top
    st.pop();
    cout << "top most element in stack is : " << st.top() << endl;

    // checking is stack empty or not 
    cout << (st.empty() ? "the stack is empty "  :  "the stack is not empty ") << endl; 

}