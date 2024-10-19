
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>,greater<int>> heap;
        
        // Add first k elements to the heap
        for (int i = 0; i < k; i++) {
            heap.push(nums[i]);
        }
        
        // Process the rest of the array
        for (int i = k; i < nums.size(); i++) {
            if (heap.top() < nums[i]) {
                heap.pop();  // Remove the smallest element
                heap.push(nums[i]);  // Add the current element
            }
        }
        
        return heap.top();  // The kth largest element
    }
};