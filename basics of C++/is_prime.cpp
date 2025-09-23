#include<iostream>
#include <cmath>
using namespace std ;

bool is_prime( int n ){
/*
    for(int i =2; i < n; i++){
          if( n % i == 0 )        return false; 
    }

    we can optimize the code by iterating the for loop till sqrt of num 
    i.e, sqrt( n ) 
*/
    
    for(int i =2; i < sqrt( n ); i++){
          if( n % i == 0 )        return false; 
    }
    
    return true;
}

int main(){
    int num;
    cout << " Enter the number: " ;
    cin >> num ;
  
    if( is_prime( num ))        cout << " The entered number "<< num <<" is Prime ";
    else                        cout << " The entered number "<< num <<" is Not prime "; 
    //printing all the primes from 1 to num
    cout << "\n The prime numbers are: ";
    for(int i = 2; i <= num; i++){
    
        if( is_prime( i ))        cout << i << " ";
       // else                        cout << " The entered number is Not prime "; 
    }

}