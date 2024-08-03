class Solution {
public:
    int maxElementInRow(vector<vector<int>>& mat, int mid) {
        int maxi = 0, row_number = 0;
        for (int i = 0; i < mat.size(); i++) {
            if (maxi < mat[i][mid]) {
                maxi = mat[i][mid];
                row_number = i;
            }
        }
        return row_number;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int start = 0, end = mat[0].size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            int row = maxElementInRow(mat, mid);

            int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
            int right = mid + 1 < mat[0].size() ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            } else if (mat[row][mid] < left) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return {0, 0};
    }
};
