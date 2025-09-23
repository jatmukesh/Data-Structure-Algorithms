#include<iostream>
using namespace std;
bool FindElement(int arr[][4], int row ,int col,int target){
    int N = row*col;
    int s = 0 , e = N-1;
    int mid = s + (e-s)/2;
    while(s<= e){
        int rowIndex = mid/col;
        int colIndex = mid%col;
        int currentElement = arr[rowIndex][colIndex];
        if(currentElement == target )   return true;
        else if(currentElement < target ){
            s = mid+1;
        }
        else 
        e = mid -1;
         mid = s + (e-s)/2;
    }
    return false;
}


int main(){
    int arr[3][4]= {
        {1,2,3,4},
        {6,7,8,9},
        {11,12,14,16}
    };

    int target= 17;
    if(FindElement(arr,3,4,target))
    cout << "found ";
    else 
    cout << "not found";


}
