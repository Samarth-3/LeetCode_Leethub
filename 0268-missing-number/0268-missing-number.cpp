// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int size=nums.size();
//         for(int i=0;i<size;i++){
//             if(i==size-1 && nums[i]==i){
//                 return i+1;
//             }
//             if(i==nums[i] ) {continue;}
//             return i;
//         }
//         return -1;
//     }
// };

//better optimal solution
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expected_sum = n * (n + 1) / 2;
        int actual_sum = 0;

        for (int num : nums) {
            actual_sum += num;
        }

        return expected_sum - actual_sum;
    }
};
