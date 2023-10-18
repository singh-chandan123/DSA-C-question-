#include <bits/stdc++.h> 

int solve(string &st1,string &st2,int i,int j,vector<vector<int>>&dp){
//base case
if(i==st1.length()){
  return 0;
}
if(j==st2.length()){
  return 0;
}
if(dp[i][j]!=-1){
  return dp[i][j];
}
int ans=0;
if(st1[i]==st2[j]){
 ans= 1+solve(st1,st2,i+1,j+1,dp);
}
else{
  ans=max(ans,max(solve(st1,st2,i+1,j,dp),solve(st1,st2,i,j+1,dp)));
}
dp[i][j]=ans;
return dp[i][j];


}
int getLengthOfLCS(string & str1, string & str2) {
  int n=str1.length();
  int m=str2.length();
vector<vector<int>>dp(n,vector<int>(m,-1));
return solve(str1,str2,0,0,dp);
}