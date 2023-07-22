class Solution {
public:
    int fib(int n) {
        int sum=0;
        if(n==0||n==1){
            return n;
        }
        
        sum+=fib(n-1)+fib(n-2);
        return sum;
    }
};