class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        
        long long sum=0;
        
        while(pq.size() > 1){
            long long a= pq.top();
            pq.pop();
            
            long long b=pq.top();
            pq.pop();
            
            sum += a+b;
            pq.push(a+b);
        }
        return sum;
    }
};
//TC : O(n log n)
//SC : O(n)
