#include<iostream>
using namespace std;

class Tree_Node {
    public:
        int data ;
        Tree_Node* left ;
        Tree_Node* right ;

        // constructor to initialize a tree node  ;
        Tree_Node(){
            this->left = nullptr ;
            this->right = nullptr ;
            //cout << "node created ! " << endl ;
        }
        
        //constructor to initial with value the tree nodes ;
        Tree_Node(int data){
            this->data = data ;
            this->left = nullptr ;
            this->right = nullptr ;
           // cout << "node created with data value : " << this->data << endl  ;
        }

};

// create a tree with values 
Tree_Node* create_Tree(){       // why Tree_Node type because it will return a pointer to the root or start of tree
    
    // taking input for each root by user 
    int val ;
    cout << "Enter the node value (-1 for leaf node) : " ;
    cin >> val;  
    
    // base case 
    if(val == -1 )      return nullptr ;

    // handling 1 case 
    Tree_Node* root_node = new Tree_Node(val) ;
        
    // recursive call for the left side of root_node 
    cout << "Enter the left child of node -> " << val << endl; 
    root_node->left = create_Tree() ;

    // recursive call for the right side of root_node 
    cout << "Enter the right child of node -> " << val << endl; 
    root_node->right = create_Tree() ;

    return root_node ;
}


void pre_order_traversal(Tree_Node* root){
    // pre order traversal : N L R
    // base case
    if(root == nullptr)     return ;

    // handling 1 case i.e, printing current node 
    cout << root->data << " "  ;

    // recursion call for left node
    pre_order_traversal(root->left); 

    // recursion call for right node
    pre_order_traversal(root->right);

}

void post_order_traversal(Tree_Node* root){
    // post order traversal : L R N
    // base case
    if(root == nullptr)     return ;

    // recursion call for left node         --> L
    pre_order_traversal(root->left); 
    
    // recursion call for right node        --> R
    pre_order_traversal(root->right);
    
    // handling 1 case i.e, processing the current node 
    cout << root->data << " "  ;         // --> N

}

void in_order_traversal(Tree_Node* root){
    // in order traversal :  L N R
    // base case
    if(root == nullptr)     return ;

    
    // recursion call for left node                     --> L
    pre_order_traversal(root->left); 

    // handling 1 case i.e, printing current node       --> N 
    cout << root->data << " "  ;
    
    // recursion call for right node                    --> R
    pre_order_traversal(root->right);

}



int main(){
    // Tree_Node* root_node = new Tree_Node(10);       
    // Tree_Node* node1 = new Tree_Node();
    // node1->data = 20 ;
    // root_node->left = node1 ;
    // Tree_Node* node2 = new Tree_Node(30) ;
    // Tree_Node* node3 = new Tree_Node(40) ;
    // Tree_Node* node4 = new Tree_Node(70) ;
    // root_node->right = node4 ;
    // node1->left =node2 ; 
    // node1->right =node3 ; 
    // pre_order_traversal(root_node) ;
    // cout << endl ;
    // post_order_traversal(root_node) ;
    // cout << endl ;
    // in_order_traversal(root_node);
    // cout << endl ;

    Tree_Node* tree_node = create_Tree() ;
    pre_order_traversal(tree_node) ;
    cout << endl ;
    
}

