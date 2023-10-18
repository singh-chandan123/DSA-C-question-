# include<bits/stdc++.h>
int solve(vector<int>&arr,int target,int ind,vector<vector<int>>&dp){
	//base case
	if(target==0){
		return 1;

	}
	if(ind<=0){
	if(target==arr[ind]){
		return 1;
	}
	else{
		return 0;
	}	
	}

	if(dp[ind][target]!=-1){
		return dp[ind][target];
	}
int take=0;
if(arr[ind]<=target){
	 take=solve(arr,target-arr[ind],ind-1,dp);
}

	int nottake=solve(arr,target,ind-1,dp);
	dp[ind][target]=(take+nottake)%1000000007;
	return dp[ind][target];
}
int findWays(vector<int>& arr, int k)
{

	int n=arr.size();
	vector<vector<int>>dp(n,vector<int>(k+1,-1));
	return solve(arr,k,n-1,dp);
}