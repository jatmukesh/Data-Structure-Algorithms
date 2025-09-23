#include<iostream>
using namespace std; 

void segragrateNegPos(int arr[], int size){
    int j = 0,index = 0 ;
    while(index < size ){
        
        if( arr[ index ]< 0){
            swap(arr[index ], arr[ j ]);
            j++;
        }
        index++;
    }

    for(int i = 0; i < size; i++){
        cout << arr[i] << " " ;
    }
}

//Dutch National Flag algorithm ( DNF algorithm )

void sort0_1_2( int arr[], int size ){
    
    int index = 0 ,left = 0, right = size-1; 
    while( index <= right ){
        if(arr[ index ]== 0 ){
            swap( arr[index] , arr[left ]);
            left++;
            index++;
        }
        else if( arr[ index] == 2){
            swap( arr[index], arr[ right]);
            right --; 
            index++;  
        }
        else{
            index++ ;
        }
    }

    for(int i = 0; i < size; i++){
        cout << arr[i] << " " ;
    }
}


int main(){
  //  int arr[] = { 23,-7,0,12,-10,-11,40,60,0 };
   int arr[] = { 0,2,2,1,0,1,0,1 };
     int size = sizeof(arr)/ sizeof( arr[0]);

   // segragrateNegPos(arr, size);
   cout << " \nBefore sorting : ";
   for(int i = 0; i < size; i++){
        cout << arr[i] << " " ;
    }

    cout << " \nAfter sorting : ";
    sort0_1_2(arr, size);
}