# include<bits/stdc++.h>
// without using recursion
// int solve(int n, int x, int y, int z){
// //base case
// if(n==0){
// 	return 0;
// }

// if(n<0){
// 	return INT_MIN;
// }

// int a=1+solve(n-x,x,y,z);
// int b=1+solve(n-y,x,y,z);
// int c=1+solve(n-z,x,y,z);
// int ans=max(a,max(b,c));
// return ans;
	
// }


// memoization
int solvememo(int n, int x, int y, int z,vector<int>&dp){
//base case
if(n==0){
	return 0;
}

if(n<0){
	return INT_MIN;
}

//step3
if(dp[n]!=-1){
	return dp[n];
}

int a=1+solvememo(n-x,x,y,z,dp);
int b=1+solvememo(n-y,x,y,z,dp);
int c=1+solvememo(n-z,x,y,z,dp);
dp[n]=max(a,max(b,c));
return dp[n];

	
}



int cutSegments(int n, int x, int y, int z) {

// int ans=solve(n,x,y,z);
// if(ans<0){
// 	return 0;
// }
// return ans;

// solve by memoization
	//create vector
	vector<int>dp(n+1,-1);
int ans=solvememo(n,x,y,z,dp);
if(ans<0){
	return 0;
}
return ans;
}