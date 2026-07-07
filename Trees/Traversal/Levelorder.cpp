//https://leetcode.com/problems/binary-tree-level-order-traversal/description/

// Approach:
// Use BFS (Level Order Traversal) with a queue.
// Push the root node into the queue.
// For each level, process all nodes currently in the queue,
// store their values in a temporary vector, and push their
// left and right children into the queue.
// Add each level's vector to the result and return it.

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root == NULL) return res;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            vector<int> temp;

            while(size--){
                TreeNode* top=q.front();
                q.pop();
                temp.push_back(top->val);
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};

//TC: O(n)
//SC: O(n)
