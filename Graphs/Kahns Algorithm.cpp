//https://www.geeksforgeeks.org/problems/topological-sort/1

// Approach:
// 1. Build adjacency list and calculate indegree of each node.
// 2. Push all nodes with indegree 0 into a queue.
// 3. Repeatedly remove a node from the queue, add it to the answer,
//    and decrease the indegree of its neighbors.
// 4. If a neighbor's indegree becomes 0, push it into the queue.
// 5. The resulting order is the topological ordering (Kahn's Algorithm).

// TC: O(V + E)
// SC: O(V + E)

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code hereu
        queue<int>q;
        vector<int>indegree(V,0);
        vector<int>ans;
        
        //create adj list
        vector<vector<int>>adj(V);
        for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        //push the elememts which have indegree 0 to the queue
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans.push_back(top);
            
            for(int nbr : adj[top]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        return ans;
    }
};
