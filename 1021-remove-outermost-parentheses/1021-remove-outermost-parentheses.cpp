class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;   
        int balance = 0; 

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                // If balance is greater than 0, it means this '(' is not an
                // outermost parenthesis
                if (balance > 0) {
                    result += s[i]; 
                }
                balance++; 
            } else {
                balance--; 
                // If balance is greater than 0, it means this ')' is not an
                // outermost parenthesis
                if (balance > 0) {
                    result += s[i]; 
                }
            }
        }
        return result; 
    }
};