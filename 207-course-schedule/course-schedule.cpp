class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        // 1. convert edges to adjlist and precompute the indegree
        vector<vector<int>> adjL(n);
        vector<int>indegree(n,0);

        for(auto edge : prerequisites){
            int u = edge[0];
            int v = edge[1];

            adjL[u].push_back(v);
            indegree[v]++;
        }

        queue<int>q;
        for(int i = 0 ;i < n  ; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();q.pop();
            ans.push_back(node);

            for(auto neighbor : adjL[node]){
                if(indegree[neighbor]){
                    indegree[neighbor]--;
                    if(indegree[neighbor]==0)q.push(neighbor);
                }
            }
        }

        
        if(ans.size() != n)return false;
        return true;
    }
};