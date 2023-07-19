class Solution {
public:
    bool check(int a[26], int b[26]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int count1[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            int ch = s1[i] - 'a';
            count1[ch]++;
        }
        
        int window = s1.length();
        int count2[26] = {0};
        int i = 0;
        for (i; i < window && i<s2.length(); i++) {
            int index = s2[i] - 'a';
            count2[index]++;
        }
        
        if (check(count1, count2)) {
            return true;
        } 
        
        for(i;i<s2.length() ;i++){
            char newChar=s2[i];
            int index=newChar-'a';
            count2[index]++;
            
            char oldChar=s2[i-window];
            index=oldChar-'a';
            count2[index]--;
            
            if (check(count1, count2)) {
            return true;
            } 
            
        }
        
        return false;
    }
};
