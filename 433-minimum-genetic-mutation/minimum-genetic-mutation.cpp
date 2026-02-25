class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end());
        if(st.find(endGene) == st.end())return -1;
        if(startGene == endGene)return 0;
        queue<string>q;
        q.push(startGene);
        st.erase(startGene);
        int level = 0;
        char Gene[] = {'A','C','G','T'};
        while(!q.empty()){
            int size = q.size();
            while(size--){

            string gene = q.front();q.pop();
            if(gene == endGene)return level;

            for(int i = 0 ; i < gene.size() ;i++){
                    char original = gene[i];
                    for(int j = 0 ;j < 4 ;j++){
                        gene[i] = Gene[j];
                        if(st.find(gene) != st.end()){
                            st.erase(gene);
                            q.push(gene);
                        }
                        
                    }
                    gene[i] = original;
            }
            }

             level++;
        }
        return -1;
    }
};