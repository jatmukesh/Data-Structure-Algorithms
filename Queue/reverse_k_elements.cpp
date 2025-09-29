#include<iostream>
#include<stack>
#include<queue>
using namespace std; 

void print_q(queue<int> q){
    while(!q.empty()){
        cout << q.front() << "  ";
        q.pop(); 
    }
    cout << endl;
}

    void reverse_k_elements(queue<int> &q, int k ){
        
        // step 1 : move k elements from q to stack
        // step 2 : push the k elements from stack to queue
        // step 3 : push the first n-k elements from the queue to its back
        
        // step 1 : move k elements from q to stack
            stack<int> s;
            int i = k ;
            while( i>= 1){
                s.push(q.front());
                q.pop();
                i--;
            }

        // step 2 : push the k elements from stack to queue
            while(i<=k){
                q.push(s.top());
                s.pop();
                i++;
            }
            
        // step 3 : push the first n-k elements from the queue to its back
                cout << q.size()<< endl;
            for(int i= 0 ; i< q.size()-k; i++ ){
                int temp = q.front();
                q.pop();
                q.push(temp);
            }    
    }
int main(){
    queue<int> q ;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    print_q(q);

    //reversing the k elements of the q 
    reverse_k_elements(q, 3);
    print_q(q);
}