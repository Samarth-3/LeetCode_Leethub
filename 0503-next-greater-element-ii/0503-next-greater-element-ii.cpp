class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        
        for (int i = 0; i < 2 * n; i++) {
            int current = nums[i % n];
            
            for (int j = i + 1; j < 2 * n; j++) {
                if (nums[j % n] > current) {
                    ans[i % n] = nums[j % n];
                    break;
                }
            }
        }
        return ans;
    }
};
