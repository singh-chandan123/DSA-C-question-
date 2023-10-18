/************************************************************
    Following is the Binary Search Tree node structure

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

************************************************************/
TreeNode* LCAinaBST(TreeNode* root, TreeNode* P, TreeNode* Q)
{
	TreeNode*temp=root;
    while(temp!=NULL){
      if (P->data > temp->data && Q->data > temp->data) {
        // right me
        temp = temp->right;
      } 
      else if (P->data < temp->data && Q->data < temp->data){
        // left me
        temp = temp->left;
    }
else{
    return temp;
}

    }
}