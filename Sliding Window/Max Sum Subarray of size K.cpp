//https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int i=0;
        int sum=0;
        
        while(i<k){
            sum+=arr[i];
            i++;
        }
        
        int window=sum;
        while(i<n){
            window -= arr[i-k];
            window += arr[i];
            sum = max(sum,window);
            i++;
        }
        return sum;
    }
};

//TC : O(n)
//SC : O(1)
