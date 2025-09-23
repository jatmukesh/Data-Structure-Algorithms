#include<iostream>
#include<string.h>
#include<vector>
#include <numeric>
using namespace std;

int  findCollectionTime( vector<string> garbage ,vector<int> travel){
    vector<int> timeP(3,0) ;
    vector<int> timeT(3,0) ;
    vector<int> last_occ(3,0) ;
    int total_time = 0;

    for(int i = 0; i < garbage.size();i++ ){
        string current = garbage[i];
        for(auto ch : current){
            if(ch == 'G'){
                timeP[0] += 1;
                last_occ[0] = i;
            }
            else if(ch == 'P'){
                timeP[1] += 1;
                last_occ[1] = i ;
            }
            else if(ch == 'M'){
                timeP[2] += 1;  
                last_occ[2] = i;              
            }
        }
    }

    for(int i = 0 ; i < last_occ[0]; i++){
        timeT[1] += travel[i];
    }
    
    for(int i = 0 ; i < last_occ[1]; i++){
        timeT[1] += travel[i];
    }

    for(int i = 0 ; i < last_occ[2]; i++){
        timeT[2] += travel[i];
    }
    total_time = accumulate(timeP.begin(),timeP.end(),0) + accumulate(timeT.begin(),timeT.end(),0) ; 

    return total_time;
}

int main(){
    vector<string> garbage = { "G" ,"P","GP","GG" };
    vector<int> travel = { 2,4,3 };

    int time = findCollectionTime(garbage , travel);
    cout << "time : " << time <<endl;
    
     
}