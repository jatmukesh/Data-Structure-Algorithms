#include<iostream>
using namespace std;

int main(){
    //Half diamond pattern
  
    int n = 5;
    
    for(int i = 0; i < 2*n-1; i++){
        
        /*
        int condition = 0;
        if(i < n){
            condition = i;
        }
        else{
            condition = n - (i%n) -2; 
        }
        */        

        int condition = i < n ? i : n - (i % n) -2;

        for(int j = 0; j <= condition; j++){
            cout << "* "<<" ";
        }
            cout << endl ;
    }


}