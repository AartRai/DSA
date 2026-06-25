//Longest Subarray with Sum K array consist of positive interger

// Approach:
// Use a sliding window to maintain a subarray sum.
// Expand the window by moving the right pointer and adding elements to 'sum'.
// If the sum becomes greater than k, shrink the window from the left
// until the sum is less than or equal to k.
// Whenever sum equals k, update the maximum length of the subarray.
//
// Note: This approach works only when all array elements are non-negative.

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int i=0;
        int j=0;
        int ans=0;
        int sum=0;
        int n=arr.size();
        
        while(i<n){
            sum += arr[i];
            
            while(sum > k){
                sum -= arr[j];
                j++;
            }
            
            if(sum == k) ans = max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};

//TC: O(n)
//SC: O(1)
