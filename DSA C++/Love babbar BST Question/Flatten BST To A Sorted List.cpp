#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inorder(TreeNode<int>*root,vector<int>&inorderval){
//base case
if(root==NULL){
    return;
}
inorder(root->left,inorderval);
//store val in vector
inorderval.push_back(root->data);
inorder(root->right,inorderval);

}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int>inorderval;
   inorder(root,inorderval);
   int n=inorderval.size();
   //create newroot node 
   TreeNode<int>*newroot=new TreeNode<int>(inorderval[0]);
//create node for traversal
TreeNode<int>*current=newroot;
for(int i=1;i<n;i++){
    TreeNode<int>*temp=new TreeNode<int>(inorderval[i]);
    current->right=temp;
    current->left=NULL;
    current=temp;
}
//then at last we add null to both left and right of current
current->left=NULL;
current->right=NULL;
//return newroot 
return newroot;
}