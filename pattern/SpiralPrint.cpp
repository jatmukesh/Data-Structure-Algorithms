#include<iostream>
#include<vector>

using namespace std;


void SpiralPrint(vector<vector<int>> A){
    vector<int> ans;
    int m = A.size();
    int n = A[0].size();
    int total_elements = m*n;

    int StartingRow = 0;
    int EndingCol = n-1;
    int EndingRow = m-1;
    int StartingCol = 0;
    int count = 0;

    while(count < total_elements){
        // printing the StartingRow
        for( int i = StartingCol ; i <= EndingCol && count < total_elements; i++){
            ans.push_back(A[StartingRow][i]);
            count++; 
        }
        StartingRow++;

        // printing the EndingCol
        for( int i = StartingRow ; i <= EndingRow && count < total_elements; i++){
            ans.push_back(A[i][EndingCol]);
            count++; 
        }
        EndingCol--;
        // printing the EndingRow
        for( int i = EndingCol ; i >= StartingCol && count < total_elements; i--){
            ans.push_back(A[EndingRow][i]);
            count++; 
        }
        EndingRow--;
         // printing the StartingCol
         for( int i = EndingRow ; i >= StartingRow && count < total_elements; i--){
            ans.push_back(A[i][StartingCol]);
            count++; 
        } 
        StartingCol++;
    }

    for( auto i : ans ){
        cout << i << " ";
    }
}

int main(){
    vector<vector<int>> A = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout << "Spiral Pattern :\n";
    SpiralPrint(A);
}