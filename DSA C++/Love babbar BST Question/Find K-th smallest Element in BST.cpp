#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

void  inorder(BinaryTreeNode<int>* root, int & k,vector<int>&ans){
//base case
if(root==NULL){
    return;
}
inorder(root->left,k,ans);
//storing all node in vector
ans.push_back(root->data);
inorder(root->right,k,ans);

}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    //create vector for storing ans;
    vector<int>ans;
   inorder(root,k,ans);
   if(k>ans.size()){
return -1;
   }
   else
   return ans[k-1];

}