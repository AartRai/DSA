//https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

// Maintain a fixed-size sliding window of length k.
//
// freq map stores frequencies of elements
// and sum stores the current window sum.
//
// Build the first window.
//
// For each slide:
// - Add incoming element.
// - Remove outgoing element.
// - Erase element if its frequency becomes 0.
//
// If freq.size() == k,
// all k elements are distinct,
// so update the maximum window sum.

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        long long ans = 0;
        unordered_map<int,int> freq;

        int i=0;
        // First window
        while(i<k) {
            sum += nums[i];
            freq[nums[i]]++;
            i++;
        }

        if(freq.size() == k)
            ans = sum;
        
        // Slide the window
        while(i<n) {

            // Add new element
            sum += nums[i];
            freq[nums[i]]++;

            // Remove old element
            sum -= nums[i-k];
            freq[nums[i-k]]--;

            if(freq[nums[i-k]] == 0)
                freq.erase(nums[i-k]);

            // Check if all elements are distinct
            if(freq.size() == k)
                ans = max(ans, sum);

            i++;
        }

        return ans;
    }
};

//TC : O(n)
//SC : O(k)
