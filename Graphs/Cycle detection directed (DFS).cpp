// Step 1: Create an adjacency list from the given edges.

// Step 2: Create two arrays:
//          a) vis[]  -> to mark visited nodes.
//          b) path[] -> to track nodes in the current DFS path.

// Step 3: Traverse all vertices.

// Step 4: If a vertex is unvisited, start DFS from it.

// Step 5: Mark the current node as visited
//          and add it to the current path.

// Step 6: Traverse all adjacent nodes.
//          a) If adjacent node is unvisited,
//             perform DFS on it.
//          b) If adjacent node is already
//             present in the current path,
//             cycle is detected.

// Step 7: After visiting all neighbors,
//          remove the current node from the path.

// Step 8: If any DFS call detects a cycle,
//          return true.

// Step 9: If all vertices are processed
//          and no cycle is found,
//          return false.

class Solution {
public:

    bool dfs(int node, vector<vector<int>> &adj,vector<int> &vis, vector<int> &path) {

        vis[node] = 1;
        path[node] = 1;

        for(int nbr : adj[node]) {

            if(!vis[nbr]) {
                if(dfs(nbr, adj, vis, path)) return true;
            }

            else if(path[nbr]) {
                return true;
            }
        }

        path[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {

        vector<vector<int>> adj(V);

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        vector<int> vis(V, 0), path(V, 0);

        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                if(dfs(i, adj, vis, path)) return true;
            }
        }

        return false;
    }
};
// Time Complexity: O(V + E)
// Space Complexity: O(V)
