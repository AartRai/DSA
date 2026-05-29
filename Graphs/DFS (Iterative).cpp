// Depth First Search (DFS) using Stack

// DFS explores one path completely before exploring another path.

// Step 1: Start from the source node.
// Step 2: Mark the source node as visited.
// Step 3: Push the source node into the stack.
// Step 4: While the stack is not empty:
//          a) Remove the top node.
//          b) Visit the node.
//          c) Traverse all its adjacent nodes.
//          d) If an adjacent node is unvisited:
//                - Mark it as visited.
//                - Push it into the stack.
// Step 5: Repeat until the stack becomes empty.

// Data Structure Used:
// Stack (LIFO)

void dfs(int src, vector<vector<int>>& adj, vector<int>& vis,vector<int>& res) {

    stack<int> st;

    vis[src] = 1;
    st.push(src);

    while (!st.empty()) {

        int node = st.top();
        st.pop();

        res.push_back(node);

        for (int nbr : adj[node]) {

            if (!vis[nbr]) {

                vis[nbr] = 1;
                st.push(nbr);
            }
        }
    }
}

// Time Complexity: O(V + E)
// Space Complexity: O(V)
