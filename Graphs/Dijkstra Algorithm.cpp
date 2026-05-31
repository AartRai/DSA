// Dijkstra's Algorithm finds the shortest distance from
// a source node to all other nodes in a weighted graph
// (weights must be non-negative).

// Step 1: Create adjacency list from the given edges.
// Step 2: Initialize distance array with INT_MAX.
// Step 3: Mark distance of source node as 0.
// Step 4: Create a min-heap (priority queue)
//         storing {distance, node}.
// Step 5: Push {0, source} into the priority queue.
// Step 6: While the priority queue is not empty:
//          a) Extract the node having minimum distance.
//          b) If the node is already visited,
//             continue.
//          c) Mark the node as visited.
//          d) Traverse all its adjacent nodes.
//          e) If a shorter path is found:
//               distance[adjNode] =
//               distance[currentNode] + edgeWeight
//             push updated distance and node
//             into the priority queue.
// Step 7: Repeat until the priority queue becomes empty.
// Step 8: Distance array now contains the shortest
//         distance from source to every vertex.
// Step 9: Return the distance array.



class Solution {
  public:
  typedef pair<int,int> P;
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<P>> adj(V);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int>visited(V,0);
        vector<int>distance(V,INT_MAX);
        priority_queue<P,vector<P>,greater<P>> pq;
        
        distance[src]=0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(visited[node]) continue;
            visited[node]=1;
            
            for(auto nbr:adj[node]){
                int n=nbr.first;
                int d=nbr.second;
                
                if(distance[node] + d < distance[n]){
                    distance[n] =  distance[node] + d;
                    pq.push({distance[node] + d,n});
                }
            }
        }
        return distance;
    }
};

//TC : O((V + E) log V)
//SC: O(V + E) 
