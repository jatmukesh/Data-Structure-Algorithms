#include<iostream>
#include<vector>

using namespace std;

void RemoveDuplicateTwoPointerMethod(vector<int> v ){           //Two pointer approach  Time Complexity -> O(n)
    int i = 1;
    int j = 0;
    while( i < v.size() ){
        
        if( v[ i ] == v[ j ])   i++;
        else v[ ++j ] = v[ i++ ];
        // else{
        //     j++;
        //     v[j] = v[i];
        //     i++;
        // }
       
    }
    cout << " \nTotal number of unique elements : " << j+1 << endl ;
    v.resize( j+1 );                                        //this shrinks the vector array only upto the unique values 
    cout << "Array with No Duplicates : " ;
    for( auto i : v){
        cout << i << " ";
    }
}

void RemoveDuplicateRemoveMethod(vector<int> v ){           //Two pointer approach  Time Complexity -> O(n^2)
    int i = 1;
    int j = 0;
    while( i < v.size() ){
        if(v[i] == v[j]){
            v.erase(v.begin() + i );                       // the TC increase as erase method has TC -> O(n)
        }
        else{
            i++;
            j++;
        }
    }
    cout << "Total number of unique elements : " << j+1 << endl ;
    cout << "Array with No Duplicates : " ;
    for( auto i : v){
        cout << i << " ";
    }
}
int main(){
    vector<int> v = { 0,0,1,1,1,2,2,3,3,4 };
    RemoveDuplicateRemoveMethod( v );
    RemoveDuplicateTwoPointerMethod(v);
}