class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long digit=x;
        long reverse=0;
        while(x!=0){
            int a=x%10;
            reverse=reverse*10+a;
            x=x/10;
        }
        if(digit==reverse) return true;
        return false;
    }
};