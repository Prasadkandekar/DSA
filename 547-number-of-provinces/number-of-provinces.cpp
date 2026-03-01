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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<vector<int>> adjL(n);
        int count = 0;

        for(int i = 0 ;i < n; i++){
            for(int j = 0 ; j < m ; j++){
                if(isConnected[i][j]==1 && i != j){
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }// now we have adj list

        vector<int>visited(n,0);

        for(int i = 0 ; i < n ;i++){
            if(!visited[i]){
                dfs(i,adjL,visited);
                count++;
            }
        }

        return count;
    }
};