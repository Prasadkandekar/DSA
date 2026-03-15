class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        //1. convert edges to adj list first
        vector<vector<int>> adjL(numCourses);

        for(auto edge : prerequisites){
            int u = edge[0];
            int v = edge[1];

            adjL[v].push_back(u);
        }
        //2. pre compute the indgeree
        vector<int>indegree(numCourses,0);
        for(int i=0 ; i < numCourses ; i++){
            for(auto neighbor : adjL[i]){
                indegree[neighbor]++;
            }
        }

        vector<int> ans;
        queue<int>q;

        // lets push the nodes with indegree 0
        for(int i = 0 ; i < numCourses ;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();q.pop();
            ans.push_back(node);

           for(auto neighbor : adjL[node]){
                indegree[neighbor]--;

                if(indegree[neighbor]==0)q.push(neighbor);
           }
        }
        
    return (ans.size() != numCourses)? vector<int>{} : ans ;
    }
};