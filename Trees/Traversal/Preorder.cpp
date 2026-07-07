//https://leetcode.com/problems/binary-tree-preorder-traversal/description/

class Solution {
public:
    void solve(TreeNode* root,vector<int> &ans){
        if(root==NULL) return ;
        ans.push_back(root->val);
        solve(root->left,ans);
        solve(root->right,ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};

//TC: O(n)
//SC: O(h)
