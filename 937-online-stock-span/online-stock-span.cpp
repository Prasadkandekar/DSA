class StockSpanner {
public:
    int cnt = 0;
    vector<int>spans;
    StockSpanner() {
        
    }
    
    int next(int price) {
        spans.push_back(price);
         cnt = 1;
         for(int i = spans.size()-2 ;i >= 0 ;i--){
            if(spans[i] <= price)cnt++;
            else break;
         } 
         return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */