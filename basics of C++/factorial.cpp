#include<iostream>
using namespace std;

int factorial( int n ){
    if ( n == 0 || n == 1)      return 1;
    else                        return n * factorial( n - 1 );
    
}

int main(){

    int num;
    cout << "Enter the number: ";
    cin >> num;

    cout << "The Factorial of Number '" << num << "' is: " << factorial( num );

}