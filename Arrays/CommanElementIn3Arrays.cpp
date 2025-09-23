#include<iostream>
#include<vector>
#include <set>
using namespace std;

vector<int> CommanElement( int A[],int B[],int C[],int n1,int n2,int n3){
    vector<int> ans ;
    set<int> st;
    int i,j,k;
    i=j=k=0;
    while( i<n1 && j<n2 && k<n3 ){
        if( A[i]==B[j] && B[j]==C[k] ){
            st.insert(A[i]);       //here set is used to avoid getting a same repeated answer 
                                    // the set ensures even if elements are repeated it appears only one time 
            
            i++,j++,k++;
        }
        else if(A[i]<B[j])
            i++;
        else if(B[j]<C[k])
            j++;
        else    
            k++;
    }
    for( auto i : st){
        ans.push_back(i);
    }
    return ans;
}

int main(){

    int A[] = { 1,2,20,30,40 };
    int B[] = { 2,4,20,25,40 };
    int C[] = { 4,5,20,34,40 };


    vector<int> result = CommanElement(A, B, C, 5, 5, 5);
    cout << "The common Elements are : ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;
    
}