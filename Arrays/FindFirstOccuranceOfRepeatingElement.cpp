#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

int FindFirstOccurance_BruteForce(int arr[], int n){
    for( int i = 0; i < n; i++){
        for( int j = i+1; j < n; j++){
            if( arr[i] == arr[j]){
                return i+1;
            }
        }
    }
    return -1;
}

int FindFirstOccurance_HashMap(int arr[], int n){
   /*
   we can also create a custom hashmap for this 
   we can use an array that have highest index value equal to the largest value in given array i.e, arr[] = { 1,5,3,4,3,5,6 }
   as highest value is " 6 " we will create an array that has highest index as " 6 "     i.e,  hashmap[7] = {               }
    since highest index is 6 size == ' 7 '                                                      index     ->[ 0 1 2 3 4 5 6 ]
   */
   
    int hashmap[ 7 ] = { 0 };       //initialize the hashmap array with zeros
    for(int i = 0; i < n; i++){
        hashmap[arr[i]]++;
    }
    for( int i = 0; i < n; i++){
        if( hashmap[arr[i]] > 1 )
            return i+1;
    }
    return -1;
   
    /*
    //using prebuild maps    
    unordered_map< int,int >hash_map;
    for( int i = 0; i < n; i++){
        hash_map[arr[i]]++;
    }
    for( int i = 0; i < n; i++){
        if( hash_map[arr[i]] > 1 )
            return i+1;
    }
    return -1;
    */
}

int main(){

    int arr[] = { 1,2,1,4,3,5,6 };
    int n = sizeof(arr)/sizeof(arr[0]);
  
   

    cout << " Element Reapeated is at : " << FindFirstOccurance_HashMap(arr, n);
}