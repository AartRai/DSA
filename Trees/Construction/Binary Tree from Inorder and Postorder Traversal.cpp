//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

/*
Approach:
1. The last element of postorder is always the root.
2. Find the root's position in inorder traversal.
3. Elements left of the root in inorder belong to the left subtree,
   while elements right of the root belong to the right subtree.
4. Since postorder follows Left -> Right -> Root, we process the
   right subtree first when moving backwards from the end of postorder.
5. Recursively construct:
   - Right subtree using inorder[pos+1 ... inend]
   - Left subtree using inorder[instart ... pos-1]

Time Complexity:
- find() takes O(n) in the worst case.
- Performed for every node.
- Overall TC = O(n²)

Space Complexity:
- Recursive call stack: O(h)
  - Balanced tree: O(log n)
  - Skewed tree: O(n)
- Extra space excluding output tree: O(h)
*/

lass Solution {
public:
    int find(vector<int>& inorder, int element,int instart,int inend){
        for(int i=instart;i<=inend;i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;
    }
    TreeNode* Tree(vector<int>& inorder, vector<int>& postorder,int instart,int inend,int indx){
        if(instart>inend){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[indx]);
        int pos=find(inorder,postorder[indx],instart,inend);

        root->right=Tree(inorder,postorder,pos+1,inend,indx-1);
        root->left=Tree(inorder,postorder,instart,pos-1,indx-(inend-pos)-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        return Tree(inorder,postorder,0,n-1,n-1);
    }
};
