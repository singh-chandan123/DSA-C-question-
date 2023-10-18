#include <bits/stdc++.h> 
//1 st approach time complexity -  0(Nlog N)
// vector<int> Klargest(vector<int> &a, int k, int n) {
//     // Write your code here
//     vector<int>ans;
//     sort(a.begin(),a.end(),greater<int>());
//    for(int i=k-1;i>=0;i--){
// ans.push_back(a[i]);
//    }
// return ans;
//     }

//2 nd approach 

    vector<int> Klargest(vector<int> &v, int k, int n) {
   vector<int>ans;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < n; ++i) {
        pq.push(v[i]);
        if (pq.size() > k) {
            pq.pop();

        }
    }
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();

    }
    return ans;
}