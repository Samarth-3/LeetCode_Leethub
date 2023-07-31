class Solution {
public:
    vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                // If the current digit is not 9, simply increment and return
                digits[i]++;
                return digits;
            } else {
                // If the current digit is 9, set it to 0 and propagate the carry
                digits[i] = 0;
            }
        }

        // If the loop completes, it means all digits were 9, so we need to add a new digit 1 at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};