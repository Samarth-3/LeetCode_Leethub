class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int zcount=0;
        int maxi=-1;
        int n=nums.size();
        while(r<n){
            if(nums[r]==0){
                zcount++;
                while(zcount>k){
                    if(nums[l]==0){
                        zcount--;
                    }
                    l++;
                }
                
            }
            int len=r-l+1;
            maxi=max(maxi,len);
            r++;
        }
        return maxi;
    }
};