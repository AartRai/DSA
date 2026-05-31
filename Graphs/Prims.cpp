// Prim's Algorithm finds the Minimum Spanning Tree (MST)
// of a connected weighted undirected graph.

// Step 1: Create a Min Heap (Priority Queue)
//         to always pick the edge with minimum weight.
// Step 2: Push {0, 0} into the heap
//         (weight = 0, starting node = 0).
// Step 3: Maintain a visited array (inMST)
//         to track nodes already included in MST.
// Step 4: While the heap is not empty:
//          a) Extract the minimum weight edge.
//          b) If the node is already in MST,
//             skip it.
//          c) Otherwise, include the node in MST.
//          d) Add its edge weight to the answer.
//          e) Traverse all adjacent nodes.
//          f) If a neighbor is not in MST,
//             push {edge_weight, neighbor}
//             into the heap.
// Step 5: Continue until all vertices are included.
// Step 6: Return the total weight of the MST.

// Why does Prim's Algorithm work?
// At every step, it chooses the minimum weight edge
// that connects a visited node to an unvisited node.
// This greedy choice always leads to a valid MST.

// Time Complexity: O(E log V)
// Space Complexity: O(V)

class Solution
{
    typedef pair<int, int> P;

	public:
	int spanningTree(int V, vector<vector<int>> adj[])
	{
	    priority_queue<P, vector<P>, greater<P>> pq;

	    pq.push({0, 0});

	    vector<bool> inMST(V, false);

	    int sum = 0;

	    while(!pq.empty())
	    {
	        auto p = pq.top();
	        pq.pop();

	        int wt = p.first;
	        int node = p.second;

	        if(inMST[node])
	            continue;

	        inMST[node] = true;
	        sum += wt;

	        for(auto &tmp : adj[node])
	        {
	            int neighbor = tmp[0];
	            int neighbor_wt = tmp[1];

	            if(!inMST[neighbor])
	            {
	                pq.push({neighbor_wt, neighbor});
	            }
	        }
	    }
	    return sum;
	}
};


//TC : O(E log V)
//SC : O(E + V)
