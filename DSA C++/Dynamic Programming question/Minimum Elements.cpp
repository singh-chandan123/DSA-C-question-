#include <bits/stdc++.h> 
int solve(vector<int> &num, int t,int ind,vector<vector<int>>&dp){
//base case
if(t==0){
    return 0;
}
if(ind==0){
   if(t%num[ind]==0){
       return t/num[ind];
   } else {
       return 1e9;
   }
}
//step2
if(dp[ind][t]!=-1){
    return dp[ind][t];
}

   int nottake=0+solve(num,t,ind-1,dp);
int take=INT_MAX;
if(num[ind]<=t){
    take=1+solve(num,t-num[ind],ind,dp);
}
dp[ind][t]= min(take,nottake);
return dp[ind][t];


}
int minimumElements(vector<int> &num, int x)
{
  
   int n=num.size();
   int size=n-1;
     //create vector
    vector<vector<int>>dp(n,vector<int>(x+1,-1));
  int ans= solve(num,x,size,dp);
  if(ans>=1e9){
      return -1; 
  }
  else{
      return ans;
  }

}