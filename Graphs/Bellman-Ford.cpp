// Bellman-Ford Algorithm finds the shortest distance
// from a source node to all other nodes.
// It also detects negative weight cycles.

// Step 1: Initialize distance array with INF.
// Step 2: Set distance[source] = 0.
// Step 3: Repeat (V-1) times:
//          a) Traverse all edges.
//          b) For every edge (u → v) with weight wt,
//             if distance[u] is reachable and
//             distance[u] + wt < distance[v],
//             update distance[v].
// Step 4: After (V-1) relaxations,
//         shortest distances are obtained.
// Step 5: Traverse all edges one more time.
// Step 6: If any edge can still be relaxed,
//         a negative weight cycle exists.
// Step 7: Return {-1} if a negative cycle is found.
// Step 8: Otherwise return the distance array.

//Why V-1 Iterations?
//In a graph with V vertices, the longest possible shortest path can contain at most V-1 edges.
//Therefore, relaxing all edges V-1 times guarantees that every shortest path is found.

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        for(int i = 1; i < V; i++){
            for(auto &e : edges)
                int u = e[0];
                int v = e[1];
                int wt = e[2];

                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                return {-1};
            }
        }
        return dist;
    }
};


//TC : O(VE)
//SC : O(V)
