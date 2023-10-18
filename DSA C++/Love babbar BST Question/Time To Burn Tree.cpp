# include<bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int maxdis(map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>&mp,BinaryTreeNode<int>* node){
 //make map visit
 map<BinaryTreeNode<int>*,int>vis;
 vis[node]=1;
 queue<BinaryTreeNode<int>*>q;
 q.push(node);
 int max=0;
while(!q.empty()){
 int n=q.size();
 int flag=0;
 for (int i = 0; i < n; i++) {
   BinaryTreeNode<int> *front = q.front();
   q.pop();
//check for left 
if(front->left!=NULL&&!vis[front->left]){
    flag=1;
vis[front->left]=1;
q.push(front->left);
}
//check for right
 if(front->right!=NULL&&!vis[front->right]){
       flag=1;
vis[front->right]=1;
q.push(front->right);
} 
//check for parent 
if(mp[front]&&vis[mp[front]]!=1){
      flag=1;
q.push(mp[front]);
vis[mp[front]]=1;
} 
 }
 if(flag){
max++;
 }
}
return max;
}
BinaryTreeNode<int>* solvenode(BinaryTreeNode<int>* root, int start,map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>&mp){
queue<BinaryTreeNode<int>*>q;
q.push(root);
BinaryTreeNode<int>*res;
while(!q.empty()){
   BinaryTreeNode<int>*front=q.front();
   if(front->data==start){
res=front;
   }
   q.pop();
   if(front->left!=NULL){
       mp[front->left]=front;
       q.push(front->left);
   } 
   if(front->right!=NULL){
       mp[front->right]=front;
       q.push(front->right);
   }

}
return res;
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
  //store the parent of each node
map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>mp;
//store the node of start
 BinaryTreeNode<int>* currentnode=solvenode(root,start,mp);
  int ans=maxdis(mp,currentnode);
  return ans;
}
