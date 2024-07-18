class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = 0;
        int max_sum = nums[0]; // Initialize max_sum with the first element
        
        for (int num : nums) {
            current_sum += num;
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
            if (current_sum < 0) {
                current_sum = 0;
            }
        }
        
        return max_sum;
    }
};
