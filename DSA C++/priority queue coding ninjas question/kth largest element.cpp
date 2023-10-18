/*
Given an array 'arr' of random integers and an integer 'k', return the kth largest element in the array.


Note: Try to do this in O(n*log k) time.


Example:
Input:
5
3 2 5 1 4
2
Output:
4
Explanation:
Array in non increasing form is [5,4,3,2,1]. So the 2nd largest is 4.
Input Format :
The first line of input contains an integer 'n', that denotes the size of the array.
The next line contains 'n' space separated integers, that denote the value of the elements of the array 'arr'.
The next line contains an integer, that denotes the value of 'k'.
Output Format :
The output contains the kth largest element.
Sample Input 1 :
6
9 4 8 7 11 3
2
Sample Output 1 :
9
Explanation of sample input 1:
arr = [9,4,8,7,11,3]
Array 'arr' in non increasing form is [11,9,8,7,4,3]. So the 2nd largest is 9.
Sample Input 2 :
8
2 6 10 11 13 4 1 20
4
Sample Output 2 :
10
Constraints :
1 <= n <= 10^5
1 <= arr[i] <= 10^5
1 <= k <= n
Time Limit: 1 sec
*/

/*
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#include "solution.h"

class Runner
{
    vector<int> arr;
    int k;

public:
    void takeInput()
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            arr.push_back(x);
        }
        cin>>k;
    }

    void execute()
    {
        vector<int>arrCpy=arr;
        int ans=kthLargest(arrCpy,k);
    }

    void executeAndPrintOutput()
    {
        vector<int>arrCpy=arr;
        int ans=kthLargest(arrCpy,k);
        cout<<ans;
    }
};
int main()
{
    // freopen("./Testcases/large/in/input12.txt", "r", stdin);
    // freopen("./Testcases/large/out/output12.txt", "w", stdout);
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}
*/

# include<bits/stdc++.h>
int kthLargest(vector<int>&arr, int k) {
    // Write your code here
    int n=arr.size();
// create minheap
priority_queue<int,vector<int>,greater<int>>pq;
//k element queue me daalo
for(int i=0;i<k;i++){
    pq.push(arr[i]);
}
for(int i=k;i<n;i++){
    if(arr[i]>pq.top()){
        pq.pop();
        pq.push(arr[i]);
    }
}

return pq.top();
}