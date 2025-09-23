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


void printLL(Node* &head){
    Node* temp = head;                  // create a temp pointer tht will be used to traverse the LL
    cout << "LL : " ;
    while(temp != NULL){                // iterate till temp doest reach NULL -> end of LL
        cout << temp->data << " -> ";      // cout the data of the current node pointer by temp
        temp= temp -> next ;            // update the temp to temp ke next node ;
    }
    cout << "NULL" << endl;

}

void insertT(Node* &head, int data){

    Node* newNode = new Node(data);     // create a new node with data to be inserted at the end of LL 
    Node* tail = head;                  // create a tail pointer to access the end element of LL
    while(tail-> next != NULL){                
        tail = tail->next;              //tail reaches the last element after this tail-> next == NULL;
    }                                   // exits loop tail-> next == Null 

    tail->next = newNode;               // point the tail->next = newNode ;
}

Node* middleNode(Node* &head) {
    Node* slow = head;
    Node* fast = head;
        
    while (fast->next != NULL ) {
        fast = fast->next;    // moves 2 steps  NOTE: always move fast first then only move slow by 1 
        if(fast->next != NULL){
            fast = fast->next ;
            slow = slow->next;          // moves 1 step
        } 
    }
    
    return slow;

}



void rev_LL(Node* &head){
    Node* prev = NULL ;
    Node* curr = head ;
    
    
    while(curr != NULL){
        Node* nextNode = curr->next;        // points the next node to not lose track of LL
        curr->next = prev;                  // redirect the current node to prev node
        prev = curr;                        // move prev one node ahead to curr
        curr = nextNode ;                   // update the curr
    }
    head = prev;                            // reallocate the head to the prev which at this point points to the last element of LL (new head)

}

void printNode(Node* node){
    cout << "Node : " << node->data <<endl; 
}
bool comapre_LL(Node* head1 , Node* head2){
    while(head1 != NULL && head2 != NULL){
        if(head1->data != head2->data ){
            return false;
        }
        else {
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return true;
}

bool isPalindrome(Node* head){
    // find middleNode
    Node* temp = head ;
    Node* mid_Node = middleNode(temp);

    //break the LL 
    Node* head2 = mid_Node->next;
    mid_Node->next = NULL ;

    rev_LL(head2);
    printLL(head);
    printLL(head2);
    
    bool ans = comapre_LL(head, head2);
    return ans;
}

int main(){
    Node* head = new Node(10);
    insertT(head, 20);
    insertT(head, 30);
    insertT(head, 30);
    insertT(head, 20);
    insertT(head, 10);
    
    printLL(head);

    cout << "MiddleNOde is ->" ;
    printNode(middleNode(head));
    cout << endl;
    if(isPalindrome(head)){
        cout << "palindrome!!" << endl;
    }
    else{
        cout << "Not palindrome!!" << endl;
    }
}