class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adjL(n+1);
        for(auto time : times){
            int u = time[0];
            int v = time[1];
            int t = time[2];

            adjL[u].push_back({v,t});
        }

        //q -> time , node
        // queue<pair<int,int>>q;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;
        int ans  = 0;
        while(!pq.empty()){
            int currTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(currTime > dist[node]) continue;
             ans = max(ans,currTime);

            for(auto it : adjL[node]){
                int neighbor = it.first;
                int t = it.second;

                if(currTime + t < dist[neighbor]){
                    dist[neighbor] = currTime+t;
                    pq.push({currTime+t,neighbor});
                }
            }
        }
        for(int i = 1 ;i <= n ;i++){
            if(dist[i]==INT_MAX)return -1;
        }
        return ans;
    }
};