// Topological Sort (DFS)

// Topological Sort is used for Directed Acyclic Graphs (DAG).

// First visit a node.
// Then recursively visit all its unvisited neighbors.
// After visiting all neighbors, push the node into a stack.
// Finally, pop elements from the stack to get the topological order.

// Data Structure Used
// Stack (LIFO) + Recursion

// Algorithm
// Create an adjacency list from edges.
// Initialize a visited array.
// For every unvisited vertex:
//   Perform DFS.
// In DFS:
//   Mark current node as visited.
//   Visit all unvisited neighbors recursively.
//   Push current node into stack after exploring all neighbors.
// Pop all elements from the stack.
// The obtained order is the topological sorting.

class Solution {
  public:
  
    void DFS(int vertex,vector<vector<int>>&adjList,vector<bool>&visited,stack<int>&s){
        visited[vertex]=1;
        
        for(auto nbr :adjList[vertex]){
            if(!visited[nbr]){
                DFS(nbr,adjList,visited,s);
            }
        }
        s.push(vertex);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adjList(V);
        for(auto &e:edges){
            adjList[e[0]].push_back(e[1]);
        }
        vector<bool>visited(V,0);
        stack<int>s;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                DFS(i,adjList,visited,s);
            }
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
        
    }
};

//TC: O(V + E)
//SC: O(V + E)
