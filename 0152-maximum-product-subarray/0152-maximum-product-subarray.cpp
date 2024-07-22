class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(); 

        long long int pre = 1, suff = 1;
        long long int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            if(pre == 1000000000 || suff == 1000000000) break;
            if (pre == 0) pre = 1;
            if (suff == 0) suff = 1;
            pre *= nums[i];
            suff *= nums[n - i - 1];
            ans = max(ans, max(pre, suff));
        }
        return ans;
    }
};