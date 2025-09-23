#include<iostream>
#include<string.h>
#include<vector>
#include <numeric>
#include <cmath>
using namespace std;

// void solve(int* p){ // pass by value 
//   p=p+1;
// cout << p<<endl;
// }


void solve(int* &p){ // pass by refrence 
  p=p+1;
cout << p<<endl;
}


int main(){
   
   /*
    int a = 5; 
    cout << "value of a : " << a << endl;
    cout << " address of a : " << &a << endl;
  //  cout << " value of a : " << *a << endl;           this (*a) is invalid operation  "cant dereference an integer"
    
    
    //creating a pointer variable to hold the address of 'a'
    int* ptr = &a ;
    //accessing pointer data 
    cout << "value stored in ptr : " << ptr << endl ;
    cout << "value at the address location stored in ptr : " << *ptr << endl;
    cout << " address of ptr itself : " << &ptr << endl;
 
    int** ptr2 = &ptr;          // this stores the address of pointer ptr
    cout << " value stores is address of ptr : " << *ptr2 << endl;

    //size of operator with ptr
    cout << sizeof(ptr) << endl;

    //arithmatic of pointers
    cout << "post increment of value stored at ptr content : " << (*ptr)++ << endl;      // 5+1 -> 6
    cout << "value stores is address of ptr : " << *ptr << endl;                         // printing new value of *ptr

    cout << "pre increment of value stored at ptr content : " << ++(*ptr) << endl;       // 1+6 -> 7 in the same line 
    cout << "value stores is address of ptr : " << *ptr << endl;                         // printing new value of *ptr

    cout << "value stored at ptr content : " << (*ptr)/2 << endl;                        // 7/2 -> 3 in the same line 
   
    cout << "value stored at ptr content : " << (*ptr - 2) << endl;                      // 1+6 -> 7 in the same line 


    //pointer copying
    int* ptr_new = ptr ;     // naya pointer joh usse element ke address ko point karta hua jisko ptr kar rha hai            

    //new pointer that points to the same address as of ptr
    cout << " value of ptr_new : " << *ptr_new << endl;
*/

/*
    int arr[] = { 10,20,30,40,50 };
    
    // we can access the base or starting address of the arary using 3 ways 
    cout << " base address of arr : " << arr << endl;
    cout << " base address of arr : " << &arr << endl;
    cout << " base address of arr : " << &arr[0] << endl;
    cout << " address of 1st index : " << arr+1 << endl;
    
    // access value of array using pointers             integer arrays 
    cout << " value at 0th index of  arr : " << arr[0] << endl;
    cout << " value at 0th index of  arr : " << *arr << endl;           //dereferencing the value at 0th index of arr gives : 10
    cout << " value at 0th index of  arr : " << *arr+1 << endl;
    cout << " value at 0th index of  arr : " << *(arr) + 1 << endl;
    cout << " value at 1st index of  arr : " << *(arr+1) << endl;
    cout << " value at 2nd index of  arr : " << *(arr+2) << endl;
    cout << " value at 2nd index of  arr : " << 2[arr] << endl;  // prints element at 2nd index -> this is evaluated same as *(arr + 2)---arr[2]
    cout << " size of arr in bytes : " << sizeof(arr) << endl;

*/
    
    // // access value of array using pointers             charr arrays 
    // char ch[50] = "mukesh" ; 
    // char* cptr = ch ;
    

    // cout << " base address of ch : " << &ch << endl;
    // cout << " value : " << ch << endl;
    // cout << " value : " << cptr << endl;
    // cout << " value : " << cptr+2 << endl;
    // cout << " value : " << cptr[0] << endl;
    // cout << " value : " << *cptr << endl;
    // cout << " value : " << *(cptr+0) << endl;
    //  cout << " value : " << *(ch+0) << endl;
 

     // array of pointers and pointer to an array

     int nums[5] = { 1,2,3,4,5  };

   // accessing will be using pointer notation 
     int (*ptr_arr)[5] = &nums ;
   
     cout << (*ptr_arr)[1] << endl;
     cout << (*ptr_arr)[0] << endl;
     
     // accessing will be done using array notation
     int* ptr_arr2[5] ;
     ptr_arr2[2] = &nums[2];
     ptr_arr2[4] = &nums[3];

    cout << *ptr_arr2[2] << endl;
    cout << *ptr_arr2[4] << endl;


    //pointer to pointer 
    int x = 10 ;
    int* p1 = &x;
    int** p2 = &p1;
    int*** p3 = &p2;
    int**** p4 = &p3;


    cout << x << endl;
    cout << *p1 << endl;  
    cout << **p2 << endl;    
    cout << ***p3 << endl;  
    cout << ****p4 << endl;  

    int* p = &x; 
    int** q = &p;
  
    cout << x << endl;    //10
    cout << &x << endl;   //address of x
    cout << p << endl;    //address of x
    cout << &p << endl;   //address of p
    cout << *p << endl;   //value of x -> 10
    cout << q << endl;    //address of p
    cout << &q << endl;   //address of q
    cout << *q << endl;   //adress of x
    cout << **q << endl;  //value of x -> 10

    cout << p<< endl;
    solve(p);
    cout << *p<< endl;
  
  }