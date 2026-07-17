https://leetcode.com/problems/course-schedule/description/

// Approach:
// Build a graph where prerequisite -> course.
// Use Kahn's Algorithm (BFS Topological Sort).
// Push all nodes with indegree 0 into a queue.
// Process nodes, reduce indegree of neighbors, and push new indegree 0 nodes.
// If all courses are processed, no cycle exists and all courses can be finished.

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        queue<int>q;
        int count=0;

        for(auto &e:prerequisites){
            int u=e[1];
            int v=e[0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto x: adj[node]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }
        return count==numCourses;
    }
};
