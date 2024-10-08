class Solution {
public:
    int fun(int i,int j,vector<int>& nums,vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int maxi=-1e9;
        for(int k=i;k<=j;k++){
            int cost=(nums[i-1]*nums[k]*nums[j+1])+fun(i,k-1,nums,dp)+fun(k+1,j,nums,dp);
            maxi=max(maxi,cost);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return fun(1,n,nums,dp);
    }
};