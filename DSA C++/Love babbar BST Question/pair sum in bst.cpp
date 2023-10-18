/**********************************************************
    Following is the Binary Tree Node structure:

    class BinaryTreeNode
    {
    public:
        int data;
        BinaryTreeNode *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(int x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : data(x), left(left), right(right) {}
    };
***********************************************************/

void inorder(BinaryTreeNode*root,int k,vector<int>&inorderval){
//base case
if(root==NULL){
    return;
}
inorder(root->left,k,inorderval);
//store val in vector
inorderval.push_back(root->data);
inorder(root->right,k,inorderval);

}
// check function of two sum
bool check(vector<int>&inorderval,int i,int j,int k){
int sum=0;
while(i<=j){
    sum=inorderval[i]+inorderval[j];
if(sum==k){
    return true;
}
if(sum<k){
    i++;
}
else{
    j--;
}

}
return false;

}

bool pairSumBst(BinaryTreeNode *root, int k)
{
 vector<int>inorderval;
 inorder(root,k,inorderval); 
int i=0;
int j=inorderval.size()-1;
bool ans=check(inorderval,i,j,k);
return ans;
}