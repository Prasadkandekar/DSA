class DisjointSet{
    vector<int>parent,size;
    public:
        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i= 0 ;i < n; i++){
                parent[i] = i;
            }
        }//init done


        int findParent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }


        void unionBySize(int u , int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);

            if(ulp_u == ulp_v)return;

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int>mp;
        DisjointSet ds(n);
        for(int i = 0 ;i < n ;i++){
            for(int j = 1 ;j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mp.find(mail) != mp.end()){
                    ds.unionBySize(i,mp[mail]);
                }else{
                    mp[mail] = i;
                }
            }
        }//union done

        //merging Now :
        vector<vector<string>> mergedMails(n);

        for(auto it : mp){
            int parent = ds.findParent(it.second);
            mergedMails[parent].push_back(it.first);
        }

        vector<vector<string>>ans;

        for(int i = 0 ;i < n ; i++){
            vector<string>temp;
            if(mergedMails[i].size()==0)continue;

            temp.push_back(accounts[i][0]);
            sort(mergedMails[i].begin(),mergedMails[i].end());
            for(auto mail: mergedMails[i]){

                temp.push_back(mail);
            }
           
            ans.push_back(temp);
        }

return ans;

    }
};