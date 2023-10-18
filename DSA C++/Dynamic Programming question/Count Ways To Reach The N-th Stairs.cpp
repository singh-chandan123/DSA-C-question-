#include <bits/stdc++.h>
int mod=1000000007;
int solve(int n,vector<int>&dp){
//base case
//step1
if(n==0){
   return 1; 
}
 //step2
 if(dp[n]!=-1){
     return dp[n];
 } 
//step3
 dp[n]=(solve(n-1,dp)+solve(n-2,dp))%mod;
return dp[n];

}
int countDistinctWays(int nStairs) {
    int n=nStairs;
    //step1 create dp vector for memoisation
  vector<int>dp(n+1);
  for(int i=0;i<=n;i++){
      dp[i]=-1;
  }
 return  solve(n,dp);
}