class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end());
        if(st.find(endGene) == st.end())return -1;
        if(startGene == endGene)return 0;
        queue<pair<string,int>>q;
        q.push({startGene,1});
        st.erase(startGene);

        char Gene[] = {'A','C','G','T'};
        while(!q.empty()){
   
   

            string gene = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(gene == endGene)return steps-1;

            for(int i = 0 ; i < gene.size() ;i++){
                    char original = gene[i];
                    for(int j = 0 ;j < 4 ;j++){
                        gene[i] = Gene[j];
                        if(st.find(gene) != st.end()){
                            st.erase(gene);
                            q.push({gene,steps+1});
                        }
                        
                    }
                    gene[i] = original;
            }

        }
        return -1;
    }
};