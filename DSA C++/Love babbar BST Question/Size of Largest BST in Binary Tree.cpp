/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

class node{
public:
int maxsize;
int minsize;
int size;
//constructor
node(int maxsize,int minsize,int size){
	this->maxsize=maxsize;
	this->minsize=minsize;
	this->size=size;
}
};

node helper(TreeNode *root){
//base case
if(root==NULL){
	return node(INT_MIN,INT_MAX,0);
}
//here postorder
//left call
auto leftans=helper(root->left);
auto rightans=helper(root->right);
//condition for BST
if(root->data>leftans.maxsize&&root->data<rightans.minsize){
	//means it is bst
return node(max(root->data,rightans.maxsize),min(root->data,leftans.minsize),leftans.size+rightans.size+1);

}
else{
	return node(INT_MAX,INT_MIN,max(rightans.size,leftans.size));
}

}
int largestBST(TreeNode* root) 
{
    // Write your code here.
   return  helper(root).size;
}