class StockSpanner {
public:
    stack<pair<int,int>> s;
    int index=-1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        index+=1;
        int ans;
        while(s.size()!=0 && s.top().first<=price){
            s.pop();
        }
        if(s.empty()){
            ans=index-(-1);
        }else{
            ans=index-s.top().second;
        }
        s.push({price,index});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */