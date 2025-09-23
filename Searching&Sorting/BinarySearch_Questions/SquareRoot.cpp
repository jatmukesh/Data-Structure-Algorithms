#include<iostream>
using namespace std;


/*
     0 1 2 3 4 5 6 7 8 


*/



int SquareRoot(int N ){
    int start = 0 , end = N;
    long long int mid = start + (end- start)/2;
    int ans = -1 ;
    while( start <= end){
        if(mid*mid == N )   return mid;
        else if(N > mid*mid){
            ans = mid;
            start = mid + 1;
        }
        else 
            end = mid -1;
        mid = start + (end -start)/2;
    }
    return -1;
}

double precisionSqrt( int n ){
    
    double sqrt = SquareRoot( n );
    double step = 0.1;
    int precision = 5 ;    //precision upto 5 decimal places

    for( int i = 0; i < precision;i++){
        double j = sqrt;
        while(j*j <= n){
            sqrt = j;
            j += step;
        }
        step /= 10;
    }
    return sqrt;

}

int main(){
    int N = 51 ;
    double root = precisionSqrt( N );
    cout << " The Sqaure Root is : " << root << endl;
}