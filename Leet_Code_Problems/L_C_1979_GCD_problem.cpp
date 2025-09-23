#include<iostream>
#include<string.h>
#include<vector>
#include <algorithm>
#include <cmath>
using namespace std;

int findGCD(int &a , int &b){
    if ( a == 0)         return b;
    else if ( b = 0)     return a;

    while (a > 0 && b > 0 ){
        if((a-b)> 0 ) a -= b;
        else    b -= a;
    }
    return a == 0 ? b : a ;
}

int main(){
    int arr[] = { 24,72,55 };
    int a = *min_element(arr, arr+3);
    int b =  *max_element(arr, arr+3);
    cout << a << "  "  << b <<endl;
    int gcd = findGCD(a,b);
    cout << gcd;
}