/*Approach: there are 3 approaches to solve this question
1) 2 solutions(recursive and using stack) with O(n) time and space complexity
2) 1 sol. with O(n) time and O(1) space complexity
*/


#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  struct Node* left;
  struct Node* right;

  Node(int val){
    data = val;
    left = right = NULL;
  }
};
void flattenTree(Node* root);
void preOrder(Node* root);
int main(){
    //create tree
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    flattenTree(root);
}
void preOrder(Node* node){
    if(node == NULL){
        return;
    }
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}
void flattenTree(Node* node){
    /*recursive solution: pre-order traversal is the flatten linked list of tree
    To solve this problem consider reverse postorder traversal i.e. RIGHT, LEFT, ROOT to make the list
    Preorder traversal of this tree is :  1 2 3 4 5 6 7
    
    First go till the last right most node of the tree (here is 6) then left most and make node->left = null for each node
    */
    Node* prev = NULL;
    if(node == NULL){
        return;
    }
    flattenTree(node->right);
    flattenTree(node->left);
    node->right = prev;
    node->left = NULL;
    prev = node;
    preOrder(node);

    /*Stack approach: extension of recursion
    intitially it will have a root, check if the node has right child then push it then for left child. then make its left child null and right child - top of stack
    */
   stack<Node*> st;
   st.push(node);

   while(!st.empty()){
    Node* curr = st.top();
    st.pop();

    if(curr->right){
        st.push(curr->right);
    }
    if(curr->left){
        st.push(curr->left);
    }
    if(!st.empty()){
        curr->right = st.top();
    }
    curr->left = NULL;
   }
   preOrder(node);

   /*
    with O(1) space complexity: not getting correct ans
   */
  Node* curr = node, *prev = NULL;
  while(curr){
    if(curr->left){
        prev = curr->left;
        while(prev->right){
            prev = prev->right;
        }
        prev->right = curr->right;
        curr->right = curr->left;
    }
    curr = curr->right;
  }
  preOrder(node);
}
