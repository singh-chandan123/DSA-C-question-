#include <bits/stdc++.h> 
//recursion+memoization approach
int solve(vector<int> &nums,int n,int ind,vector<int>&dp){
    int sum=0;
    //base case
    if(ind==n||ind>n){
        return sum;
    }
    //step2
    if(dp[ind]!=-1){
        return dp[ind];
    }


    //step3
int incl=sum+nums[ind]+solve(nums,n,ind+2,dp);
int exc=sum+solve(nums,n,ind+1,dp);
dp[ind]= max(incl,exc);
return dp[ind];
}


int maximumNonAdjacentSum(vector<int> &nums){
int n=nums.size();
vector<int>dp(n+1,-1);
 return solve(nums,n,0,dp);
}