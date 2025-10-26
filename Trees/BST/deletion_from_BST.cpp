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

void inorder_traversal(Node* root){

    // base case
    if(root == NULL)    return ;
    
    // LNR 
    inorder_traversal(root->left) ;
    cout << root->data << " " ;
    inorder_traversal(root->right) ;

}

Node* max_node(Node* root){
    if(root == NULL )   return NULL ;
    Node* temp = root ;
    while(temp->right != nullptr){
        temp = temp->right ;
    }

    return temp ;
}


Node* deletion_from_BST(Node* &root, int target){
    // target ko dundho phele
    // then usko delete karo 

    if(root == NULL ){
        return NULL ;
    }

    if(root->data == target){
        // 4 cases
          //case 1 Node to be deleted is a leaf node
        if(root->left == NULL && root->right == NULL ){
            delete root ;
            return NULL ;
        } 
        else if(root->left != NULL && root->right == NULL ){
            Node* leftChildTree = root->left;
            delete root ;
            return leftChildTree ; 
        }
        else if(root->left == NULL && root->right != NULL ){
            Node* rightChidTree = root->right ;
            delete root ;
            return rightChidTree ;  
        }
        else{
            Node*  maxi = max_node(root->left);
            root->data = maxi->data ;  
            root->left = deletion_from_BST(root->left, maxi->data) ;
            return root ;    
        }
    }

    else if(target < root->data){
        root->left = deletion_from_BST(root->left, target);
    }
    else {
        root->right = deletion_from_BST(root->right, target);
    }
    return root ; 
    
} 

int main (){

    Node* root =NULL ;
    // function call to create the BST tree
    create_BST(root) ;
    
    cout << endl ;
    level_order(root);
    cout << endl ;
    
    int target ;
    cout << "Enter the target : " ;
    cin >> target ; 

    while(target != -1){
        root = deletion_from_BST(root, target) ; 
        cout << endl << "printing after deleting : " << target << endl ;
        level_order(root) ;
        cout << endl << "Enter next value to be deleted : " ;
        cin >> target ;
    }

}