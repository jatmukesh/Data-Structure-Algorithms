#include<iostream>
using namespace std;

class Stack{
    public:
        int* arr; 
        int size;
        int top1;
        int top2;

        //ctor
        Stack(int size){
            arr = new int[size];
            this->size = size;
            top1 = -1;
            top2 = size ;
            for(int i = 0; i< size; i++){
                arr[i] = 0;
            }
        }

        //member functions
        void push1(int data){
            if(top2-top1 == 1){
                cout << "stack 1 OVERFLOW " << endl;
            }
            else{
                top1++;
                arr[top1] = data;
            }
        }
        void push2(int data){
            if(top2-top1 == 1){
                cout << "stack 2 OVERFLOW " << endl;
            }
            else{
                top2--;
                arr[top2] = data;
            }
        }

        void pop1(){
            if(top1 == -1){
                cout << "stack 1 underflow " << endl;
            }
            
            else{
                arr[top1] = 0;
                top1--;
            }
        }
        void pop2(){
            if(top2 == size){
                cout << "stack 2 underflow " << endl;
            }
            else{
                arr[top2] = 0;
                top2++;
            }
        }
        //top element of stacks
        int at_top1(){
            return arr[top1];
        }

        int at_top2(){
            return arr[top2];
        }

        //printing stack
        void print_stack(){
            cout << "top1 at : " << top1 << endl;
            cout << "top2 at : " << top2 << endl;
            
            for(int i = 0 ; i < size ; i++){
                cout << arr[i] << "  " ;
        }
        cout << endl;
        }

        
};

int main(){

    Stack st(6);

    //insertion in stack
    st.push1(10);
    st.push1(20);
    st.push2(100);
    st.push2(200);
    st.push2(300);
    st.push2(400);
    st.push2(500);
    st.print_stack();

}