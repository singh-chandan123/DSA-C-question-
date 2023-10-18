int pivot(vector<int>& arr,int n){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return e;
}
int binarysearch(vector<int>& arr,int s,int e,int k){
    int st=s;
    int end=e;
    int mid=st+(end-st)/2;
    while(st<=end){
        if(arr[mid]==k){
           return mid; 
        }
        else if(arr[mid]<k){
st=mid+1;
        }
        else{
            end=mid-1;
        }
     mid=st+(end-st)/2;   
    }
    return -1;
}



int findPosition(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
int p=pivot(arr, n);
if(k>=arr[p]&&k<=arr[n-1]){
   return  binarysearch(arr,p, n-1,k);
}
else{
   return binarysearch(arr,0,p-1,k);
}
}