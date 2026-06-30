//https://leetcode.com/problems/combination-sum-iii/


// Backtracking: Try all combinations using numbers 1 to 9.
// For each number, we have two choices: pick it or skip it.
// If we select exactly k numbers and the remaining sum becomes 0,
// we have found a valid combination and add it to the answer.

class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;

    void BackTrack(int i,int k,int n){

        if(n==0 && temp.size()==k){
            ans.push_back(temp);
            return;
        }

        if(i>9 || i<0 || temp.size()>k) return;

        //Pick
        temp.push_back(i);
        BackTrack(i+1,k,n-i);
        temp.pop_back();

        //not pick
        BackTrack(i+1,k,n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        BackTrack(1,k,n);
        return ans;
    }
};
