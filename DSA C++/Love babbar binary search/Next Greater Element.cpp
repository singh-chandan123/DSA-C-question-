# include<stack>
# include<bits/stdc++.h>
vector<int> nextGreaterElement(vector<int> &arr, int n) {
  // Write your code here
  stack<int>s;
  vector<int>ans;
 for(int i=n-1;i>=0;i--){
//if empty
if(s.empty()==true){
    ans.push_back(-1);
}
else if(s.empty()==false&&s.top()>arr[i]){

ans.push_back(s.top());

}
else{
while(s.empty()==false&&arr[i]>=s.top()){
    s.pop();
}
if(s.empty()==true){
    ans.push_back(-1);
}
else{
    ans.push_back(s.top());
}


}
s.push(arr[i]);
 }
//reverse ans
reverse(ans.begin(),ans.end());
return ans;

}