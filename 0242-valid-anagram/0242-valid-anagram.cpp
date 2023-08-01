class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr1(26,0);
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            arr1[ch-'a']++;
        }
        vector<int> arr2(26,0);
        for(int i=0;i<t.size();i++){
            char ch=t[i];
            arr2[ch-'a']++;
        }
        
        if(arr1==arr2){
            return true;
        }
        return false;   
    }
};