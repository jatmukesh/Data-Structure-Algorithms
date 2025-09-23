#include<iostream>
using namespace std;

int rev( int n ){
    
    if( n <= INT_MIN ){
        return 0;
    }
    
    bool isNeg = false;
    if( n < 0 ){
        isNeg = true;
        n = -n; // n = abs(n)
    }
    int ans = 0;
    while( n > 0){
        if(ans > INT_MAX / 10){
            return 0;
        }
        int rem = n % 10;
        ans = ans*10 + rem ;
        n /= 10;
    }
    return isNeg ? -ans : ans ;
}

int main(){
    int num;
    cout << "Enter the number: ";
    cin >> num;
    cout << " The reverse of number '" << num << "' is: " << rev( num );
    
    

}