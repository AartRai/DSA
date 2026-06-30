//https://leetcode.com/problems/combination-sum-ii/

//Duplicate combinations are avoided using:
//if(i > idx && candidates[i] == candidates[i - 1])
 //   continue;

class Solution {
public:
    int n;

    void Backtrack(vector<int>& candidates, int target, vector<int>&curr,vector<vector<int>>&result,int idx){
        if(target == 0){
            result.push_back(curr);
            return;
        }

        for(int i=idx;i<n;i++){
            if(i>idx && candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i] > target) break;
            
            curr.push_back(candidates[i]);
            Backtrack(candidates,target-candidates[i],curr,result,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<int>curr;
        vector<vector<int>>result;
        sort(candidates.begin(),candidates.end());

        Backtrack(candidates,target,curr,result,0);
        return result;

    }
};
