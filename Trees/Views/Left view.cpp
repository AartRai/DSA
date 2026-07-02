//https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1


//bfs
class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL) return ans;
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* node =q.front();
                q.pop();
                if(i==0) ans.push_back(node->data);
                
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};

//dfs
class Solution {
public:
    void dfs(Node* root, int level, vector<int>& ans) {
        if (!root) return;

        // First node at this level
        if (level == ans.size()) {
            ans.push_back(root->data);
        }

        dfs(root->left, level + 1, ans);
        dfs(root->right, level + 1, ans);
    }

    vector<int> leftView(Node *root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};
