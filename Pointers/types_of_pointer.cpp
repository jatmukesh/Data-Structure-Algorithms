#include<iostream>
#include<string.h>
#include<vector>
#include <numeric>
#include <cmath>
using namespace std;
/*

types of pointer-> 1. Wild pointer
                   2. Void pointer
                   3. Dangling pointer
*/

/*
When a void pointer is declared in C++, it is a pointer that does not have an associated data type.  
This means it can store the memory address of any variable, 
regardless of its data type (e.g., int, float, char, or even a custom struct or class).
However, because it lacks type information, a void pointer cannot be directly dereferenced
or used for pointer arithmetic. To access the data it points to, 
or to perform operations on that data, the void pointer must first be explicitly typecast to a pointer 
of a specific data type. This typecast informs the compiler about the size 
and interpretation of the data at the memory address the void pointer holds.
*/

int main(){
    // void* void_ptr;     // declare kardo void pointer 
    // int x = 10;         // koi bhi datatype ka variable declare karo 

    // void_ptr = &x;      // fir void pointr ko waha point karwa do
    // int* int_ptr = static_cast<int*>( void_ptr );       //  abb type casting use karke void_ptr ko data ka type bata do 
    //                                                     //  so that compiler  ko pata lage kese interpret karna hai

    // cout << void_ptr << endl;       // hold the address of x
    // cout << int_ptr << endl;        // int type pointer jo same address of x ko point karta hai 
    // cout << *int_ptr << endl;       // deference karke value print kardo
    // //cout << *void_ptr << endl;      // not possible kyuki compiler ko pata he nhi data kis type ka hai toh print nhi karsakta:


/*

Dynamic memory allocation is performed in C++, 
when the size of memory needed is not known at compile time then we perform Dynamic memory 
Allocation using operators like new or malloc.
 Void pointers can be used to allocate memory for any data type.
  In C++, "new" keyword is used for dynamic memory allocation which returns a pointer to the allocated memory. 
After allocating memory, We need perform type casting to use the allocated memory with a specific data type.

*/

void* void_ptr1 = new int ;                         // allocating dynamic memory for integer (new)-> keyword memory allocated karke address return karta hai waha ka 

int* int_ptr1 = static_cast<int*>(void_ptr1);       // allocated memory location ko access karne ke liye int* type ka pointer 

*int_ptr1 = 10; // setting value to the pointed location

cout << *int_ptr1 << endl;      //yaha koi static varible use nhi kiya hai just dynamic memory banake pointer ke help se value asign kardi  
} 