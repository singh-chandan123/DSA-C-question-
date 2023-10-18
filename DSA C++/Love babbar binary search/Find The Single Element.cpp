#include<vector>
# include<bits/stdc++.h>
int getSingleElement(vector<int> &arr){
    // bruteforce 
// int ans=0;
// for(int i=0;i<arr.size();i++){
// ans=ans^arr[i];
// }
// return ans;

//optimise 
int n=arr.size();
int l=1;
int h=arr.size()-1;
if(arr.size()==1){
    return arr[0];
}
if(arr[0]!=arr[1]){
    return arr[0];
}
if(arr[n-1]!=arr[n-2]){
    return arr[n-1];
}
while(l<=h){
    int mid=(l+h)/2;
    if(arr[mid]!=arr[mid-1]&&arr[mid]!=arr[mid+1] ){
        return arr[mid];
    }
    if((mid%2==1&&arr[mid-1]==arr[mid]) || (mid%2==0&&arr[mid]==arr[mid+1]) ){
l=mid+1;
    }
    else{
        h=mid-1;
    }
}
return -1;
}