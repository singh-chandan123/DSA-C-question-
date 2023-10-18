#include <bits/stdc++.h> 
int solve(vector<int>& weight, vector<int> &value, int ind, int capacity,vector<vector<int>>&dp){
//base case
if(ind==0){
	if(weight[0]<=capacity){
		return value[0];
        } else {
                return 0;
        }
}
//step3
if(dp[ind][capacity]!=-1){
	return dp[ind][capacity];
}

        int include=0;
	if(weight[ind]<=capacity){
		include=value[ind]+solve(weight,value,ind-1,capacity-weight[ind],dp);
	}

	int exclude=0+solve(weight,value,ind-1,capacity,dp);
dp[ind][capacity]=max(include,exclude);
return dp[ind][capacity];



}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
 return solve(weight,value,n-1,maxWeight,dp);	
	
}