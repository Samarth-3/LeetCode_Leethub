class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector <int> temp(nums.size());
        for(int i=0;i<nums.size();i++){
            temp[(i+k)%nums.size()]=nums[i];
        }

        nums=temp; 
    }
};

// o(1) sol is 
// reverse entire arr
//then reverse first k ele
//then rev k to n-1 elements