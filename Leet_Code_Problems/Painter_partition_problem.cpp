#include<iostream>
#include<numeric>
using namespace std;

bool isPossibleSolution(int board_time[],int n,int k,int sol){
    int time = 0;
    int painter = 1;
    for(int i =0 ; i < n;i++){
        if(board_time[i]> sol)  return false;
        else if(time+ board_time[i] > sol){
            painter++;
            time = board_time[i];
            if(painter > k) {
                 return false;
            }   
        }
        else {
            time+= board_time[i];
        }
    }
    return true;
}

int Find_Time(int board_time[],int n,int k){
    
    if(k>n) return -1;          //corner condition 

    int start= 0 ;
    int end = accumulate(board_time,board_time+n, 0);
    int ans = -1;
    while(start <= end ){
        int mid = start + (end-start)/2;
        if(isPossibleSolution(board_time,n,k,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }

    }
    return ans;
}

int main(){
    int board_time[] = { 10,20,30,40 };
    int n = 4;
    int k = 2;
    int ans = Find_Time(board_time,n,k);

    cout << "minimum time wil be : " << ans;
}