//BFS is used to traverse the graph level by level. For every node, we also store its parent. While traversing, 
//if we find a visited neighbor that is not the parent, then a cycle exists in the graph.

// Step 1: Create an adjacency list from the given edges.
// Step 2: Create a visited array.
// Step 3: Traverse all vertices.
// Step 4: If a vertex is unvisited:
//          a) Push {node, parent} into queue.
//          b) Mark it as visited.
// Step 5: While queue is not empty:
//          a) Pop front node and parent.
//          b) Traverse all adjacent nodes.
// Step 6: For each neighbor:
//          a) If neighbor is parent,
//             ignore it.
//          b) If neighbor is already visited,
//             cycle is detected.
//          c) Otherwise mark visited
//             and push into queue.
// Step 7: If any BFS call detects a cycle,
//          return true.
// Step 8: If all vertices are processed
//          and no cycle is found,
//          return false.

class Solution {
public:
    bool bfs(int src,vector<vector<int>>&adjList,vector<int>&visited){
      vector<int>parent(visited.size(),-1);
      queue<int>q;
      
      q.push(src);
      visited[src]=1; 
      
      while(!q.empty()){
          int vertex=q.front();
          q.pop();
          
          for(auto nbr: adjList[vertex]){
              if(!visited[nbr]){
                  visited[nbr]=1;
                  parent[nbr]=vertex;
                  
                  q.push(nbr);
              }else if(parent[vertex] !=nbr){
                  return true;
              }
          }
      }
      return false;
  }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);
        
        for(auto &e:edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        
        vector<int> visited(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(bfs(i, adjList, visited))
                    return true;
            }
        }
        
        return false;
    }
};

//TC : O(V + E)
//SC : O(V)
