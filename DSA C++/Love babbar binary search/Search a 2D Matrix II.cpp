#include <bits/stdc++.h> 
bool findInMatrix(int x, vector<vector<int>> &arr)
{
  
  int r=arr.size();
  int c=arr[0].size();
  int srow=0;
  int scol=c-1;
  while(srow<r&&scol>=0){
      int element=arr[srow][scol];
      if(element==x){
          return true;
      }
      if(element<x){
          srow++;
      }
      else{
          scol--;
      }
  }
  return false;
}