#include <bits/stdc++.h> 
bool ispossible(vector<int> &pages, int n,int m, int b){
	int ninja1=1;
	int pageno=0;
	for(int i=0;i<n;i++){
					if(pageno+pages[i]<=m){
pageno=pageno+pages[i];
		}
		else{
ninja1++;
		if(ninja1>b||pages[i]>m){
			return false;
		}
		pageno=pages[i];
		
		}	
	}
	return true;
}
int allocateBooks(vector<int> &pages, int n, int b)
{
	// Write your code here.
	if(b>n){
		return -1;
	}
	else{
			int s=0;
	int e=0;
	int sum=0;
	for(int i=0;i<n;i++){
sum+=pages[i];
	}
	e=sum;
	int m=s+(e-s)/2;
	int ans=-1;
	while(s<=e){
if(ispossible(pages,n,m,b)){
ans=m;
e=m-1;
}
else{
s=m+1;
}
m=s+(e-s)/2;
	}
return ans;
	}

}