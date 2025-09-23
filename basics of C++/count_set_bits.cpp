#include<iostream>
using namespace std;

int convert_binary(int n){
    int ans = 0 ;
    int bit_place = 1;
    int count = 0;
    while( n > 0 ){
        int bit = n % 2;
        if( bit )       count++;
        ans = ans + bit_place * bit;
        bit_place *= 10;
        n = n / 2;
    }
    return count;
}

int bit_method( int n ){
    int count = 0 ;
    while( n > 0 ){

        int bit = n & 1 ;
        if( bit )   count++ ;
        n = n >> 1 ;

    }
    return count ; 
}

int main(){
    int num;
    cout << " Enter the num: ";
    cin >> num;

    cout << "the binary equivalent is : " << bit_method( num ) << endl;
    cout << "the binary equivalent is : " << convert_binary( num ) << endl;
}