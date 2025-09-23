#include<iostream> 
#include<queue>
using namespace std;

class Queue{
    public :
    int *arr ;
    int size ; 
    int front ;
    int rear ; 

    Queue(int size){
        arr = new int[size] ;
        this->size = size;
        front = -1 ;
        rear = -1 ;
    }

    //push 
    void push(int val){
        //overflow
        if(rear == size-1){
            cout << "overflow" << endl;
            return ;
        }
        //pushing in empty queue
        else if(front == -1 && rear == -1){
            front ++;
            rear++ ;
            arr[rear] = val ;
        }
        else{
            rear ++; 
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

    // queue<int> q ;
    // q.push(10) ;
    // q.push(20) ;
    // q.push(30) ;
    
    // cout << "Size of queue is : " <<  q.size() << endl;

    // cout <<(q.empty() ? " empty queue " : "queue is not empty") << endl;

    // cout << "first element of queue is : " <<  q.front() << endl;
    // cout << "last element of queue is : " <<  q.back() << endl;

    Queue q(5);

    q.push(10);
    cout << "Size of Queue : " << q.q_size() << endl;
    q.push(20);
    cout << "Size of Queue : " << q.q_size() << endl;
    q.push(30);
    cout << "Size of Queue : " << q.q_size() << endl;
    q.push(40);
    cout << "Size of Queue : " << q.q_size() << endl;
    q.push(50);
    cout << "Size of Queue : " << q.q_size() << endl;
    cout << q.q_size() ;

    q.pop();
    cout << "Size of Queue : " << q.q_size() << endl;
    cout << q.q_size() ;


q.pop();
    q.print_q();
    cout << "Size of Queue : " << q.q_size() << endl;

 cout << "front element of Queue : " << q.front_element() << endl;
cout << "last element of Queue : " << q.rear_element() << endl;
    
     q.pop();
      q.pop();
    

 cout << "front element of Queue : " << q.front_element() << endl;
cout << "last element of Queue : " << q.rear_element() << endl;

    // overflow as the queue is completely filled upto its size not more element can be pushed  
    q.push(60);
    cout << "Size of Queue : " << q.q_size() << endl;
    q.print_q();




}