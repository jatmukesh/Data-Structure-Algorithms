#include<iostream>
using namespace std;

void even_odd( int num ){
    if( num%2 == 0 ) cout << " Even ";
    else cout << " Odd ";
}

//using bitwise operator
/* 
    the lest significant bit of any even number is 0 
    and that of odd number is 1
    if we bitwise AND 1 and the num we get the resultant 
    i.e, ( num & 1 ) --> 1 for odd number 
         ( num & 1 ) --> 0 for even number
*/
void even_odd_bitwise( int num ){
    if( num & 1 ) cout << " Odd ";
    else cout << " Even ";
}

int main(){

    int num;
    cout << "Enter number: " ;
    cin >> num ;

    cout << " The entered number " << num << " is:" ;
    even_odd_bitwise( num );
}