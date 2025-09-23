#include<iostream>
using namespace std;

int set_k( int n , int k){
    int mask = 1 << k;
    int ans = n | mask;
    return ans;
}

int main(){

    int num ;
    int k ;
    cout << " Enter the number and value of k : ";
    cin >> num >> k ;

    cout << "the output after setting '"<< k <<"' th bit is: " << set_k( num,k );

}