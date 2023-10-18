/*
Implement the class for Max Priority Queue which includes following functions -


1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.


2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.


3. insert -
Given an element, insert that element in the priority queue at the correct position.


4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.


5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.


Note : main function is given for your reference which we are using internally to test the class.
*/

/*
#include <iostream>
using namespace std;

#include "solution.h"

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}
*/

# include<bits/stdc++.h>
class PriorityQueue {
    // Declare the data members here
    vector<int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
 pq.push_back(element);
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            if(pq[parentIndex] < pq[childIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }
            childIndex = parentIndex;
        }


     
    }

    int getMax() {
        // Implement the getMax() function here
            if(pq.size()) {
        	return pq[0];
        } else {
            return INT_MIN;
        }
    }

 void maxHeapify(vector<int> &arr, int n, int index) {
        int curr = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        
        if(left < n and arr[left] > arr[curr]) {
            curr = left;
        }
        
        if(right < n and arr[right] > arr[curr]) {
            curr = right;
        }
        
        if(curr != index) {
            int temp = arr[curr];
            arr[curr] = arr[index];
            arr[index] = temp;
            maxHeapify(arr, n, curr);
        }
    }

    int removeMax() {
        // Implement the removeMax() function here
         int ans;
        if(pq.size()) {
            ans = pq[0];
        } else {
            return INT_MIN;
        }
        
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        maxHeapify(pq, pq.size(), 0);
        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
         return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
         return pq.size() == 0;
    }
};