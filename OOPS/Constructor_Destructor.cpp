#include<iostream>
#include<string.h>
using namespace std;

class Student{
    public:
        int id;
        string name;
        
        // default constructor by the compiler looks like this 
        //it is called when the instance of a class is created;
        // the constructor creates and assigns the values to the variables 
        //by default it assigns garbage values 
        Student(){
            cout << "default constructor is called "<< endl;
        }

        //parameterised constrcutor 
        Student(int _id , string _name){
            id = _id;                   // we can also use this-> id = _id to assign  
            name= _name;
            cout << "parameterised constructor called" << endl;
        }

        //Copy constructor 
        Student( Student &src_obj ){
            cout << "copy constructor " << endl;
             id = src_obj.id;
             name = src_obj.name;
        }
   
};

int main(){
    Student s1;                             // default constructor is called
    
    Student s2(01, "mukesh");               // parameterized constructor is called
    //for student s2
    cout<< " ID : "  << s2.id << " name : " << s2.name << endl;
    
    Student s3(s2);    //  can also write as s3 = s2 ;              // copy constructor is called
    //for student s3
    cout<< " ID : "  << s3.id << " name : " << s3.name << endl;
    
}