class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int maxans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                ans++;
            }
            maxans=max(maxans,ans);
            if(nums[i]==0){
                ans=0;
            }
        }
        return maxans;
    }
};