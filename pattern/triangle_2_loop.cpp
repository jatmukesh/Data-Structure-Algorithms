#include<iostream>
using namespace std;

int main(){
    int N = 3;

    for(int i = 0; i < N; i++ ){
        for(int j = 0; j < (2*N-1); j++ ){
            if( j>= (N -1 - i) && j <= (N -1 + i))
                cout << "* ";
            else
                cout << "  ";
        }   
        cout << endl;
    }
}