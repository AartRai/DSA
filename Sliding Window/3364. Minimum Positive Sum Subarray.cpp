//https://leetcode.com/problems/minimum-positive-sum-subarray/?envType=daily-question&envId=2026-11-14


// Traverse all possible starting indices
// Extend the subarray while its length does not exceed r
// Calculate the running sum of the subarray
// Check if subarray length is within [l, r]
// and its sum is positive
// Update the minimum positive sum
// Return -1 if no valid subarray is found



class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int res=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum =0;
            for(int j=i;j<nums.size() && (j-i+1 <= r); j++){
                sum += nums[j];
                if(sum > 0 && j-i+1 >=l){
                    res = min(res,sum);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
