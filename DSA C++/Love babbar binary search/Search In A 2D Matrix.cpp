# include<bits/stdc++.h>
bool searchMatrix(vector<vector<int>>& mat, int target) {
       int row=mat.size();
       int col=mat[0].size();
       int s=0;
       int e=row*col-1;
       int mid=s+(e-s)/2;
       while(s<=e){
if(mat[mid/col][mid%col]==target){
    return true;
}
if(mat[mid/col][mid%col]<target){
    s=mid+1;   
}
else{
    e=mid-1;
}
   mid=s+(e-s)/2;
           
       } 
       return false;
}