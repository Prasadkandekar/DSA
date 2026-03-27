class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>>dist(n,vector<int>(n,1e9));

        for(int i = 0 ; i < n ; i++){
            dist[i][i] = 0;//self zero
        }

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            dist[u][v] = min(dist[u][v],wt); 
            dist[v][u] = min(dist[v][u],wt);

        }//adj matrix is ready;

        //apply floyd warshall algorithm;

        for(int k = 0 ; k < n; k++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(dist[i][k] == 1e9 || dist[k][j]== 1e9)continue;
                    dist[i][j] = min(dist[i][j] ,dist[i][k] + dist[k][j]);
                }
            }
        }//dist arr ready

        //now we have to find the max dist[i][j] < dthreshold
        // int ans_dist = -1;
        // int ans_city = -1;
        // for(int i = 0 ; i < n ;i++ ){
        //     for(int j = 0 ;j < n ;j++){
        //         if(dist[i][j] <= distanceThreshold ){
        //                  ans_dist= max(ans_dist, dist[i][j]);
        //                  ans_city = dist[i][j];
        //         }
        //     }
        // }

        int cntMax = n+1;
        int city = -1;
        for(int i = 0 ;i < n ;i++){
             int cnt = 0;
           for(int j = 0 ; j < n ;j++){
               
                if(dist[i][j] <= distanceThreshold){
                    cnt++;  
                }
           }
           if(cnt <= cntMax){
                    cntMax = cnt;
                    city = i;
                }
        }

    return city;
    }
};