class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adjL) {
        int n = adjL.size();
        // as we are getting tle , so we need to create reverse graph and compare parent
        vector<vector<int>> reverseGraph(n);
        vector<int>outdegree(n,0);
        for(int i = 0 ; i < n ;i++){
            outdegree[i] = adjL[i].size();

            for(auto neighbor : adjL[i]){
                reverseGraph[neighbor].push_back(i);
            }

        }

        queue<int>q;
        for(int i = 0 ; i <  n ;i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }

        vector<int>ans;

        while(!q.empty()){
            int node = q.front();q.pop();
            ans.push_back(node);

            // for(int i = 0 ;i < n ;i++){
            //     for(auto neighbor : adjL[i]){
            //         if(neighbor == node){
            //             outdegree[i]--;
            //             if(outdegree[i]==0)q.push(i);
            //         }
            //     }
            // }

            for(auto parent : reverseGraph[node]){
                outdegree[parent]--;
                if(!outdegree[parent]) q.push(parent);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};