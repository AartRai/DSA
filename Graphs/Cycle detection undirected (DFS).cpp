//DFS traverses the graph depth-wise. While visiting a node, we keep track of its parent. If we encounter a visited neighbor that is not the parent, then a cycle exists.

// Step 1: Create an adjacency list from the given edges.
// Step 2: Create a visited array.
// Step 3: Traverse all vertices.
// Step 4: If a vertex is unvisited,
//          start DFS from it.
// Step 5: Mark the current node as visited.
// Step 6: Traverse all adjacent nodes.
//          a) If neighbor is unvisited,
//             perform DFS on it.
//          b) If neighbor is already visited
//             and is not the parent,
//             cycle is detected.
// Step 7: If any DFS call detects a cycle,
//          return true.
// Step 8: If all vertices are processed
//          and no cycle is found,
//          return false.


class Solution {
  public:
  
  bool dfs(int src,int parent,vector<vector<int>>&adjList,vector<int>&visited ){
      visited[src]=1;
      for(auto nbr: adjList[src]){
          if(!visited[nbr]){
              if(dfs(nbr,src,adjList,visited)) return true;
          }else if(nbr !=parent){
                  return true;
          }
      }
      return false;
  }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adjList(V);
        vector<int> visited(V,0);
        for(auto &e: edges){
            int u=e[0];
            int v=e[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int>parent(V);
        
        for(int i=0;i<V;i++){
            if (!visited[i]) {                
                if(dfs(i,-1,adjList,visited)) return true;
            }
        }
        
        return false;
    }
};

//TC = O(V+E);
//SC = O(V) 
