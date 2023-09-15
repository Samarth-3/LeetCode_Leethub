class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;

        for (int i = 0; i < s.length(); ++i) {
            char sChar = s[i];
            char tChar = t[i];

            // Check if sChar already maps to tChar in sToT
            if (sToT.find(sChar) != sToT.end()) {
                if (sToT[sChar] != tChar) {
                    return false; // Mismatch in mapping
                }
            } else {
                sToT[sChar] = tChar;
            }

            // Check if tChar already maps to sChar in tToS
            if (tToS.find(tChar) != tToS.end()) {
                if (tToS[tChar] != sChar) {
                    return false; // Mismatch in mapping
                }
            } else {
                tToS[tChar] = sChar;
            }
        }

        return true;
    }
};
