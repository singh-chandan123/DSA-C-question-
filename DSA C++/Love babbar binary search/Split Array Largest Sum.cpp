# include<bits/stdc++.h>

int possiblecounts(vector<int> &array, int mid){
int tempsum=0;int count=0;

for(int i=0;i<array.size();i++){
if(tempsum+array[i]<=mid){
    tempsum+=array[i];
}
else{
    count++;
    tempsum=array[i];
}
}
count++;
return count;


}
int splitArray(vector<int> &array, int k) {
    // Write your code here.
int n=array.size();
int low=0;
int high=0;
int ans=0;
// int max=0;
for(int i=0;i<n;i++){
    //find largest element as low
low=max(array[i],low);
high=high+array[i];

}
int mid;
while(low<=high){
mid=(low+high)/2;
int count=possiblecounts(array,mid);
if(count<=k){
ans=mid;
    high=mid-1;
} 
else {
  low = mid + 1;
}

}
return ans;
}