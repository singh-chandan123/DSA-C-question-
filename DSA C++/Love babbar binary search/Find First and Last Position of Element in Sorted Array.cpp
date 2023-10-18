int firstocc(vector<int> &arr,int n,int x){
    int l=0;
    int h=n-1;
    int mid=l+(h-l)/2;
    int ans=-1;
    while(l<=h){

if(arr[mid]==x){
    ans=mid;
   h=mid-1;
// l=mid+1;
}
else if(arr[mid]<x){
    l=mid+1;
}
else{
    h=mid-1;
}
mid=l+(h-l)/2;
    }
 return ans;   
} 

int lastocc(vector<int> &arr,int n,int x){
    int l=0;
    int h=n-1;
    int mid=l+(h-l)/2;
    int ans=-1;
    while(l<=h){

if(arr[mid]==x){
    ans=mid;
  //  h=mid-1;
l=mid+1;
}
else if(arr[mid]<x){
    l=mid+1;
}
else{
    h=mid-1;
}
mid=l+(h-l)/2;
    }
 return ans;   
} 


pair<int, int> findFirstLastPosition(vector<int> &arr, int n, int x)
{
	// Write your code here. 
pair<int,int>p;
p.first=firstocc(arr, n, x);
p.second=lastocc(arr, n, x);
return p;
}