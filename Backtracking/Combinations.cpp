//https://leetcode.com/problems/combinations/?envType=problem-list-v2&envId=backtracking


// 1. Maintain a temporary vector curr.
// 2. Start from start = 1.
// 3. Try every number i from start to n.
// 4. Add i to curr.
// 5. Recurse with start = i + 1 (to avoid duplicates).
// 6. Remove i (backtrack).
// 7. When curr.size() == k, store the combination.

class Solution {
public:
    vector<vector<int>> ans;
    vector<int>temp;

    void BackTrack(int idx,int n,int k){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<=n;i++){
            temp.push_back(i);
            BackTrack(i+1,n,k);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        BackTrack(1,n,k);
        return ans;
    }
};
