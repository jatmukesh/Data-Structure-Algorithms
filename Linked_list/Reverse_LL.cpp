#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next; 

    //ctor
    Node(int data){
        this->data = data; 
        this->next = NULL;
    }
};


void insertT(Node* &head, int data){

    Node* newNode = new Node(data);     // create a new node with data to be inserted at the end of LL 
    Node* tail = head;                  // create a tail pointer to access the end element of LL
    while(tail-> next != NULL){                
        tail = tail->next;              //tail reaches the last element after this tail-> next == NULL;
    }                                   // exits loop tail-> next == Null 

    tail->next = newNode;               // point the tail->next = newNode ;
}


void printLL(Node* &head){
    Node* temp = head;                  // create a temp pointer tht will be used to traverse the LL
    cout << "LL : " ;
    while(temp != NULL){                // iterate till temp doest reach NULL -> end of LL
        cout << temp->data << " -> ";      // cout the data of the current node pointer by temp
        temp= temp -> next ;            // update the temp to temp ke next node ;
    }
    cout << "NULL" << endl;

}


void rev_LL(Node* &head){
    Node* prev = NULL ;
    Node* curr = head ;
    
    
    while(curr != NULL){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode ; 
    }
    head = prev;
    
}


int main(){
    Node* head = new Node(10);
    insertT(head, 20);
    insertT(head, 30);
    insertT(head, 40);
    insertT(head, 50);
    
    printLL(head);

    rev_LL(head);
    printLL(head);


}