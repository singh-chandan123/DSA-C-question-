#include <bits/stdc++.h> 
bool solve(int n,int target,vector<int>&arr,int ind,vector<vector<int>>&dp){
//base case
if(target==0){
    return true;
}
//for index base case
if(ind==0){
    if(arr[0]==target){
        return true;
    }
    else{
        return false;
    }
}

if(dp[ind][target]!=-1){
    return dp[ind][target];
}
bool nottake=solve(n,target,arr,ind-1,dp);
bool take=false;
if(target>=arr[ind]){
    take=solve(n,target-arr[ind],arr,ind-1,dp);
}
dp[ind][target]= (nottake || take);
return dp[ind][target];

}
bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<vector<int>>dp(n,vector<int>(k+1,-1));
  int ind=n-1;
  return solve(n,k,arr,ind,dp); 
}