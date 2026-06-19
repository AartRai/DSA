//https://leetcode.com/problems/house-robber/

//memo
class Solution {
public:
    int dp[101];

    int solve(vector<int>&nums,int i){
        if(i >= nums.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int take = nums[i] + solve(nums,i+2);
        int skip = solve(nums,i+1);

        return dp[i]= max(take,skip);
    }

    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};

//TC = O(n)
//SC = O(n)

//tabulation
class Solution {
public:
    int solve(vector<int>&nums,int i){
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>dp(n+1,-1);

        dp[0]=0; //max stolen money till i
        dp[1]=nums[0];

       for(int i=2;i<=n;i++){
        int take = nums[i-1] + dp[i-2];
        int skip = dp[i-1];
        dp[i]=max(take,skip);
       }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        return solve(nums,0);
    }
};


//TC: O(n)
//SC: O(n)

//(Space Optimized Bottom Up )
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int prevPrev = 0;
        int prev= nums[0];
        
        for(int i = 2; i<=n; i++) {
            int skip = prev;
            
            int take = nums[i-1] + prevPrev;
                
            int temp = max(skip, take);
            
            prevPrev = prev;
            prev = temp;
        }
        
        return prev;
    }
};
//TC: O(n)
//SC: O(1)
