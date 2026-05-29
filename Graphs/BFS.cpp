// BFS explores nodes level by level.

// First visit the source node.
// Then visit all its neighbors.
// Then neighbors of those neighbors.
// Continue until all reachable nodes are visited.

// Data Structure Used
// Queue (FIFO)



// Algorithm
// Push source node into queue.
// Mark it visited.
// While queue is not empty:
//   Pop front node.
//   Visit it.
//   Push all unvisited neighbors.


class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int V=adj.size();
        vector<int>visited(V,0);
        vector<int>ans;
        queue<int>q;
        q.push(0);
        visited[0]=1;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto nbr:adj[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=1;
                }
            }
        }
        return ans;
    }
};

//Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
//Output: [0, 2, 3, 1, 4]

//TC O(V+E)
//SC O(V)
