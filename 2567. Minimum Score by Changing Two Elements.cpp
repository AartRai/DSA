//https://leetcode.com/problems/minimum-score-by-changing-two-elements/description/?envType=daily-question&envId=2026-11-19

//First, sort the array in ascending order so that the smallest elements are at the beginning and the largest elements are at the end.

//Since we are allowed to modify at most 3 elements, we can minimize the difference between the maximum and minimum elements by considering three possible cases:
//1. Change the 3 largest elements: The remaining range will be nums[n-4] - nums[0]?
//2. Change the 3 smallest elements: The remaining range will be nums[n-1] - nums[3].
//3. Change 2 smallest and 1 largest element: The remaining range will be nums[n-2] - nums[2].
//We calculate the difference for all three cases and return the minimum value.

//Time Complexity: O(n log n) – Due to sorting.

//Space Complexity: O(1) – No extra space is used 


class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return min({nums[n-1] - nums[2], nums[n-3] - nums[0], nums[n-2] - nums[1]});
    }
};
