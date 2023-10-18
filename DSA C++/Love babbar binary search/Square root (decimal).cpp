#include <bits/stdc++.h> 

int intsol(long long int  n){
	long int s=0;
	long int  e=n;
	long int ansspace=n;
	long int ans=-1;
	long int m=s+(e-s)/2;
	while(s<=e){
		unsigned  long int sq=m*m;
		if(sq==ansspace){
			ans=m;
			return ans;
		}
		else if(sq>ansspace){
			e=m-1;
		}
		else{
ans=m;
s=m+1;

		}
		m=s+(e-s)/2;
	}
	return ans;
}
double squareRoot(long long n, int d) 
{	
	// Write your code here.
	int tempsol=intsol(n);
double ans=tempsol;
	double factor=1;
	for(int i=0;i<d;i++){
		factor=factor/10;
		for(double j=ans;j*j<n;j=j+factor){
			ans=j;
		}
	}
return ans;
}