# include<bits/stdc++.h>
int solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
    //base case
 if(i==s1.length()){
     return s2.length()-j;
 }
  if(j==s2.length()){
     return s1.length()-i;
 }
 if(dp[i][j]!=-1){
     return dp[i][j];
 }
  int ans=0;
  if(s1[i]==s2[j]){
     return 0+solve(s1,s2,i+1,j+1,dp);
  }
  else{
   int insert=1+solve(s1,s2,i,j+1,dp);
   int replace=1+solve(s1,s2,i+1,j+1,dp);
   int delet=1+solve(s1,s2,i+1,j,dp);
   ans=min(insert,min(replace,delet));
  }
  return dp[i][j]=ans;
}
int editDistance(string str1, string str2)
{
  if(str1.length()==0||str2.length()==0){
      return 0;
  }
  int n=str1.length();
  int m=str2.length();
  vector<vector<int>>dp(n,vector<int>(m+1,-1));
  return solve(str1,str2,0,0,dp);
}