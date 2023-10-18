#include <bits/stdc++.h> 
int solve(vector<int>&arr,int n,int i,int j,vector<vector<int>>&dp){
//base case
if(i+1==j){
	return 0;
}
if(dp[i][j]!=-1){
	return dp[i][j];
}
int maxi=INT_MAX;
for(int k=i+1;k<j;k++){
maxi=min(maxi,arr[i]*arr[j]*arr[k]+solve(arr,n,k,j,dp)+solve(arr,n,i,k,dp));

}
dp[i][j]=maxi;
return dp[i][j];
}
int minimumTriangleScore(vector<int> &arr, int n){
	vector<vector<int>>dp(n,vector<int>(n+1,-1));
int j=n-1;
return solve(arr,n,0,j,dp);

}