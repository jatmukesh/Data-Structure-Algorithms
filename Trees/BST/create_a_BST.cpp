#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data ; 
        Node* left ;
        Node* right ;
        
        Node(int data){
            this->data = data ;
            this->left = nullptr ;
            this->right = nullptr ; 
        }
};

Node* insert_into_BST(Node* root, int data){
    if(root ==  NULL ){                         // first node start of BST
        root = new Node(data) ;
        return root ;
    }

    // for the rest of the BST
    if(data > root->data){
        root->right = insert_into_BST(root->right, data);
    }
    else{
        root->left = insert_into_BST(root->left, data);
    }

    return root ;
}

void create_BST(Node* &root){
    cout << "Enter the data : " ;
    int data ; 
    cin >> data ;
    
    while(data != -1){
        cout << "Enter data : " ;
        root = insert_into_BST(root, data) ;
        cin >> data ;
    }
}

void level_order(Node* root){
    queue<Node*> q ;
    q.push(root) ;
    q.push(NULL) ;

    while(!q.empty()){
        Node* front = q.front() ;
        q.pop() ;

        if(front == NULL ){
            cout << endl ; 
            if(!q.empty()){
                q.push(NULL) ;
            }
        }
        else{
            cout << front->data << " " ;
            if(front->left != NULL )    q.push(front->left) ;
            if(front->right != NULL )    q.push(front->right) ;
        }
    }

}

int main (){

    Node* root =NULL ;
    
    // function call to create the BST tree
    create_BST(root) ;

    cout << endl ;
    level_order(root);
    
    
}