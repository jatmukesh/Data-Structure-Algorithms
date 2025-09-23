#include<iostream>
using namespace std;

void quickSort(int arr[],int start,int end){
    //base case
     if( start> end )   return ;
     int pivot = end ;
     int i  = start-1;
     int j = start;
     
     while(j < pivot ){
        if(arr[j] < arr[pivot]){
            ++i;
            swap(arr[i],arr[j]);
        }
        j++;
     }
     ++i;
     swap(arr[i], arr[pivot]);
     quickSort(arr, start,i-1);
     quickSort(arr, i+1, end);
}

int main(){
    int arr[] = { 5,4,1,2,5,6,3 };
    quickSort(arr,0, 6);
    
    for(auto i : arr){
        cout << i << "  ";
    }

}