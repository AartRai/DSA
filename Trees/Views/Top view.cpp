//https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

//bfs
class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL) return ans;
        
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            Node* node=it.first;
            int hd=it.second;
            
            if(mp.find(hd)==mp.end()){
                mp[hd]=node->data;
            }
            if(node->left!=NULL){
                q.push({node->left,hd-1});
            }
            if(node->right!=NULL){
                q.push({node->right,hd+1});
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};

//dfs
class Solution {
public:
    map<int, pair<int,int>> mp;
    // hd -> {level, value}

    void dfs(Node* root, int hd, int level) {
        if (!root) return;

        if (mp.find(hd) == mp.end() || level < mp[hd].first) {
            mp[hd] = {level, root->data};
        }

        dfs(root->left, hd - 1, level + 1);
        dfs(root->right, hd + 1, level + 1);
    }

    vector<int> topView(Node *root) {
        vector<int> ans;

        dfs(root, 0, 0);

        for (auto &it : mp) {
            ans.push_back(it.second.second);
        }

        return ans;
    }
};
