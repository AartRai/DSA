https://leetcode.com/problems/top-k-frequent-elements/description/?envType=problem-list-v2&envId=heap-priority-queue

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int x:nums){
            mp[nums]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }

        while(pq.size()>k){
            pq.pop();
        }
        vector<
    }
};

//TC: O(n log k)
//SC: O(n)
