class Solution {
public:
    int fun(vector<int>& arr) {
        int n=arr.size();
        int prev1=arr[0];
        int prev2=0;

        for(int i=1;i<n;i++){
            int pick=arr[i];
            if(i>1) pick+=prev2;
            int nopick=0+prev1;
            int curi=max(pick,nopick);
            prev2=prev1;
            prev1=curi;
        }
        return prev1;
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){return nums[0];}
        vector<int> firstinc;
        vector<int> lastinc;
        for(int i=0;i<n;i++){
            if(i!=0) lastinc.push_back(nums[i]);
            if(i!=n-1) firstinc.push_back(nums[i]);
        }
        return max(fun(firstinc),fun(lastinc));
    }
};