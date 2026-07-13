//https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

// Floyd Warshall Algorithm
// Idea: Treat every node as an intermediate (via) node and check
// if path i -> via -> j gives a shorter distance than current i -> j.
//
// TC: O(V^3)  -> Three nested loops (via, i, j)
// SC: O(1)    -> In-place updates (excluding input matrix)
//
// Note:
// - Works for all-pairs shortest paths.
// - Handles negative edge weights (but not negative cycles).
// - Here 1e8 represents INF (no direct path).

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                if(dist[i][via] == 1e8) continue;
                for(int j=0;j<n;j++){
                    if(dist[via][j] == 1e8) continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }
};
