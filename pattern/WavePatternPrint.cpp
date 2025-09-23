#include<iostream>
#include<vector>

using namespace std;

void WavePattern( vector<vector<int>> A ){
    int m = A.size();  //size of rows
    int n = A[0].size(); // gives size/no of cols
    
    for (int startCol = 0; startCol < n; startCol++){
    // For even numbered cols -> Top to bottom
        if((startCol & 1 ) == 0 ){
        for(int i = 0 ; i < m ; i++ ){
            cout << A[i][startCol] << " ";
        }
        }
        // For odd numbered cols ->  bottom to Top 
        else{
            for(int i = m-1; i>=0; i--){
                cout << A[i][startCol] << " ";
            }
        }
    }
    
}


int main(){
    vector<vector<int>> A = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    cout << "Wave Pattern :\n";
    WavePattern(A);
}