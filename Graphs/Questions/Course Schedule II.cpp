//https://leetcode.com/problems/course-schedule-ii/

// Approach:
// Build a graph where prerequisite -> course.
// Use Kahn's Algorithm (BFS Topological Sort) to generate a valid course order.
// Start with all nodes having indegree 0.
// Process each node, add it to the answer, and reduce indegree of its neighbors.
// If all courses are included in the answer, return the order; otherwise a cycle exists, so return {}.

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int>ans;
        queue<int>q;
        
        for(auto &e : prerequisites ){
            int u = e[1];
            int v = e[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        for(int i=0 ; i<numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto x : adj[node]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};
