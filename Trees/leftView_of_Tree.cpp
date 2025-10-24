#include<iostream>
#include<vector>
#include<unordered_map>
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

Tree_Node* create_Tree(){
    // Enter the first node of tree
    cout << "\nEnter the Node val : " ;
    int data ;
    cin >> data ;
    
    if(data == -1 ) return nullptr ;

    Tree_Node* curr_Node = new Tree_Node(data);

    // ENter the left child of the current node
    cout << "Enter the left child of : " << curr_Node->data << " : " ;
    curr_Node->left = create_Tree() ;
        // ENter the left child of the current node
    cout << "Enter the right child of : " << curr_Node->data << " : " ;
    curr_Node->right = create_Tree() ;
    
    return curr_Node ; 
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

void leftViewSeen(Tree_Node* root , int level , vector<int>& leftView){

    if(root == NULL )   return ;

    if(level == leftView.size()){
        leftView.push_back(root->data);
    }

    leftViewSeen(root->left, level+1 , leftView);
    leftViewSeen(root->right, level+1 , leftView);

}

void rightViewSeen(Tree_Node* root , int level , vector<int>& rightView){

    if(root == NULL )   return ;

    if(level == rightView.size()){
        rightView.push_back(root->data);
    }

    rightViewSeen(root->right, level+1 , rightView);
    rightViewSeen(root->left, level+1 , rightView);

}

void top_view(Tree_Node* root){

    unordered_map<int,int> hash_map ;
    queue< pair<Tree_Node* , int >> q ;         // this store node and its vertical/horizontal distance 

    q.push(make_pair(root , 0 ));

    while(!q.empty()){
        pair< Tree_Node* , int> front_element = q.front();
        q.pop() ;
        Tree_Node* front_Node = front_element.first ;
        int hd = front_element.second ;         // hd is horizontal distance 

        if(hash_map.find(hd) == hash_map.end()) {  // means no entry yet
            hash_map[hd] = front_Node->data ;
        }

        if(front_Node->left != NULL)    q.push(make_pair(front_Node->left,hd-1));
        if(front_Node->right != NULL)    q.push(make_pair(front_Node->right,hd+1));
    }

    for(auto it : hash_map){
        cout << it.second << " " ;
    }
    cout << endl ; 
}



void bottom_view(Tree_Node* root){

    unordered_map<int,int> hash_map ;
    queue< pair<Tree_Node* , int >> q ;         // this store node and its vertical/horizontal distance 

    q.push(make_pair(root , 0 ));

    while(!q.empty()){
        pair< Tree_Node* , int> front_element = q.front();
        q.pop() ;
        Tree_Node* front_Node = front_element.first ;
        int hd = front_element.second ;         // hd is horizontal distance 


        // for bottom view just overwrite this so that last level elements are stored in map 
        // if(hash_map.find(hd) == hash_map.end()) {  // means no entry yet 
        //     hash_map[hd] = front_Node->data ;
        // }
        hash_map[hd] = front_Node->data ;


        if(front_Node->left != NULL)    q.push(make_pair(front_Node->left,hd-1));
        if(front_Node->right != NULL)    q.push(make_pair(front_Node->right,hd+1));
    }

    for(auto it : hash_map){
        cout << it.second << " " ;
    }
    cout << endl ; 
}


int main(){
    Tree_Node* root = create_Tree() ;

    // tree input -> 10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1


    pre_order_traversal(root) ;
    cout << endl ;

    vector<int> leftView ;
    leftViewSeen(root , 0 , leftView) ;
     for(auto x : leftView){
        cout << x << "  " ;
    }
    cout << endl ;
    vector<int> rightView ;
    rightViewSeen(root , 0 , rightView) ;
     for(auto x : rightView){
        cout << x << "  " ;
    }
    cout << endl ;

    top_view(root);

    cout << endl ;

    bottom_view(root);

}
