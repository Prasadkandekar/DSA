class Solution {
private:
    bool dfs(int node , int col,vector<vector<int>>& graph , vector<int>& color){
        color[node] = col;

        for(auto neighbor : graph[node]){
            if(color[neighbor]==-1){
                if(dfs(neighbor,!col,graph,color)==false)return false;;
            }else if(color[neighbor] == col){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();

        // firstly we  are given adjlist so no issue here
        // we wil declare color array with -1;

        vector<int>color(n,-1);

         for(int i = 0 ;i < n ;i++){
            if(color[i]==-1){
               if(dfs(i,0,graph,color)== false)return false;;
            }
         }
        return true;
    }
};