class DisjointSet{
    public: 
        vector<int>parent,size;
        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i = 1 ;i <= n ; i++){
                parent[i] = i;
            }
        };
        int findParent(int node){
            if(node == parent[node])return node;

            return parent[node] = findParent(parent[node]);
        }
        void unionBySize(int u , int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            
            if(ulp_u == ulp_v) return;

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n );

        //step1 : connects ones in the grid
        for(int i =  0 ;i < n ;i++){
            for(int j = 0;j < n ;j++){
                if(grid[i][j]==0)continue;

                int drow[4] = {1,-1,0,0};
                int dcol[4] = {0,0,1,-1};
                int row = i;
                int col = j;
                for(int k = 0 ;k < 4 ; k++){
                    int nrow = row + drow[k];
                    int ncol = col + dcol[k];

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol]==1){
                        int currNode = row*n + col;
                        int adjNode = nrow*n + ncol;
                        ds.unionBySize(currNode,adjNode);
                    }
                }
            }
        }

        //step 2 : try to convert 0 to 1 and find largest Island
        int maxIsland = 0;
        for(int i = 0 ;i  < n ; i++){
            for(int j = 0 ;j < n ; j++){
                if(grid[i][j]==1)continue;


                int drow[4] = {1,-1,0,0};
                int dcol[4] = {0,0,1,-1};
                int row = i;
                int col = j;
                set<int>components;
                for(int k = 0 ;k < 4 ; k++){
                    int nrow = row + drow[k];
                    int ncol = col + dcol[k];

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n ){
                        if(grid[nrow][ncol] == 1){
                                components.insert(ds.findParent(nrow*n+ncol));
                        }
                        
                    }
                }
                int componentSize = 0;
                for(auto it : components){
                    componentSize += ds.size[it];
                }
            maxIsland = max(maxIsland,componentSize + 1);
            }
        }

        //what if thre are all ones then
        for(int cellNo = 0 ; cellNo < n*n ; cellNo++){
            maxIsland = max(maxIsland, ds.size[ds.findParent(cellNo)] );
        }

        return maxIsland;
    }
};