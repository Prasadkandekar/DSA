class Solution {
public:
    const long long MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
       
        //adjL -> node , time
        vector<vector<pair<int,int>>>adjL(n);
        for(auto road : roads){
            int u = road[0];
            int v = road[1];
            int time = road[2];

            adjL[u].push_back({v,time});
            adjL[v].push_back({u,time});
        }

        //pq -> (time , node)
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long , long long>>>pq;
        vector<long long>dist(n,1e12);
        vector<long long>ways(n,0);
        pq.push({0,0});
        dist[0] = 0;
        ways[0]  = 1;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long currTime = it.first;
            long long node = it.second;

            for(auto iter : adjL[node]){
                long long neighbor = iter.first;
                long long reqTime = iter.second;

                if(currTime + reqTime < dist[neighbor]){
                    dist[neighbor] = currTime + reqTime;
                    ways[neighbor] = ways[node];
                    pq.push({currTime+reqTime, neighbor});
                }else if(currTime + reqTime == dist[neighbor]){
                    ways[neighbor] = (ways[neighbor]+ways[node])%MOD;
                }

            }
        }


        return ways[n-1]%MOD;
    }
};