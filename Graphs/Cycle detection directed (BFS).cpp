//Kahn's Algorithm uses BFS and Indegree. In a Directed Acyclic Graph (DAG), all vertices can be processed using topological sorting. 
//If some vertices remain unprocessed, it means a cycle exists.

// Step 1: Create adjacency list from the given edges.
// Step 2: Calculate indegree of every vertex.
// Step 3: Push all vertices having indegree 0 into a queue.
// Step 4: Initialize count = 0.
// Step 5: While the queue is not empty:
//          a) Remove front node.
//          b) Increment count.
//          c) Traverse its adjacent nodes.
//          d) Decrease their indegree by 1.
//          e) If indegree becomes 0,
//             push it into the queue.
// Step 6: After BFS completes,
//          compare count with V.
// Step 7: If count == V,
//          no cycle exists.
// Step 8: If count < V,
//          cycle is present.


class Solution {
public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        
        for(auto &e : edges) {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        int cnt = 0;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            cnt++;
            
            for(int nbr : adj[node]) {
                indegree[nbr]--;
                
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        
        return cnt != V;
    }
};

// Time Complexity: O(V + E)
// Space Complexity: O(V)
