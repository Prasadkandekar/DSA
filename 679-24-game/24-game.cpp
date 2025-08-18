class Solution {
public:
    bool canMake24(vector<double>& cards,double target , double epsilon){
        if(cards.size()==1)return abs(cards[0]-target) < epsilon;

        for(int i = 0 ;i < cards.size() ; i++){
            for(int j = i+1 ; j < cards.size() ;j++){
                double a = cards[i];
                double b = cards[j];

                vector<double>result;
                result.push_back(a+b);
                result.push_back(a-b);
                result.push_back(b-a);
                result.push_back(a*b);
                if(a != 0)result.push_back(b/a);
                if(b != 0)result.push_back(a/b);
                    
                for(auto& r:result){
                    vector<double>next;
                for(int k = 0 ;k < cards.size(); k++){
                    if(k != i && k != j){
                        next.push_back(cards[k]);
                    }
                }
                next.push_back(r);
                if(canMake24(next,target,epsilon))return true;
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double>card;
        for(auto& el : cards){
            card.push_back((double)el);
        }
        double target = 24.0;
        double epsilon = 1e-6;
        return canMake24(card,target,epsilon);
    }
};