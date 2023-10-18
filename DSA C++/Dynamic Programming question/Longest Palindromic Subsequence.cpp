#include <bits/stdc++.h> 
int solve(string s1,string s2,int i,int j,vector<vector<int>>&dp){
//base case
if(i==s1.length()||j==s2.length()){
    return 0;
}
if(dp[i][j]!=-1){
    return dp[i][j];
}
int ans=0;
if(s1[i]==s2[j]){
    ans=1+solve(s1,s2,i+1,j+1,dp);

}
else{
    ans=max(ans,max(solve(s1,s2,i+1,j,dp),solve(s1,s2,i,j+1,dp)));
}
return dp[i][j]=ans;
}
int longestPalindromeSubsequence(string s)
{

string str=s;
reverse(str.begin(),str.end());
vector<vector<int>>dp(s.length(),vector<int>(str.length(),-1));
return solve(str,s,0,0,dp);

}