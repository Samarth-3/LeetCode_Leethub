class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int sRow = 0;
        int sCol = 0;
        int eRow = row - 1;
        int eCol = col - 1;

        int count = 0;
        int size = row * col;

        vector<int> arr;
        while (count < size) {
            for (int i = sCol; i <= eCol && count < size; i++) {
                arr.push_back(matrix[sRow][i]);
                count++;
            }
            sRow++;

            for (int i = sRow; i <= eRow && count < size; i++) {
                arr.push_back(matrix[i][eCol]);
                count++;
            }
            eCol--;

            for (int i = eCol; i >= sCol && count < size; i--) {
                arr.push_back(matrix[eRow][i]);
                count++;
            }
            eRow--;

            for (int i = eRow; i >= sRow && count < size; i--) {
                arr.push_back(matrix[i][sCol]);
                count++;
            }
            sCol++;
        }
        
        return arr;
    }
};
