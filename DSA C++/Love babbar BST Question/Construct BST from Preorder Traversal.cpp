#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* solve(vector<int> &preOrder,int min,int max,int &i){
    //base case
    if(i>=preOrder.size()){
        return NULL;
    }
    //agar range m nhi hai toh NULL RETURN 
    if(preOrder[i]<min||preOrder[i]>max){
        return NULL;
    }
    //root banao first element ka
    TreeNode<int>* root=new TreeNode<int>(preOrder[i]);
 i++;
    //leftcall 
    root->left=solve(preOrder,min,root->data,i);
    root->right=solve(preOrder,root->data,max,i);
    return root;
}
  
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
     int min=INT_MIN;
   int max=INT_MAX;
   int i=0;
  return solve(preOrder,min,max,i);
}