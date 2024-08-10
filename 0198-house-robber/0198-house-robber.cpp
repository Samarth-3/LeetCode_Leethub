// tabulation code
/*
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        int neg=0;
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=dp[i-2];
            int nopick=0+dp[i-1];
            dp[i]=max(pick,nopick);
        }
        return dp[n-1];
    }
};
*/

// space optimised;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1=nums[0];
        int prev2=0;

        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int nopick=0+prev1;
            int curi=max(pick,nopick);
            prev2=prev1;
            prev1=curi;
        }
        return prev1;
    }
};