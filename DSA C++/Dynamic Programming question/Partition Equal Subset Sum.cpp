# include<bits/stdc++.h>
bool solve(vector<int>&arr,int n,int ind,int target,vector<vector<int>>&dp){

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
bool nottake=solve(arr,n,ind-1,target,dp);
bool take=false;
if(target>=arr[ind]){
    take=solve(arr,n,ind-1,target-arr[ind],dp);
}
bool ans= (nottake || take);
 dp[ind][target]=ans;
return dp[ind][target];
}
bool canPartition(vector<int> &arr, int n)
{

	int sum=0;
	for(int i=0;i<n;i++){
		
		sum=sum+arr[i];
	}
	int target=sum/2;
		//create vector
	vector<vector<int>>dp(n,vector<int>(target+1,-1));
	if(sum%2!=0){
return 0;
	}
	else{
	return	solve(arr,n,n-1,target,dp);
	}
}