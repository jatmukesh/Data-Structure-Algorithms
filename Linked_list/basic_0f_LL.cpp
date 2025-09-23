#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(){
        this->next = NULL;
    }
    Node(int _data){
        this-> data = _data;
        this-> next = NULL;
    }
};

void printLL(Node * head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " " ;
        temp = temp-> next ; 
    }
}

int main(){


    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    head -> next = second ;
    second -> next = third ;
    third -> next = fourth ;

    printLL(head);

}