#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Factorial(int n){
    
    vector<int> ans;
    ans.push_back(1);
    
    for(int i = 2; i <= n; i++){             //iteration (i) ->    (2)      (3)     (4)     (5)
        int carry = 0 ;
        for(int j = 0; j < ans.size(); j++){ //iteration (j) ->    (0)      (0)     (0)     (0)    (1)
            int x = ans[j] * i + carry;                      //     2        6       24      20     10+2=12
            ans[j] = x % 10 ;                                //     2        6       4       0      2
            carry = x / 10 ;                                 //     0        0       2       2      1
                                             //ans[j]               2        6       4       0      2  and carry = 1 pushback
        
        
        }                                     
        while( carry ){
        ans.push_back(carry % 10);
        carry /= 10;
        }
    }
    reverse( ans.begin(), ans.end());
    cout << " The factorial of " << n << " is : " ; 
    for( auto i : ans){
        cout << i ;
    }
}
int main(){
    int n = 5;
    Factorial(n);
}