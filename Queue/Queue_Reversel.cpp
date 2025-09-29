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

void reversed_q(queue<int> &q){
    // base case 
    if(q.empty()){
        return ;
    }

    // handling case
    int temp = q.front();
    q.pop();

    // recursion 
    reversed_q(q);

    // backtracing after hitting base case
    q.push(temp);

}
int main(){
    queue<int> q ;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    print_q(q);

    reversed_q(q) ;

    print_q(q);

    
}