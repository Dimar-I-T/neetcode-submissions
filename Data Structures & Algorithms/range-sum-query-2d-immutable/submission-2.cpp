class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        dp = matrix;
        int n = matrix.size(), m = matrix[0].size();
        for (int x = 0; x < m; x++) {
            for (int y = 1; y < n; y++) {
                dp[y][x] += dp[y - 1][x];
            }
        }

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                int left = 0, up = 0;
                if (y > 0) {
                    left = matrix[x][y - 1];
                }

                up = dp[x][y];
                matrix[x][y] = left + up;
            }
        }

        dp = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s = 0, b1 = 0, b2 = 0, b3 = 0;
        s = dp[row2][col2];
        if (row1 > 0) {
            b1 = dp[row1 - 1][col2];
        }

        if (col1 > 0) {
            b2 = dp[row2][col1 - 1];
        }

        if (row1 > 0 && col1 > 0) {
            b3 = dp[row1 - 1][col1 - 1];
        }

        cout << "s = " << s << "\n";
    cout << "b1 = " << b1 << "\n";
    cout << "b2 = " << b2 << "\n";
    cout << "b3 = " << b3 << "\n";

        return s - (b1 + b2 - b3);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */