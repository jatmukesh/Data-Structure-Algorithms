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

int lenLL(Node* &head){
    Node* temp = head ; 
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void printLL(Node* &head){
    Node* temp = head;
    cout << "LL : " ;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout <<" NULL "<<endl; 
}

void insert_H(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insert_T(Node* &head, int data){
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insert_at_position(Node* &head,int data, int pos){
    if(pos < 1 || pos > lenLL(head)+1){
        cout << "position out of range !!" << endl;
        return;
    }
    
    Node* newNode = new Node(data);
    Node* pre = NULL;
    Node* post = head;
    for(int i = 1; i< pos ; i++){
        pre = post ;
        post = post->next;
    }
    newNode->next = post;
    newNode->prev = pre;
    pre->next = newNode; 
    post->prev = newNode;

}

void delete_from_pos(Node* &head, int pos){

    //empty LL 
    if(head == NULL){
        cout<<  "cant delete ,empty LL " << endl;
        return;
    }
    //from head 
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp ;
    }

    else if(pos == lenLL(head)){
        Node* tail = head;
        Node* temp = head;
        while(tail->next != NULL){
            temp = tail;
            tail = tail->next;
        }
        temp->next = NULL ;
        tail->prev = NULL;
        delete tail;
        tail = temp;
    }
    else{
        Node* pre = NULL;
        Node* post = head;
        for(int i = 1; i< pos ; i++){
            pre = post ;
            post = post->next;
        }
        pre->next = post->next;
        post->next->prev = pre;
        post->next= NULL;
        post->prev= NULL;
        delete post;
    }
}

void del_element(Node* &head , int element){
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next ;
    }                           // this finds tail
    
    // at head 
    if(head->data == element ){
        Node* temp = head ;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp ;
        return ; 
    }
    else{
        Node* pre_todelete  = NULL;
        Node* todelete = head ;  
        while( todelete->next != NULL ){
            if(todelete->data != element){
                pre_todelete = todelete;
                todelete= todelete->next;
            }
            else{
                // todelete at position where element is found 
                Node* post_todelete = todelete->next;   // new point next to the node to be deleted to easily bridge the LL
                pre_todelete->next =  post_todelete;
                post_todelete->prev = pre_todelete ;
                todelete->next= NULL;
                todelete->prev = NULL;
                delete todelete;
                return;
            }
        }

        if(todelete->next == NULL){
            //tail case : element at the tail 
            // this means todelete is pointing to tail now
            if(todelete->data == element){
            pre_todelete->next = todelete->next;         //automatically points last element ot NULL
            tail = todelete->prev ;
            todelete->prev = NULL;
            delete todelete ;
            return ;
            }
        }
    }
    cout << "element not present in LL "<<endl;
}


int main(){
    //creating a doubly LL ;
    Node* head = new Node(20);
    insert_H(head, 10);
    printLL(head);
    insert_T(head, 40);
    printLL(head);
    insert_at_position(head, 30 , 3);
    printLL(head);
    cout <<"length of LL : "<< lenLL(head)<<endl;


    // delete_from_pos(head, 3);
    // printLL(head);
    // cout <<"length of LL : "<< lenLL(head)<<endl;

    del_element(head, 40);
    printLL(head);
    cout <<"length of LL : "<< lenLL(head)<<endl;

}