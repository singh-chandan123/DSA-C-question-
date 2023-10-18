#include <bits/stdc++.h> 
  int firstocc(vector<int>& arr,int n,int k){
    int l=0;
    int h=n-1;
    int mid=l+(h-l)/2;
    int ans=-1;
    while(l<=h){

if(arr[mid]==k){
    ans=mid;
    h=mid-1;

}
else if(arr[mid]<k){
    l=mid+1;
}
else{
    h=mid-1;
}
mid=l+(h-l)/2;
    }
 return ans;   
}

int lastocc(vector<int>& arr,int n,int k){
    int l=0;
    int h=n-1;
    int mid=l+(h-l)/2;
    int ans=-1;
    while(l<=h){

if(arr[mid]==k){
    ans=mid;
  //  h=mid-1;
l=mid+1;
}
else if(arr[mid]<k){
    l=mid+1;
}
else{
    h=mid-1;
}
mid=l+(h-l)/2;
    }
 return ans;   
} 

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{

pair<int, int> p;
p.first=firstocc(arr,n,k);
p.second=lastocc(arr,n,k);
return p;
}