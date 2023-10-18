#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
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
//inorder find to store number in sorted order
void inorder(TreeNode<int> *root1,vector<int>&v1){
//base case
if(root1==NULL){
    return;
}
inorder(root1->left,v1);
v1.push_back(root1->data);
inorder(root1->right,v1);

}

//merge two vectors
vector<int> merge(vector<int>a,vector<int>b){
//create new vector of size a+b
vector<int>ans(a.size()+b.size());
int i=0, j=0;
int k=0;
while(i<a.size()&&j<b.size()){
if(a[i]<b[j]){
    ans[k]=a[i];
    i++;
    k++;
}
else{
    ans[k]=b[j];
    j++;
    k++;
}
}
//baki bacha hua aur check kro
while(i<a.size()){
    ans[k]=a[i];
    i++;
    k++;
}

while(j<b.size()){
    ans[k]=b[j];
    j++;
    k++;
}
return ans;
}

//insert into bst function
TreeNode<int> *insertintobst(int s,int e,vector<int>&a){
    //base case
    if(s>e){
        return NULL;
    }
//mid find out
int mid=s+(e-s)/2;
//root
TreeNode<int>* root=new TreeNode<int>(a[mid]);
root->left=insertintobst(s,mid-1,a);
root->right=insertintobst(mid+1,e,a);
return root;
}


TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
   //phle vector m store kro dono sorted bst ko then merge 
   vector<int>v1;
 vector<int>v2;
inorder(root1,v1);
inorder(root2,v2);
//now merge both v1 and v2
vector<int>ans=merge(v1,v2);
int s=0;
int e=ans.size()-1;
return insertintobst(s,e,ans);




}