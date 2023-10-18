# include<bits/stdc++.h>
# define MOD 1000000007;
int solve(int dice,int face,int target,vector<vector<int>>&dp){
//base case
if(target<0){
    return 0;
}
if(dice==0&&target!=0){
    return 0;
}
if(dice!=0&&target==0){
    return 0;
}
if(dice==0&&target==0){
    return 1;
}

if(dp[dice][target]!=-1){
    return dp[dice][target]%MOD;
}
int ans=0;
for(int i=1;i<=face;i++){
    ans=(ans+solve(dice-1,face,target-i,dp))%MOD;
}
dp[dice][target]= ans%MOD;
return dp[dice][target];
}
int diceThrows(int d, int f, int s) {
 vector<vector<int>>dp(d+1,vector<int>(s+1,-1));
 return  solve(d,f,s,dp);
    
}