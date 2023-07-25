class Solution {
private:
    void functionCall(vector<int>& nums,vector<int> &output,int index,vector<vector<int>>&ans){
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        //exclude case
        functionCall(nums,output,index+1,ans);
        
        //include case
        int element=nums[index];
        output.push_back(element);
        functionCall(nums,output,index+1,ans);
        output.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> output;
        int index=0;
        functionCall(nums,output,index,ans);
        return ans;
    }
};