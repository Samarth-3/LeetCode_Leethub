class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>mp;
        for(auto it: t){
            mp[it]++;
        }
        int r=0;
        int l=0;
        int count=0;
        int sindex=-1;
        int mini=INT_MAX;
        while(r<s.size()){
            if(mp[s[r]]>0) count++;
            mp[s[r]]--;
            while(count==t.length()){
                if(r-l+1<mini){
                mini=r-l+1;
                sindex=l;
                }
                
                mp[s[l]]++;
                if(mp[s[l]]>0) count--;
                l++;
            }
            r++;
        }
    return sindex==-1?"":s.substr(sindex,mini);
    }
};