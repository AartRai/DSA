//https://leetcode.com/problems/maximum-subarray-with-equal-products/description/?envType=daily-question&envId=2026-11-24


class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();

        int mx = 0, ml = 1;

        // Calculate maximum element and LCM of entire array
        for (int x : nums) {
            mx = max(mx, x);
            ml = lcm(ml, x);
        }

        int maxP = ml * mx;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {

                prod *= nums[j];

                // Stop if product exceeds maximum possible GCD * LCM
                if (prod > maxP)
                    break;

                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);

                if (prod == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};


class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for(int j = i; j < n; j++) {

                prod *= nums[j];

                g = gcd(g, (long long)nums[j]);

                l = lcm(l, (long long)nums[j]);

                if(prod == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};






// 1. Initialize ans = 0 to store the maximum length of a valid subarray.
// 2. Use an outer loop with index i to select the starting index of the subarray.
// 3. Use a second loop with index j, starting from i, to select the ending index of the subarray. This generates every possible contiguous subarray.
// 4. For each subarray from i to j, initialize:
// - prod = 1 to calculate the product.
// - g = 0 to calculate the GCD.
// - l = 1 to calculate the LCM.
// 5. Use a third loop with index k from i to j to traverse the current subarray:
// - Multiply each element into prod.
// - Update GCD using gcd(g, nums[k]).
// - Update LCM using lcm(l, nums[k]).
// 6. After traversing the subarray, check whether:
// prod == g * l
// 7. If the condition is satisfied, update the maximum length:
// ans = max(ans, j-i+1)
// 8. Finally, return ans.
  
// Time Complexity: (O(n^3 log M))
// Space Complexity: (O(1))

  
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0 ;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                long long prod = 1;
                long long g = 0;
                long long l = 1;

                for(int k=i;k<=j;k++){
                    prod *= nums[k];
                    g = gcd(g, (long long)nums[k]);
                    l = lcm(l, (long long)nums[k]);
                }
                if(prod == g*l) ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};
