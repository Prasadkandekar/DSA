class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>>adj(n);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int>xorSub(n,0),in(n),out(n);
        int time = 0;


        function<void(int,int)> dfs = [&](int node, int parent){
            xorSub[node] = nums[node];
            in[node] = time++;
            for(int ch : adj[node]){
                if(ch == parent)continue;
                dfs(ch,node);
                xorSub[node] ^= xorSub[ch];
            }
            out[node] = time++;
        };

        dfs(0,-1);

        auto isAncestor = [&](int u , int v){
            return in[u] <= in[v] && out[v] <= out[u];
        };

        int totalXor = xorSub[0];
        int minScore = INT_MAX;

        vector<pair<int,int>>edgeChildren;

        for(auto &e : edges){
            int u = e[0],
            v = e[1];

            if(in[u] > in[v])swap(u,v);
            edgeChildren.push_back({v,xorSub[v]});
        }

        int m = edgeChildren.size();
        for(int i = 0 ;i < m ;i++){
            for(int j = i+1 ; j < m ;j++){
            int u1 = edgeChildren[i].first,xor1 = edgeChildren[i].second;
            int u2 = edgeChildren[j].first, xor2 = edgeChildren[j].second;

            int x1 , x2 , x3;
            if(isAncestor(u1,u2)){
                x2 = xor2;
                x1 = xor1^xor2;
                x3 = totalXor ^ xor1;
            }else if(isAncestor(u2,u1)){
                x1 = xor1;
                x2 = xor2^xor1;
                x3 = totalXor^xor2;
            }else{

                x1 = xor1;
                x2 = xor2;
                x3 = totalXor^xor1^xor2;
            }

            int maxVal = max({x1,x2,x3});
            int minVal = min({x1,x2,x3});
            minScore = min(minScore, maxVal-minVal);
        }
        }


    return minScore;
    }
};