#include<iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;
    Node(int data): data(data) , next(NULL){}
    // Node(int data){
    //     this->data = data;
    //     this->next = NULL;
    // }
    ~Node(){
        cout << "dtor called and node deleted with value : " << this->data << endl;
    }
};


int len_LL(Node* &head ){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp= temp->next;
    }
    return len;
}

void insertH(Node* &head ,int data){

    Node* newNode = new Node(data);        // create a new node with the data to be inserted at head
    newNode->next = head;                  // point new node ka next to current head  
    head = newNode ;                       // change the head to newNode created making it the start of Linked list
}

void insertT(Node* &head, int data){

    Node* newNode = new Node(data);     // create a new node with data to be inserted at the end of LL 
    Node* tail = head;                  // create a tail pointer to access the end element of LL
    while(tail-> next != NULL){                
        tail = tail->next;              //tail reaches the last element after this tail-> next == NULL;
    }                                   // exits loop tail-> next == Null 

    tail->next = newNode;               // point the tail->next = newNode ;
}

void insertAtPositon(Node* &head, int data, int pos){
    
    Node* newNode = new Node(data);     // create a new node 
    Node* temp = head;                  // create a temp to iterate to the inserting pos
    if (pos == 1) {
        newNode -> next = head;
        head = newNode;
        return;
    }

    else if( pos < 1 || pos > len_LL(head) + 1 ){       // bcuz if len = 5 and inserting pos is 5 means add at the end of LL which is valid
        cout << "position out of range !!" << endl;
        delete newNode;                                 // in case positon is out of range free memory ;
        
    }

    for (int i = 1; i < pos-1 && temp != NULL ; i++){     //one pos before the exact point at  which node to be inserted
        temp = temp-> next;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
    

}

void delete_from_pos(Node* &head, int pos){
    
    // 3cases 
    // delete from empty LL
    if(head == NULL){
        cout << "deletion not possible , empty LL" << endl;
        return;
    }
    if(pos == 1){
        // delete from head 
        Node* temp = head;                  // temp to access positons  
        head = temp->next;                  // move head to temp -> next
        temp->next = NULL;                  // isolate the temp node from LL by pointing to null
        delete temp;                        // free memory 
    }
    else if( pos == len_LL(head)){
        //delete from tail or end pos 
        Node* temp = head ;
        Node* tail = head ;
        while(tail->next != NULL ){
            temp = tail;
            tail = tail -> next;              
        }                                   // exits loop when tail-> next == NULL & temp->next = tail;
        temp->next = NULL;                  // point the second last node(i.e, temp ) to NULL 
        delete tail;                        // delete tail free pointer 
        tail = temp;                        // re point the tail to new tail i.e, temp ;
    }
    else{
        Node* prev = NULL ;                 // pointer to be used to bridge the gap due to deleted element 
        Node* todelete = head ;             // pointer to navigate to the positon of deletion 
        for(int i = 1 ; i < pos ; i++){     // loop iterates to the position
            prev = todelete ;               // prev points to todelete 
            todelete = todelete->next;      // actual position of elemeent to delete
        }
        prev->next = todelete->next ;       // point the prev -> next = todelete->next
        todelete->next = NULL ;             // to isolate the deleting element from LL 
        delete todelete;                    // free memory 
    }
}


void del_element(Node* &head, int element){
    
    Node* tail = head;
    while(tail->next != NULL){
            tail = tail->next;
    }                           //this finds tail
    
    
    if(head->data == element){ // element to be deleted is at head only
        Node* temp = head;
        head = temp-> next;
        temp->next = NULL;
        delete temp;
        return ;
    }
    

    else {
        Node* todelete = head;
        Node* pre_todelete = NULL;

        while(todelete->next != NULL){
            if(todelete->data !=  element ){
                pre_todelete = todelete;
                todelete = todelete->next;
            }
            else{
                // aab delete-> data == element hai 
                pre_todelete->next = todelete->next;
                todelete->next = NULL;
                delete todelete;
                return;
            }
        }

        // handling the tail case 
        if(todelete->next == NULL ){    //  element may be or not at tail 
            if(todelete->data == element ){
                pre_todelete->next = todelete->next;
                todelete->next = NULL;
                delete todelete;
                return;
            }

        }
        cout << "element not present in LL " << endl;
        return;
    }
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
    Node* n1 = new Node(10);
    Node* head = n1;

    
    insertT(head, 20);
    insertT(head, 30);
    insertT(head, 40);
    
    printLL(head);
    cout <<"Length of LL : " << len_LL(head) << endl;
    
    insertAtPositon(head, 202, 4);
    printLL(head);
    cout << "Length of LL : " << len_LL(head) << endl;
    
    // delete_from_pos(head , 5);
    // printLL(head);
    // cout <<"Length of LL : " << len_LL(head) << endl;
    
    // delete_from_pos(head , 3);
    // printLL(head);
    // cout <<"Length of LL : " << len_LL(head) << endl;
    
    del_element(head , 50);
    printLL(head);
    cout <<"Length of LL : " << len_LL(head) << endl;

}