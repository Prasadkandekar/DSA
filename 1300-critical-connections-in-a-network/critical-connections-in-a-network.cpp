class Solution {
private : 
int timer = 1;
private:
    void dfs(int node , int parent, vector<vector<int>>& adjL , vector<int>& visited, vector<int>& tin , vector<int>& low, vector<vector<int>>& ans){

        visited[node] = 1;
        tin[node] = timer;
       low[node] = timer;
       timer++;
        
        for(auto adjNode : adjL[node]){
            if(adjNode == parent)continue;
            if(!visited[adjNode]){
             
                dfs(adjNode,node , adjL, visited, tin , low, ans);
                low[node] = min(low[node],low[adjNode]);
                if(low[adjNode] > tin[node]){
                    ans.push_back({adjNode,node});
                }
            }
             low[node] = min(low[node],tin[adjNode]);
            //  if(low[adjNode] > tin[node]){
            //         ans.push_back({adjNode,node});
            //     }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adjL(n);

        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }//adjList is ready

        //now we have to perform dfs , I will assume its only one compoenent and I will make 0 as src node
    //we also need to initialize those two arays
    vector<int>tin(n,0);
    vector<int>low(n,0);
    // we need visited array as well for marking the node visted
    vector<int>visited(n,0);

    // we will store the answer in :
    vector<vector<int>>ans;

    //now we will perform dfs and some operations to get the brides we need
    // we also need to track the timer so we will do it in dfs only
    //dfs -> node , timer , adjList , visited array , tin array , low array
    dfs(0,-1,adjL,visited,tin,low,ans);

    return ans;    
    }
};