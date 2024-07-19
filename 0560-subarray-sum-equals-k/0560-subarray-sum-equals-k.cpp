class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> map;
        int sum=0;
        int count=0;
        map[0]=1;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            int complement=sum-k;
            count=count+map[complement];       
            map[sum]+=1;
        }
        return count;
    }
};