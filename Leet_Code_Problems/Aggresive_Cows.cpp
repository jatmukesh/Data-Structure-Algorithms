#include<iostream>
#include <algorithm> // For max_element and min_element

using namespace std;

bool isPossibleSolution(int stalls[]  ,int N ,int K ,int sol){
    int pos = stalls[0];
    int cow = 1;
    for(int i = 1; i< N ;i++){
        if((stalls[i] - pos) >= sol ){
            cow++;
            pos = stalls[i];
        }
        if(cow == K )   return true ;
    }
    return false ;
}

int Find_placement(int stalls[],int N, int K){
    int start = 0 , end = *max_element(stalls,stalls+N) - *min_element(stalls,stalls+N);
    int ans = -1 ;
    while(start <= end ){
        int mid = start + (end - start)/2;

        if(isPossibleSolution(stalls  ,N ,K ,mid)){
            ans = mid ;
            start = mid +1;
        }
        else {
            end = mid -1;
        }

    }
    return ans;
}

int main(){
    int stalls[] = { 1,2,4,8,9 };
    int N = 5 , K = 3;

    int ans = Find_placement(stalls,N,K);

    int val = *max_element(stalls,stalls+N) - *min_element(stalls,stalls+N);
    cout << val << endl;

    cout << "the placement with best allocation is : " << ans ;
}