class Solution {
public:
    int sum(vector<int>& nums,int threshold,int mid){
        int s=0;
        for(int i=0;i<nums.size();i++){
            s+=ceil((double)nums[i]/(double)mid);
        }
        return s;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int high=INT_MIN;
        for(int i=0;i<nums.size();i++){
            high=max(high,nums[i]);
        }
        
        int low=1;
        sort(nums.begin(),nums.end());
        int mainans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int ans=sum(nums,threshold,mid);
            if(ans<=threshold){
                mainans=mid;
                high=mid-1;
            }
            //ans<threshold
            else{
               low=mid+1;
            }
        }
        return mainans;
    }
};