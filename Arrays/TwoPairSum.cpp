#include<iostream>
using namespace std;

bool TwoPointerApproach(int arr[], int n, int TargetSum ){      // it has time complexity of ( nlogn )
    int low = 0 ; 
    int high = n-1 ;
    while( low < high ){
        int Csum = arr[ low ] + arr[ high ];  //stores the current sum
        
        if( Csum == TargetSum )     return true;  // if the target sum is obtained
        
        else if( Csum > TargetSum ){        // here if csum is greater than we reduce or shift high to low side
            high-- ;
        }
        else {
            low++ ;                         // here if csum is lesser than we increase or shift low to high side
        }
    }
    return false;
}

void sortArray(int arr[], int n, bool ascending = true) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap based on order
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(){
    int arr[] = { 1,4,45,6,10,8 };
    int n = 6;
    //sorting the given order in ascending order
 sortArray( arr, n,true );

   if( TwoPointerApproach( arr, 6, 15 ) ){
    cout << "The pair is present ";
   }
   else cout << "The pair is  not present ";
}