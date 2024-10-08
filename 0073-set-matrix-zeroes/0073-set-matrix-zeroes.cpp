class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> v(col, 0);
        vector<vector<int>> x(row, v);

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (matrix[i][j] == 0) {
                    x[i][j] = 1;
                }

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                if (x[i][j] == 1) {
                    for (int a = 0; a < row; a++) {
                        matrix[a][j] = 0;
                    }
                    for (int b = 0; b < col; b++) {
                        matrix[i][b] = 0;
                    }
                }
            }
    }
};