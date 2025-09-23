#include<iostream>
#include<string.h>
#include<vector>
#include <numeric>
#include <cmath>
using namespace std;


// //brute force      complexity-> O(n^2) 
// bool isPrime(int n ){
//     if (n <= 1) return false;
//     for(int i = 2; i < n ; i++){
//         if( n % i == 0){
//             return false;
//         }              
//     }
//     return true;
// }
/*
sqrt method      complexity -> O(n* sqrt(n))
one of the factor of non prime number should be less than sqrt(n) i.e, a*b = n so a > sqrt(n) & b > sqrt(n) cant be true 
a or b one has to be less than sqrt(n)
*/
// bool isPrime(int n ){
//     if (n <= 1) return false;
//     for(int i = 2; i <= sqrt(n) ; i++){
//         if( n % i == 0){
//             return false;
//         }    
//     }
//     return true;
// }


// int countPrime(int N){
//     int count = 0;
//     for( int i =0 ; i < N ; i++){
//         if(isPrime(i)){
//             count ++;
//         }
//     }
//     return count;
// }


/*
3) -> using sieve eratosthenes
*/
/*
//normal sieve method
int countPrime(int N ){
    vector<bool> v(N , true);
    v[0]= v[1] = false;
    int count = 0;

    for(int i = 2; i< N ;i++){
    
        if(v[i]){
            count++;          
            int j = i*2;
            while(j < N){
                v[j] = false;
                j += i;
            }
        }
    }
    return count ;
}
*/

vector<bool> optimizedSieve(int n){
    vector<bool> sieve(n, true);
    sieve[0] = sieve[1] = false;
    for(int i= 2 ; i <= n; i++){
        if( sieve[i] == true){ 
            int j = i*i;
            while(j <= n){
                sieve[j] = false;
                j += i;
            }
        }
    }
    return sieve ;
}

vector<bool> seg_sieve(int left , int right){
    
    //base sieve that will be used to mark primes in the range left to right;
    vector<bool> sieve = optimizedSieve(sqrt(right));
    vector<int> base_primes ;
    for( int i =0 ; i<= sieve.size(); i++){
        if(sieve[i]){
            base_primes.push_back(i);
        }
    }
    //sieve to store the ans of the segmented left - right ;
    vector<bool> Seg_sieve(right -left +1, true);
    if(left == 0 || left == 1){
        Seg_sieve[left ] = false;
    }

    for(auto prime : base_primes){
        int first_mul = (left/prime)*prime ;
        if(first_mul < left){
            first_mul += prime;
        }
        int j = max(first_mul,prime*prime);
        while(j <= right){
            Seg_sieve[j - left] = false;
            j += prime;
        }
    }
    return Seg_sieve;

}

int main(){
    int L = 20 , R = 30;
     vector<bool> ans = seg_sieve(L,R);
     for(int i = 0 ; i < ans.size() ; i++){
            if(ans[i] == true )
                cout << (i+L) << " " ;
     }
     cout <<endl;

}