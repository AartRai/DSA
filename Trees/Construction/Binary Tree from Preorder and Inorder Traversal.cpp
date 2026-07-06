https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/


/*
Approach:
1. The first element of preorder is always the root.
2. Find the root's position in inorder traversal.
3. Elements on the left of that position belong to the left subtree,
   and elements on the right belong to the right subtree.
4. Recursively construct:
   - Left subtree using inorder[start ... pos-1]
   - Right subtree using inorder[pos+1 ... end]
5. Preorder index is adjusted to point to the correct root for each subtree.

Time Complexity:
- find() takes O(n) for each node.
- Called for all n nodes.
- Overall: O(n²)

Space Complexity:
- Recursive call stack: O(h)
  - Best/Average case: O(log n)
  - Worst case (skewed tree): O(n)
- Extra space excluding output tree: O(h)
*/


class Solution {
public:
    int find(vector<int>& inorder,int ele){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i] == ele){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int start,int end,int idx){
        if(start > end) return NULL;

        TreeNode* root = new TreeNode(preorder[idx]);
        int pos = find(inorder,preorder[idx]);

        root->left = solve(preorder,inorder,start,pos-1,idx+1);
        root->right = solve(preorder,inorder,pos+1,end,idx+(pos-start)+1);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        return solve(preorder,inorder,0,n-1,0);
    }
};
