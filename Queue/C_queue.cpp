#include<iostream>
using namespace std;

class Cqueue{
    public:
    int *arr ;
    int size ;
    int front ;
    int rear ;

    Cqueue(int size){
        arr = new int[size];
        this->size = size ;
        front = -1; 
        rear = -1 ;
    }

    void push(int val){
        //overflow
        if((front == 0 && rear == size -1) || (rear == front -1) ){
            cout << "overflow" << endl;
            return ;
        }
        // empty
        else if(front == -1 && rear == -1){
            rear++;
            front++;
            arr[rear] = val ;
        }
        //circular
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = val ;
        }

        // normal 
        else {
            rear++ ;
            arr[rear] = val ; 
        }
    }

     int q_size(){
        if(front == -1 && rear == -1){
            cout << "empty queue" << endl;
            return 0 ;
        }
        return rear-front+1 ;
    }
   
    void pop(){
        //empty 
        if(front == -1 && rear == -1){
            cout << "underflow" << endl;
            return ;
        }
        // single element 
        else if(rear == front ){
            arr[front] = -1;
            front = -1 ;
            rear = -1 ;
        }
        else if(front == size-1){
            arr[front] = -1;
            front = 0;
        }

        //normal
        else{
            arr[front] = -1 ;
            front ++ ;
        }
    }

    int front_element(){
        if(front == -1 && rear == -1){
            cout << "empty queue" << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }
    int rear_element(){
        return arr[rear];
    }
   

    void print_q(){
        cout << "Queue is : " ;
        for(int i = 0 ; i < size ; i++){
            cout << arr[i] << " " ;
        }
        cout << endl;
    }

};


int main(){
    Cqueue q(5) ;
     q.push(10);
     q.print_q();
    cout << "Size of Queue : " << q.q_size() << endl;
    q.push(20);
    q.print_q();
    cout << "Size of Queue : " << q.q_size() << endl;
    q.push(30);
    q.print_q();
    cout << "Size of Queue : " << q.q_size() << endl;
    q.push(40);
    q.print_q();
    cout << "Size of Queue : " << q.q_size() << endl;
    q.push(50);
    q.print_q();
    cout << "Size of Queue : " << q.q_size() << endl;

    q.pop();
    q.print_q();
    cout << "Size of Queue : " << q.q_size() << endl;
  
    q.push(60);
    q.print_q();
    cout << "Size of Queue : " << q.q_size() << endl;
  
}