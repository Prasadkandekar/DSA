class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adjL(n);
        for(auto flight : flights){
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];

            adjL[u].push_back({v,price});
        }

        //q ->stops,node,cost
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        q.push({0,{src,0}});
        dist[src] =0;

        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if(stops > k)continue;
            for(auto it : adjL[node]){
                int neighbor = it.first;
                int price = it.second;

                if(cost + price < dist[neighbor]){
                    dist[neighbor] = cost + price;
                    q.push({stops+1,{neighbor,cost+price}});
                }

            }
        }

    if(dist[dst]==1e9)return -1;
    return dist[dst];
    }
};