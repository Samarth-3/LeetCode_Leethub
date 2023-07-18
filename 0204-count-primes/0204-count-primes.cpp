class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1,true);
        int count=0;
        prime[0]=prime[1]=0;
        for(int i=2;i<n;i++){
            if(prime[i]){
                count++;
                for(int j=2*i;j<n;j=j+i){
                    prime[j]=0;
                }
            }
        }
        return count;
        
        // if (n <= 2) {
        //     return 0;
        // }
        // int count = 0;
        // for (int i = 2; i < n; i++) {
        //     bool flag = true;
        //     for (int j = 2; j * j <= i; j++) {
        //         if (i % j == 0) {
        //             flag = false;
        //             continue;
        //         }
        //     }
        //     if (flag) {
        //         count++;
        //     }
        // }
        // return count;
    }
};
