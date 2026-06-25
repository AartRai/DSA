//https://leetcode.com/problems/minimum-size-subarray-sum/description/

// Sliding Window:
        // Expand the window by moving 'h' and keep adding elements to sum.
        // Once sum becomes >= target, try to shrink the window from the left
        // to find the minimum length valid subarray.
        // Update answer whenever a valid window is found.

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int sum = 0;
        int ans = INT_MAX;
        int h=0;

        while(h<n){
            sum += nums[h];

            while(sum >= target){
                ans = min(ans, h - l + 1);
                sum -= nums[l];
                l++;
            }
            h++;
        }

        if(ans == INT_MAX) return 0;
        return ans;
    }
};

//TC: O(n)
//SC: O(1)
