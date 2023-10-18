bool ispossible(vector<int> &boards, int k,int m){
    int painterno=1;
    int paintertime=0;
    for(int i=0;i<boards.size();i++){
if(paintertime+boards[i]<=m){
   paintertime=paintertime+boards[i];

}
else{
    painterno++;
    if(boards[i]>m||painterno>k){
        return false;
    }
    paintertime=boards[i];
}


    }
    return true;
}



int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int s=0;
   
      int sum=0;
    for(int i=0;i<boards.size();i++){
      sum=sum+boards[i];
    }
     int e=sum;
    int ans=-1;
    int m=s+(e-s)/2;
    while(s<=e){
if(ispossible(boards,  k, m)){
ans=m;
e=m-1;
}
else{
s=m+1;

}
m=s+(e-s)/2;


    }
    return ans;
}