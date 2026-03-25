class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>>adjL(n);
        //adjL =>  node  , price
        for(auto flight : flights){
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];

            adjL[u].push_back({v,price});
        }

        //q => stops,node,dist
       queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        dist[src] = 0;
        q.push({0,{src,0}});
   
        while(!q.empty()){

           int currStops = q.front().first;
           int node = q.front().second.first;
           int currDist = q.front().second.second;
          
           q.pop();
            if(currStops > k) continue;
       

            for(auto it : adjL[node]){
                int neighbor = it.first;
                int price = it.second;

                if(currDist + price < dist[neighbor]){
                    dist[neighbor] = currDist + price;
                    q.push({currStops+1,{neighbor,currDist+price}});
                }
            }
            
        }
        if(dist[dst] == 1e9 )return -1;
     return dist[dst];
    }
};