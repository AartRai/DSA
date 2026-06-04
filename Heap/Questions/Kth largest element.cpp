//https://www.geeksforgeeks.org/problems/kth-largest-element5034/1
//https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
  public:
    int KthLargest(vector<int> &arr, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int x:arr){
            pq.push(x);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};

//TC : O(n log k)
//SC : O(k)
