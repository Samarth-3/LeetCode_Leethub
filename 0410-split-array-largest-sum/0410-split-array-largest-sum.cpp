class Solution {
public: 
    int fun(int mid,vector<int>& nums,int k){
        int count=1;
        int csum=0;
        for(int i=0;i<nums.size();i++){
            if(csum+nums[i]>mid){
                count++;
                csum=0;
            }
            csum=csum+nums[i];
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=INT_MIN;
        int high=0;
        for(int i=0;i<nums.size();i++){
            low=max(low,nums[i]);
            high+=nums[i];
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            int a=fun(mid,nums,k);
            if(a<=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};