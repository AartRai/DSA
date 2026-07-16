//https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1

// Approach:
// Use Kruskal's Algorithm to build the Minimum Spanning Tree (MST).
// Sort all edges by weight and process them in increasing order.
// Use Disjoint Set Union (Union-Find) with path compression and union by rank
// to check whether adding an edge forms a cycle. If not, include the edge
// in the MST and add its weight to the answer.

// Intuition:
// The minimum-cost spanning tree is obtained by always choosing the smallest
// available edge that connects two different components without creating a cycle.

// Time Complexity: O(E log E)
// Space Complexity: O(V)

class Solution {
  public:
    vector<int> p,r;
    
    int find(int i){
        if(p[i] == i) return i;
        return p[i] = find(p[i]);
    }
    
    void Union(int x,int y){
        int px = find(x);
        int py = find(y);
        if(px != py){
            if(r[px] < r[py]) p[py] = p[px];
            else if(r[py] < r[px]) p[px] = p[py];
            else{
                p[py] = px;
                r[px]++;
            }
        }
    }
    
    static bool comparator(vector<int>&a, vector<int>&b){
        return a[2]<b[2];
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        p.resize(V+1);
        r.resize(V+1,0);
        for(int i=0;i<=V;i++) p[i] = i;
        
        sort(edges.begin(),edges.end(),comparator);
        int sum = 0;
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            int pu = find(u);
            int pv = find(v);
            
            if(pu != pv){
                Union(u,v);
                sum += w;
            }
        }
        return sum;
    }
};
