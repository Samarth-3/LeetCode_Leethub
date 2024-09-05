class Solution {
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<int, int> m;
        int maxlen = 0;
        int l = 0;
        int n = s.length();
        int maxfreq = 0;
        for (int r = 0; r < n; r++)
        {
            m[s[r] - 'a']++;
            maxfreq = max(maxfreq, m[s[r] - 'a']);
            int len = r - l + 1;
            int change = len - maxfreq;

            if (change > k)
            {
                m[s[l] - 'a']--;
                l++;
            }
            else
            {
                maxlen = max(maxlen, len);
            }
        }

        return maxlen;
    }
};