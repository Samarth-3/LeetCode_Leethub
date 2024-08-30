class Solution {
public:
    int fun(int index, int prev_index, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if (index == n) {
            return 0;
        }
        if (dp[index][prev_index + 1] != -1) {
            return dp[index][prev_index + 1];
        }
        int notake = 0 + fun(index + 1, prev_index, nums, dp);
        int take = -1e9;
        if (prev_index == -1 || nums[index] > nums[prev_index]) {
            take = 1 + fun(index + 1, index, nums, dp);
        }
        return dp[index][prev_index + 1] = max(take, notake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp array now has n + 1 columns to handle the prev_index + 1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return fun(0, -1, nums, dp);
    }
};
