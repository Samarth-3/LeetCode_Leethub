class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0 ; 
        int n = s.size() ; 
        int maxi = 0  ;
        map<char , int >mpp ;  
        for(int r = 0 ; r< n ; r++){
            if(mpp.find(s[r])!= mpp.end()){
                if(mpp[s[r]]>=l){
                    l=mpp[s[r]] + 1;
                }
            }
            mpp[s[r]] = r ; 
            maxi = max(maxi , r-l+1) ; 
        }
        return maxi ;
    }
};
