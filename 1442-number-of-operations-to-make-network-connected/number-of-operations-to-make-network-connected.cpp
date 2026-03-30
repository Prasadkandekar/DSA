class Solution {
private:
    void dfs(int node , vector<vector<int>>& adjL , vector<int>& visited){
        visited[node] = 1;

        for(auto neighbor : adjL[node]){
            if(!visited[neighbor]){
                dfs(neighbor,adjL,visited);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int no_of_edges = connections.size();
        if(no_of_edges < n-1)return -1;
        int ops = 0;

        vector<vector<int>>adjL(n);
        for(auto connection : connections){
            int u  = connection[0];
            int v = connection[1];
            adjL[u].push_back(v);
            adjL[v].push_back(u);

        }
        vector<int>visited(n,0);
        

        for(int i = 0 ;i < n;i++){
            if(!visited[i]){
                dfs(i,adjL,visited);
                ops++;
            }
        }

        return ops-1;
    }
};