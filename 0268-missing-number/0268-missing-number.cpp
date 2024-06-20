class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size=nums.size();
        for(int i=0;i<size;i++){
            if(i==size-1 && nums[i]==i){
                return i+1;
            }
            if(i==nums[i] ) {continue;}
            return i;
        }
        return -1;
    }
};