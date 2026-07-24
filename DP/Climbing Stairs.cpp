//https://leetcode.com/problems/climbing-stairs/


// Approach:
// dp[i] = number of ways to reach the ith stair.
// From stair i, we can come from:
// 1) i-1 (1 step)
// 2) i-2 (2 steps)
// Therefore, dp[i] = dp[i-1] + dp[i-2].
// Initialize base cases and build the answer iteratively.

// TC: O(n)
// SC: O(n)

class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1 || n==2){
            return n;
        }

        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;

        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
