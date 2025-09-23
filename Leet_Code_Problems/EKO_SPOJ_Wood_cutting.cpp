#include<iostream>
#include<algorithm>
using namespace std;

int brute_Force(int trees[], int N , int M ){
    int H = 1;
    int ans = -1;
    while( H < 20){                             //1-> 20 is the search space for height
       
        int obtained_height = 0;
       
        for(int i = 0 ; i < N ; i++){
            if(trees[i]-H > 0 ){                // this if checks if tree height is less than the raised saw then its uncutted; 
                obtained_height += trees[i]-H ; // calcualtes the height of wood jacks gets to carry home 
            }
        
        }
        if(obtained_height >= M ){              // checks jacks requirement is meet by deciding the saw height
            ans = H ;
        }
        else{
            return ans ;
        }
        H++;
    }
    return ans;
}

// predicate function for B_S
bool isValid(int tress[], int N , int M, int sol){         
   
    int obtained_height = 0 ;                         //checks whether the obtained obtained_height >= M
    for(int i = 0; i<N ;i++){
        
        if(tress[i] - sol > 0){
            obtained_height += tress[i] -sol ;
        }
       
    }
       
    if(obtained_height >= M){                   // now this here returns true for >= M
            return true;
    }
        
    else return false;
}


// Binary search approach 
int find_height(int trees[], int N , int M ){
    int start = 1, end = *max_element(trees, trees+N);
    int ans = -1;

    while(start <= end ){
        
        int mid = start + (end - start )/2;

        if(isValid(trees , N , M ,mid )){       //if isValid return true this block stores ans and move to the right part of sol
            ans = mid ;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans ;
}


int main(){
    int trees[] = { 20 ,15,10,17 };
    int N = 4 , M = 7;

    int ans = find_height( trees,N,M);
    cout << "the max height of saw is : " << ans<< endl;

}