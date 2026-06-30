//https://leetcode.com/problems/combination-sum/


//1. At every index, we have two choices:
//     Take the current number.
//      Skip the current number.
//2. If we take a number, we stay on the same index because the problem allows using the same element unlimited times.
//3. If we skip a number, we move to the next index.
//4. Whenever target == 0, we have found a valid combination, so we store it.
//5. If target < 0 or all candidates are exhausted (idx == n), that path is invalid and we return.
//6. Backtracking is used to undo the last choice and explore other possible combinations.

class Solution {
public:
vector<vector<int>>ans;
vector<int>temp;
int n;

    void Backtrack(int idx,vector<int>&candidates, int target){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(idx==n || target<0) return;

        temp.push_back(candidates[idx]);
        Backtrack(idx,candidates,target-candidates[idx]);
        temp.pop_back();
        Backtrack(idx+1,candidates,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        Backtrack(0,candidates,target);
        return ans;
    }
};

