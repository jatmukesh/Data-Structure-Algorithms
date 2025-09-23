#include<iostream>
#include<stack>
#include<vector>
using namespace  std ;

vector<int> next_small(int *arr , int size , vector<int> &ans){
    stack<int> st ;
    st.push(-1);
    int index = size -1;

    while(index >= 0){
        int curr = arr[index];
        while(st.top() >= curr){
            st.pop();
        }
        ans[index] = st.top();
        st.push(curr);
        index--;
    }
    return ans;
}


vector<int> prev_small(int *arr , int size , vector<int> &ans){
    stack<int> st ;
    st.push(-1);
    int index = 0;

    while(index < size){
        int curr = arr[index];
        while(st.top() >= curr){
            st.pop();
        }
        ans[index] = st.top();
        st.push(curr);
        index++;
    }
    return ans;
}


int main(){
    int arr[5] = { 8,4,6,2,3 };
    int size = 5;
    for(auto i : arr){
        cout << i << " " ;
    }
    cout << endl ;
    

    vector<int> ans(size);
    vector<int> prev_ans(size);
    
    
    ans = next_small(arr, size, ans);
    for(auto i : ans){
        cout << i << " " ;
    }
    cout << endl;
    prev_ans = prev_small(arr, size, prev_ans);
    for(auto i : prev_ans){
        cout << i << " " ;
    }
      
}