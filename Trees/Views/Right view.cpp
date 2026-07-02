//https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1


//bfs
class Solution {
  public:
    vector<int> rightView(Node *root) {
        //  code here
        vector<int>ans;
        if(root==NULL) return ans;
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* node=q.front();
                q.pop();
                if(i==0) ans.push_back(node->data);
                if(node->right){
                    q.push(node->right);
                }
                if(node->left){
                    q.push(node->left);
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

        if (level == ans.size()) {
            ans.push_back(root->data);
        }

        dfs(root->right, level + 1, ans);
        dfs(root->left, level + 1, ans);
    }

    vector<int> rightView(Node *root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};
