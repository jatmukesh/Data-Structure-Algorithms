#include<iostream>
using namespace std;

void separate_0_1(int arr[], int size ){
    
    int low = 0;
    int high = size -1;
    
    while(low < high ){

        while( arr[ low ] == 0 && (low < high) ){
            low++;
        }
    while( arr[ high ] == 1 && (low < high) ){
            high++;
        }

    swap( arr[ low ], arr[ high ]);
    
    }
    for(int i =0; i < size; i++ ){
        cout << arr[ i ] << " ";
    }
}

int main(){

    int arr[ 10 ] = { 0,1,0,1,0,0,1,1,1,0 };
    int size = 10;    
    separate_0_1( arr,size );

}