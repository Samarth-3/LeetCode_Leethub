// class Solution {
// public:
//     long long fun(int n,int i,vector<vector<int>>& triangle,vector<vector<long long>> &dp){
//         if(n==0){
//             return triangle[0][0];
//         }
//         if (i < 0 || i >= triangle[n].size()) {
//             return LLONG_MAX;
//         }
//         if(dp[n][i]!=-1){
//             return dp[n][i];
//         }
//         long long samei=triangle[n][i]+fun(n-1,i,triangle,dp);
//         long long plusi = (i > 0) ? triangle[n][i] + fun(n - 1, i - 1, triangle, dp) : LLONG_MAX;
//         return min(samei,plusi);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n=triangle.size();
//         long long minans=LLONG_MAX;
//         vector<vector<long long>> dp(n,vector<long long>(n,-1));
//         for(int i=0;i<n;i++){
//             long long a=fun(n-1,i,triangle,dp);
//             minans=min(minans,a);
//         }
//         return minans;
//     }
// };
// memoiztion code gave time limit exceed;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // DP array to store the minimum path sum for each position
        vector<long long> dp(n, 0);
        
        // Initialize the DP array with the values from the last row
        for (int i = 0; i < n; i++) {
            dp[i] = triangle[n-1][i];
        }

        // Bottom-up calculation: move upwards from the second-to-last row
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                // Update the dp array by taking the minimum path from the two possible lower steps
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
            }
        }

        // The top element will have the minimum path sum
        return dp[0];
    }
};
