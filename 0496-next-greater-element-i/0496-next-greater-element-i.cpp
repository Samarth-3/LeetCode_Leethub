class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       stack<int>st;
        unordered_map<int,int> umap;

        for(int i=nums2.size()-1;i>=0;i--){
            int ele=nums2[i];
            while(!st.empty() && st.top()<ele){
                st.pop();
            }
            int result=(st.empty())?-1:st.top();
            umap.insert({ele,result});
            st.push(ele);
        }
        
        vector<int> ans;
        for(auto x:nums1){
            ans.push_back(umap[x]);
        }
        return ans;
    }
};