#include<iostream>
#include<string.h>
using namespace std;

class Student{
    
    bool a;
    int c;
    int d;
    bool e;
    bool g;
   
};

int main(){
    /*
    size of any class is equal to the size of biggest datatype in it 
    say here we have 8 byte for double so the size will be -> (no of variables) * 8 bytes
                                                            -> 3*8 == 24bytes

    agaar 2 se zyada int type ke variables hai toh fir double ke size mai 2 int fit hojayega and 1 int ke liye 8 byte lagega
                                                        -> 8+8+8 == 24    
                                                        
    basically joh largest datatype hai uske multiple mai size hoga 
    i.e, double + int + int + int +bool
            8       4   4       4   1 -> 21
            SO 8 ke multiple mai size adjust hoga i.e 24                                                     
    */
   cout<< sizeof(Student); 
}