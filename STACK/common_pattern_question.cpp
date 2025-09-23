#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st,int &pos,int  &ans){
    // base case
    if(pos == 1){
        ans = st.top();
        return ;
    }
    
    // 1 case
    pos-- ;
    int temp = st.top();
    st.pop();

    // recursion
    solve(st,pos,ans);

    //backtracing 
    st.push(temp);

}

// find middle 
int find_middle(stack<int> &st){
    if(st.empty()){
        cout << " stack empty" <<endl;
        return -1 ;
    }  
    else{
        int size = st.size();
        int pos = size&1 ? size/2 + 1 : size/2 ;    // for even and odd size pos of mid
        int ans = -1 ;
        solve(st,pos, ans);
        return ans;
    }
}
//insert at bottom
void IAB(stack<int> & st, int element){
    // base case
    if(st.empty()){
        st.push(element);
        return ; 
    }

    // 1 case mai solve karunga
    int temp = st.top();
    st.pop();

    // recursion
    IAB(st, element );

    // backtracing 
    st.push(temp);


}


// reverse_Stack()

void reverse_stack(stack<int> & st){
    // base case 
    if(st.empty()){
        return ;
    }
    
    // 1 case mai solve karunga
    int temp = st.top();
    st.pop() ;

    // recursion 
    reverse_stack(st);

    // backtracing 
    IAB(st,temp);

}

void insertSorted(stack<int> &st, int element ){
    // base case 
    if(st.empty() || element> st.top()){
        st.push(element );
        return ;
    }

    // 1 case mai karunga 
    int temp = st.top();
    st.pop();

    //recursion 
    insertSorted(st, element);

    //backtracing 
    st.push(temp);
}


void sort_stack(stack<int> &st){
    //base case 
    if(st.empty()){
        return ;
    }

    // 1 case 
    int temp =st.top();
    st.pop();

    // recursion
    sort_stack(st);

    //back tracing 
    insertSorted(st, temp);

}


int main(){
    stack<int> st ;
    st.push(10);
    st.push(5);
    st.push(12);
    st.push(8);
    st.push(9);

    // int middle_element = find_middle(st);
    // cout << "middle element is : "<< middle_element << endl;

    IAB(st, 5);
    //insertSorted(st, 15);
    sort_stack(st );
    
    
    
    while(!st.empty()){
        cout << st.top() << " " ;
        st.pop();
    }
    cout << endl;

    // reverse_stack(st);

    // while(!st.empty()){
    //     cout << st.top() << " " ;
    //     st.pop();
    // }
    // cout << endl;

}