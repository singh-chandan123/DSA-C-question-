
# include<bits/stdc++.h>
int solve(vector<int>& days, vector<int>& costs,int n,int ind,vector<int>&dp){
//base case
if(ind>=n){
    return 0;
}
if(dp[ind]!=-1){
    return dp[ind];
}
int i;

//option 1 1 day pass
int ans1=costs[0]+solve(days,costs,n,ind+1,dp);

//option2 7 days pass ticket
for( i=ind;i<n&&days[i]<days[ind]+7;i++);
int ans2=costs[1]+solve(days,costs,n,i,dp);

//option3 30 days pass ticket
for(i=ind;i<n&&days[i]<days[ind]+30;i++);
int ans3=costs[2]+solve(days,costs,n,i,dp);

dp[ind]= min(ans1,min(ans2,ans3));
return dp[ind];
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
   vector<int>dp(n+1,-1);      
       return solve(days,cost,n,0,dp);  
}