#include<iostream>
#include<vector>

using namespace std;

int main(){

    // //creating vector or declaration 
    // vector<int> v;
    // cout << "size of given vector v is: " << v.size() << endl;      // when vector is initialized it has size and capacity == 0 
    // cout << "capacity of given vector v is: " << v.capacity() << endl;
    
    // // Initializing vector with values 
    // vector<int> a = { 1,2,3,4,5 };
    // cout << "size of given vector a is: " << a.size() << endl;          // here when the vector is initialized with 5 values 
    // cout << "capacity of given vector a is: " << a.capacity() << endl;  // then it acquires size = capacity == 5 
   
    // a.push_back(6);                                                     // and when we add any another element in it 
    // cout << "size of given vector a is: " << a.size() << endl;          // the size increases by the number of elements added and capacity is directly doubled
    // cout << "capacity of given vector a is: " << a.capacity() << endl;  // the size changes with push and pop operations but once the capacity is increased it stays as it 

    // for( int i = 0; i < a.size(); i++){
    //     cout << a[ i ] << " ";
    // }

    // // Initializing vector with single value and n size 
    // vector< int > b( 5, 0 );       // here even if we dont specify the value zero then too the vector is initialized with 5 zeros 
    // cout << "\n size of given vector b is: " << b.size() << endl;
    // for( int i = 0; i < b.size(); i++){
    //     cout << b[ i ] << " ";
    // }

    // // adding values using push_back (push_back function adds the values at the end/last of vector array)
    // v.push_back(2);
    // v.push_back(4);
    // v.push_back(6);
    // cout << "\n size of given vector v after inserting elements is: " << v.size() << endl;
    // cout << " capacity of vector v after inserting elements is: " << v.capacity() << endl;
    // for( int i = 0; i < v.size(); i++){
    //     cout << v[ i ] << " ";
    // }

    // // initializing vector from an array
    // int arr[ 5 ] = { 1,3,5,7,9 };
    // int n = sizeof(arr)/sizeof(arr[ 0 ]);
    // cout <<" size of array: " << n << endl;
    // cout << " value of arr+n is: " << arr+n << endl;
    
    // vector<int> c = { arr, arr + n };         //also we can use --> vector<int> c( arr, arr + n );
    // cout << "\n size of given vector c is: " << c.size() << endl;
    //   for( int i = 0; i < c.size(); i++){
    //     cout << c[ i ] << " ";
    // }
  
  
//     vector<int> s ={ 1,2,3 };
//     cout <<s.size() << endl;
//     cout <<s.capacity() << endl;
//    s.push_back(6);
//    cout <<s.size() << endl;
//    cout <<s.capacity();
//     return 0;
}