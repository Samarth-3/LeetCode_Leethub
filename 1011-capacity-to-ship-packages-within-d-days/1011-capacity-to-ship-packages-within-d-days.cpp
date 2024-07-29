class Solution {
public:
    int fun(vector<int>& weights,int days,int mid){
        int stepsum=0;
        int counter=0;
        for(int i=0;i<weights.size();i++){
            if(stepsum+weights[i]>mid){
                stepsum=0;
                counter++;
            }
            stepsum+=weights[i];
        }
        counter++;
        return counter;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int high=0;
        int low=INT_MIN;
        for(int i=0;i<weights.size();i++){
            high+=weights[i];
            low=max(low,weights[i]);
        }

        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int a=fun(weights,days,mid);
            if(a<=days){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};