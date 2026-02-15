class Solution {
private:
    void dfs(int node,vector<vector<int>>& isConnected,vector<int>& visited){
        visited[node] = 1;

        // for(auto neighbor : isConnected[node]){
        //     if(!visited[neighbor]){
        //         dfs(neighbor,isConnected,visited);
        //     }
        // }

        for(int i = 0 ; i< isConnected.size() ;i++){

            if(isConnected[node][i]==1 && visited[i] == 0){
                dfs(i,isConnected,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        int n = isConnected.size();
        vector<int>visited(n,0);

        for(int i = 0 ; i < n ;i++){
            int node = i;
            if(!visited[node]){
                
                dfs(node,isConnected,visited);
                provinces++;
            }
        }

    
        return provinces;

    }
};