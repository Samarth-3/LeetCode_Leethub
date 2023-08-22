class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int len = tokens.size();
        
        for (int i = 0; i < len; i++) {
            string curr = tokens[i];
            
            if (isdigit(curr[0]) || (curr.length() > 1 && curr[0] == '-')) {
                //second or cond to handle neg num like -11 in case 3
                st.push(stoi(curr)); // Convert string to integer
            } else {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                
                if (curr == "+") {
                    st.push(a + b);
                } else if (curr == "*") {
                    st.push(a * b);
                } else if (curr == "/") {
                    st.push(b / a);
                } else if (curr == "-") {
                    st.push(b - a);
                }
            }
        }
        
        return st.top();
    }
};
