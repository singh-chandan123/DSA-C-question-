#include<bits/stdc++.h>
using namespace std;
// int  fib(int n,vector<int>&ans){
//         //base case
//         if(n==1||n==0){
//                 return n;
//         }
// //step2
// if(ans[n]!=-1){
//         return ans[n];
// }

// //step3
// ans[n]=fib(n-2,ans)+fib(n-1,ans);
// return ans[n];
// }
int main()
{
       //top down approach
int n;
cin>>n;
// //create vector for storing ans
// vector<int>ans(n+1);
// for(int i=0;i<=n;i++){
//         ans[i]=-1;
// }
// //function
// cout<<fib(n,ans)<<endl;

   //bottom up approach
 
 int prev2=0;
 int prev1=1;
 int curr;
 for(int i=2;i<=n;i++){
curr=prev1+prev2;
prev2=prev1;
prev1=curr;
 }
cout<<prev1;
}