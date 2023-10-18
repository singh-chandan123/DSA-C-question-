#include <bits/stdc++.h> 
#include<iostream>

using namespace std;
int sqrtN(long long int N)
{
    // Write your code here.
 long  int s=0;
  long  int ansspace=N;
    long  int e=ansspace;
   
    long  int ans=-1;
    long  int m=s+(e-s)/2;
    while(s<=e){
unsigned long  int sq=m*m;
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
int main() {
	// Write your code here
	long int n;
	cin>>n;
// long sqrt=std::sqrt(n);
int s=sqrtN(n);
cout<<s;
// cout<<sqr;
}