#include<iostream>
#include<queue>
using namespace std;

class Tree_Node{
    public:
        int data ; 
        Tree_Node* left ;
        Tree_Node* right ;

        // constructor
        Tree_Node(int data ){
            this->data = data ; 
            this->left = nullptr ;
            this->right = nullptr ;
        }
};

Tree_Node* createTree(){

    // cin the node from user
    int data ; 
    cout << "Enter the node value (-1 for no node ) : " ;
    cin >> data ;

    // base condition 
    if(data == -1)  return NULL ;
    
    // creating a node with the value data 
    Tree_Node* root = new Tree_Node(data) ;

    // recursive calls for left and right child of the node until they are nulled
    cout << "Enter the left child of ' " << root->data << " ' : " << endl;  
    root->left = createTree();      // this will create all the left sub trees
    cout << "Enter the right child of ' " << root->data << " ' : " << endl;
    root->right = createTree();      // then this will create all the right sub trees

    return root ;               // this will return a pointer to the root node of the tree
}

void pre_order_traversal(Tree_Node* root_node){

    // base case 
    if(root_node == nullptr)    return;

    // NLR  handling the current node N
    cout << root_node->data << " " ;

    // left child call 
        pre_order_traversal(root_node->left) ;

    // left child call 
        pre_order_traversal(root_node->right) ;

}

void level_order_traversal(Tree_Node* root){
    // base case
    queue<Tree_Node*> q;
    q.push(root) ;

    //
    while(!q.empty()){
        Tree_Node* temp = q.front() ;
        q.pop() ;

        // cout joh bhi front pe tha 
        cout << temp->data << " " ;

        // push the left and right child of the temp node into the queue
        if(temp->left != nullptr )      q.push(temp->left) ;
        if(temp->right != nullptr)       q.push(temp->right) ;
    }

}



void level_order_traversal_level_wise(Tree_Node* root){
    // base case
    queue<Tree_Node*> q;
    q.push(root) ;
    q.push(NULL) ;

    //
    while(!q.empty()){
        Tree_Node* temp = q.front() ;
        q.pop() ;
        if(temp == NULL){
            cout << endl ;
            if(!q.empty())
                q.push(NULL) ;
        }
        else{
            // cout joh bhi front pe tha 
            cout << temp->data << " " ;
    
            // push the left and right child of the temp node into the queue
            if(temp->left != NULL )      q.push(temp->left) ;
            if(temp->right != NULL)       q.push(temp->right) ;
        }
    }   

}

int max_depth(Tree_Node* root){
    
    // base case
    if(root == NULL)        return 0 ;
    
    // handling 1 case 
    int left_Height = max_depth(root->left); 
    int right_Height = max_depth(root->right); 
    int max_height = 1 + max(left_Height,right_Height); 
    
        return max_height ;
}

int main(){

    // Tree_Node* root_node = new Tree_Node(10) ;

    Tree_Node* root_node = createTree() ;

    cout << "Pre-order Traversal : " ;
    pre_order_traversal(root_node) ;
    cout << endl;
    cout << "level-order Traversal : " ;
    level_order_traversal(root_node);
    cout << endl;
    cout << "level-order Traversal level wise : " << endl ;
    level_order_traversal_level_wise(root_node);
    cout << endl;
}
