//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

// Approach:
// Perform Level Order Traversal (BFS) using a queue.
// For each level, store node values in a vector of size 'level size'.
// If traversing left-to-right, place values normally.
// If traversing right-to-left, place values at reversed indices.
// After processing a level, toggle the traversal direction
// and add the level vector to the result.

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
         if(root==NULL){
            return result;
        }
        queue<TreeNode*>q;
        q.push(root);
        
        bool LeftToRight=true;
        
        while(!q.empty()){
            int size=q.size();
            vector<int>ans(size);
            
            for(int i=0;i<size;i++){
                TreeNode* frontnode=q.front();
                q.pop();
                
                int index=LeftToRight ? i : size-i-1;
                ans[index]=frontnode->val;
                
                if(frontnode->left){
                    q.push(frontnode->left);
                }
                
                if(frontnode->right){
                    q.push(frontnode->right);
                }
            }
            LeftToRight=!LeftToRight;
            
            result.push_back(ans);
            
        }
        return result;
    }
};

//TC: O(n)
//SC: O(n)
