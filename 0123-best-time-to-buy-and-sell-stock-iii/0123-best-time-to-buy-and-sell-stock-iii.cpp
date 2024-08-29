class Solution {
public:
    int fun(int index,int buy,int trans,vector<int>& prices,vector<vector<vector<int>>> &dp){
        int n=prices.size();
        if(index==n || trans==0){
            return 0;
        }
        if(dp[index][buy][trans]!=-1){
            return dp[index][buy][trans];
        }
        int profit;
        if(buy==1){
            profit=max(-prices[index]+fun(index+1,0,trans,prices,dp),0+fun(index+1,1,trans,prices,dp));
        }
        else{
            profit=max(prices[index]+fun(index+1,1,trans-1,prices,dp),0+fun(index+1,0,trans,prices,dp));
        }
        return dp[index][buy][trans]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return fun(0,1,2,prices,dp);
    }
};