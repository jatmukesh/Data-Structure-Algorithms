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

int len_LL(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

Node* rev_k_Group(Node* head, int k ){
   // base case
    if(head == NULL || head->next == NULL)   return head;
    if(len_LL(head) < k)         return head;

   // 1 case

   int pos = 0 ;
   Node* prev = NULL ;
   Node* curr = head ;
   Node* nextNode = curr->next ;
   while(pos < k){
    curr->next = prev;
    prev = curr;
    curr = nextNode ;
    if(curr != NULL)     nextNode = curr->next ;
    pos++;
   }

   // recursion 
   if(curr != NULL){
        Node* ans  = rev_k_Group(curr , k);
        head->next = ans ;
    }
        return prev ;
}


int main(){
    int k = 2;
    Node* head = new Node(10);
    insertT(head, 20);
    insertT(head, 30);
    insertT(head, 40);
    insertT(head, 50);
     insertT(head, 60);
    
    printLL(head);

    Node* newHead = rev_k_Group(head , k);
    printLL(newHead);


}