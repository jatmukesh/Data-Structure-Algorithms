#include<iostream>
using namespace std;

struct Node{
    int data ; 
    Node* next;

    Node(int data){
        this->data = data ;
        this->next = NULL ;
    }
};

Node* rev_LL(Node* &head ){
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        Node* nextNode = curr->next;
        curr ->next = prev;
        prev = curr;
        curr = nextNode ; 
    } 
    head = prev;
    return head;
}
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

void add_One(Node* &head){
    // rev LL
    head = rev_LL(head);
    
    // add 1 
    Node* temp = head;
    int carry = 1;
    while(temp->next != NULL){
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;
        temp->data = digit;
        temp = temp->next;
        if(carry == 0){
            break;
        }
    }
    // process last node 
    if( carry != 0){
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum/10;
        temp->data = digit;
        if(carry != 0){
            Node* newNode = new Node(carry);
            temp->next = newNode ;
        }
    }

    rev_LL(head);


}

int main(){
    Node* head = new Node(9);
    insertT(head, 9);
    insertT(head, 9);
    
    printLL(head);

    add_One(head);
      printLL(head);




}