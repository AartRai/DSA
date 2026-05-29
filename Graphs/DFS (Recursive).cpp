// DFS (Depth First Search)

// DFS explores nodes depth-wise.

// First visit the source node.
// Then visit one unvisited neighbor.
// Keep going deeper until no unvisited neighbor remains.
// Backtrack to the previous node.
// Continue until all reachable nodes are visited.

// Data Structure Used
// Recursion Stack (or Explicit Stack)


// Algorithm
// Visit the current node.
// Mark it visited.
// For every neighbor:
//     If neighbor is unvisited:
//         Call DFS on that neighbor.
// Continue until all nodes are processed.



class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &result) {
        visited[node] = true;
        result.push_back(node);
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, result);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> result;
        vector<bool> visited(V, false);

        dfs(0, adj, visited, result);

        return result;
    }
};

// TC: O(V + E)
// SC : O(V)
