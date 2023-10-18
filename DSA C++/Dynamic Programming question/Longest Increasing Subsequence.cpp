# include<bits/stdc++.h>
/* int solve(int arr[],int n,int ind,int prevind,vector<vector<int>>&dp){
    //base case
    if(ind>=n){
        return 0;
    }
    if(dp[ind][prevind+1]!=-1){
        return dp[ind][prevind+1];
    }
    int nottake=0+solve(arr,n,ind+1,prevind,dp);
    int take=0;
    if(prevind==-1||arr[ind]>arr[prevind]){
        take=1+solve(arr,n,ind+1,ind,dp);
    }
 dp[ind][prevind+1]=max(take,nottake);
 return dp[ind][prevind+1];
 }*/

//using binary serach
int solve(int arr[],int n){
if(n==0){
    return 0;
}
//cerate vector for storing ans
vector<int>ans;
ans.push_back(arr[0]);
for(int i=1;i<n;i++){
    if(arr[i]>ans.back()){
       ans.push_back(arr[i]); 
    }
    else{
        //index nikalo agle bade element ka
        int index=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
        ans[index]=arr[i];
    }
}
return ans.size();
}

int longestIncreasingSubsequence(int arr[], int n)
{
//     vector<vector<int>>dp(n,vector<int>(n+1,-1));
// return solve(arr,n,0,-1,dp);

return solve(arr,n);


}