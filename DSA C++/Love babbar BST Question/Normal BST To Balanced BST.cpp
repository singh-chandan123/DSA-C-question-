/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void inorder(TreeNode<int>* root,vector<int>&ans){
//base case
if(root==NULL){
    return;
}
//left recursive call
inorder(root->left,ans);
ans.push_back(root->data);
inorder(root->right,ans);

}
//inorder to bst

TreeNode<int>* inordertobst(int s,int e,vector<int>&ans){
    //base case
    if(s>e){
        return NULL;
    }
    //find mid and then create node for mid value
    int mid=s+(e-s)/2;
    TreeNode<int>* newroot=new TreeNode<int>(ans[mid]);
    // recursion
   newroot->left= inordertobst(s,mid-1,ans);
   newroot->right=inordertobst(mid+1,e,ans);
return newroot;

}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
   //make vector for storing inorder 
   vector<int>ans;
   inorder(root,ans);
   int s=0;
   int e=ans.size()-1;
  return inordertobst(s,e,ans);
 
}