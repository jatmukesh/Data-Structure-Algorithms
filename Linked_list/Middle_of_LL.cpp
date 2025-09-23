#include<iostream>
using namespace std;
 
// creating a node for doubly LL 
class Node{
    public:
    int data ;
    Node* prev ;
    Node* next ;

    // ctors
    Node(){
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data ){
        this->prev = NULL;
        this->data = data ;
        this->next = NULL;
    }
    ~Node(){
        cout << "dtor called to delete node with value : " << this->data << endl;
    }

};




// Node* middleNode(Node* &head) {
//     Node* slow = head;
//     Node* fast = head;
        
//     while (fast != NULL && fast->next != NULL) {
//         fast = fast->next->next;    // moves 2 steps  NOTE: always move fast first then only move slow by 1 
//         slow = slow->next;          // moves 1 step
//     }
    
//     return slow;

// }

// same method  with a bit different approachh 
/* 
    while(fast != NULL){                  phele check karo fast != NULL hai kya
    //satisy 
    fast = fast->next ;                   move fast one step ahead
    if(fast != NULL){
        fast = fast-> next ;              this moves fast now by one more step means fast has moved by 2 steps now
        slow = slow ->next ;              abb fast 2 step move hogaya that means slow bhi 1 step badega   

        basically this approach says agar fast 2 step se aage baad sakta hai toh he slow ek step chalega 
    }


*/
Node* middleNode(Node* &head) {
    Node* slow = head;
    Node* fast = head;
        
    while (fast != NULL ) {
        fast = fast->next;    // moves 2 steps  NOTE: always move fast first then only move slow by 1 
        if(fast != NULL){
            fast = fast->next ;
            slow = slow->next;          // moves 1 step
        } 
    }
    
    return slow;

}



void printNode(Node* node){
    cout << "Node : " << node->data <<endl; 
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


int main(){
    Node* head = new Node(10);
    insertT(head, 20);
    insertT(head, 30);
    insertT(head, 40);
    insertT(head, 50);
    
    printLL(head);

    cout << "MiddleNOde is ->" ;
     printNode(middleNode(head));
}