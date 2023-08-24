class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> output;
        for (int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    s.insert({nums[i], nums[j], nums[k]}); //set always have unique values
                    j++;
                    k--;
                } else if (sum < 0) {
                    j++;
                } else { //sum greater than 0
                    k--;
                }
            }
        }
        for(auto triplets : s)  //set ki values ko output mae push
            output.push_back(triplets);
        return output;
    }
};