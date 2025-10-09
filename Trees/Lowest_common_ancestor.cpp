// lowest common ancestor is the node which is the originating point of the sub bordinates nodes p and q 
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


// function to get the lowest common ancestor 
Tree_Node* lowestCommonAncestor(Tree_Node* root, Tree_Node* p,Tree_Node* q ){

    // base case ; edge cases
    if(root == NULL)    return NULL;
    if(root->data == p->data )  return p ;
    if(root->data == q->data )  return q ;

    // recursive call for left subtree
    Tree_Node* left_Ans = lowestCommonAncestor(root->left, p,q);
    // recursive call for right subtree
    Tree_Node* right_Ans = lowestCommonAncestor(root->right, p,q);

    // return cases 
    if(left_Ans == NULL && right_Ans == NULL)       return NULL ;
    else if( left_Ans != NULL && right_Ans == NULL) return left_Ans ;
    else if( left_Ans == NULL && right_Ans != NULL) return right_Ans ;
    else                                            return root ;
}
