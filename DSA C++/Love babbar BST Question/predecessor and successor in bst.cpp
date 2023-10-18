pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{

int pred=-1;
int succ=-1;
//find key
BinaryTreeNode<int>* temp=root;
while(temp->data!=key){
if(temp->data>key){
//left me
succ=temp->data;
temp=temp->left;
}
else{
    //right 
    pred=temp->data;
    temp=temp->right;
}
}

//key got 
//pred
BinaryTreeNode<int>*leftside=temp->left;
while(leftside!=NULL){
    pred=leftside->data;
    leftside=leftside->right;
}


//succ
BinaryTreeNode<int>*rightside=temp->right;
while(rightside!=NULL){
    succ=rightside->data;
    rightside=rightside->left;
}
pair<int,int>ans=make_pair(pred,succ);
return ans;


}