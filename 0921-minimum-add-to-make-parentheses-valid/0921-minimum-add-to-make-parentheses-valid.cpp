class Solution {
public:
    int minAddToMakeValid(string s) {
        stack <char> st;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='('){
                st.push(ch);
            }
            else{
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
        while(!st.empty()){
            cnt++;
            st.pop();
        }
        return cnt;
    }
};