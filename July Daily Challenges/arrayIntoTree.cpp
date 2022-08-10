#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
  int data;
  struct TreeNode* left;
  struct TreeNode* right;

  TreeNode(int val){
    data = val;
    left = right = NULL;
  }
};

TreeNode* sortedArrayToBST(vector<int> nums);
void preOrder(TreeNode* root);

int main(){
    int n;
    cout<<"Enter size of array ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter sorted array ";
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }
    sortedArrayToBST(nums);
}

TreeNode* sortedArrayToBST(vector<int> nums) {
        //if size of vector is 0 or 1
        if(nums.size() == 0){
            return NULL;
        }
        if(nums.size() == 1){
            return new TreeNode(nums[0]);
        }
        int mid = nums.size()/2;
        
        //separate nums into two parts middle ele will be the root of the tree
        TreeNode* root = new TreeNode(nums[mid]);
        
        //make two vectors for left and right tree
        vector<int> left(nums.begin(), nums.begin()+mid);
        vector<int> right(nums.begin()+mid+1, nums.end());
        
        //use recursion to create left and right tree
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        preOrder(root);
        return root;     
    }
void preOrder(TreeNode* node){
    if(node == NULL){
        return;
    }
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}
