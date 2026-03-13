class Solution {
private:
    void bfs(int Startnode, vector<int>& visited, vector<vector<int>>& adjL){
        
        queue<int>q;
        q.push(Startnode);
        visited[Startnode] = 1;

        while(!q.empty()){
            int node = q.front();q.pop();

            for(auto neighbor : adjL[node]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] = 1;
                }
            }
        }

    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        
        //adj matrix to adj list:
        vector<vector<int>> adjL(n);
        
        for(int i = 0 ;i < n ; i++){
            for(int j = 0 ; j < n  ;j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }

        vector<int>visited(n,0);

        int provinces = 0;

        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                bfs(i,visited,adjL);
                provinces++;
            }
        }

    return provinces;
    }
};