//https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/?envType=daily-question&envId=2026-11-15


// Brute Force Approach
// Approach
// 1. Run an outer loop i to select the starting index.
// 2. Initialize sum = 0 for every starting index.
// 3. Run an inner loop j to select the ending index.
// 4. Add arr[j] to the sum.
// 5. If sum is odd (sum % 2 != 0), increment the answer.
// 6. Return the answer modulo \(10^9 + 7\).


// Time Complexity: (O(N^2)) — Two nested loops.
// Space Complexity: (O(1)) — Only a few variables are used.

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int odd = 0 ;
        int mod = 1e9 + 7;

        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += arr[j];

                if(sum %2 != 0){
                    odd++;
                    odd%=mod;
                }

            }
        }
        return odd;
    }
};


// Create a prefix sum array.
// Calculate the cumulative sum at every index.
// Traverse the prefix array.
// If the current prefix sum is even:
// - Add the number of previous odd prefix sums to count.
// - Increment even.
// If the current prefix sum is odd:
// - Add the number of previous even prefix sums to count.
// - Increment odd.
// Apply modulo \(10^9+7\) and return count.

// - Time Complexity: (O(N))
// - Space Complexity: (O(N))

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int M = 1e9+7;
        vector<int>prefix(n,0);
        prefix[0] = arr[0];

        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + arr[i];
        }
        int count=0;
        int odd=0;
        int even =1;

        for(int i=0;i<n;i++){
            if(prefix[i] %2 ==0){
                count=(count+odd)%M;
                even++;
            }else{
                count=(count+even)%M;
                odd++;
            }
        }
        return count;
    }
};

// - Time Complexity: (O(N))
// - Space Complexity: (O(1))
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int M = 1e9+7;
        
        int count=0;
        int odd=0;
        int even =1;
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum %2 ==0){
                count=(count+odd)%M;
                even++;
            }else{
                count=(count+even)%M;
                odd++;
            }
        }
        return count;
    }
};
