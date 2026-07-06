//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/

/*
Approach:
1. Create nodes using preorder (Root -> Left -> Right).
2. Use postorder to determine when a subtree is complete.
3. Build left child first, then right child.
4. If root->val == postorder[post], current subtree is finished.
5. Increment post and return the root.

TC: O(n)   // Each node is processed once
SC: O(h)   // Recursion stack (O(log n) balanced, O(n) skewed)
*/

class Solution {
public:
    int pre = 0;
    int post = 0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[pre]);
        pre++;

        if(root->val != postorder[post]) root->left = constructFromPrePost(preorder,postorder);
        if(root->val != postorder[post]) root->right = constructFromPrePost(preorder,postorder);

        post++;

        return root;

    }
};
