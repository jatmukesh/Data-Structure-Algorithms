#include<iostream>
using namespace std; 

class abc 
{
    public:
    static int x ; 
    void print()    
    {
        cout << x << endl;
    }

    static void print2(){

        // has no (this-) pointer 
        cout << "we are in static print2 " << endl;
    }

};

int abc :: x;

int main(){

    abc obj1;
    obj1.x = 1;

    obj1.print();
    obj1.print2();
    abc :: print2();   // can use even without creating instance object 
    abc obj2;
    obj2.x = 10;

    obj2.print();
    obj2.print2();
   



}