//https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/

// Approach:
// 1. Calculate the total sum of the tree using DFS.
// 2. Traverse again and find the sum of every subtree.
// 3. Assume the edge above the current subtree is cut.
// 4. Product = subtreeSum * (totalSum - subtreeSum).
// 5. Keep track of the maximum product and return it modulo 1e9+7.
//
// Time Complexity: O(n)
// Space Complexity: O(h)   // h = height of tree (O(n) worst case)

class Solution {
public:
    long long total = 0, ans = 0;
    const int MOD = 1e9 + 7;

    long long findTotal(TreeNode* root) {
        if (!root) return 0;
        return root->val + findTotal(root->left) + findTotal(root->right);
    }

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long currSum = root->val + left + right;

        ans = max(ans, currSum * (total - currSum));

        return currSum;
    }

    int maxProduct(TreeNode* root) {
        total = findTotal(root);
        dfs(root);

        return ans % MOD;
    }
};
