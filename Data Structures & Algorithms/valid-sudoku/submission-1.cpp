class Solution {
   public:
    bool checkBoard(vector<int> board) {
        // must include 1-9
        // no duplicates
        int freq[10] = {0};
        int n = board.size();
        bool valid = 1;
        for (int x = 0; x < n; x++) {
            int curr = board[x];
            int& p = freq[curr];
            p++;
            if (p > 1 && curr != 0) {
                valid = 0;
                break;
            }
        }

        return (valid);
    }

    bool checkRowsCols(vector<vector<int>> board) {
        // must contain 1-9
        // cannot contain duplicates
        int n = board.size();
        // check rows
        bool validAll = 1;
        for (int x = 0; x < n; x++) {
            bool valid = 1;
            int freq[10] = {0};
            for (int y = 0; y < n; y++) {
                int curr = board[x][y];
                int& p = freq[curr];
                p++;
                if (p > 1 && curr != 0) {
                    valid = 0;
                    break;
                }
            }

            if (!valid) {
                validAll = 0;
                break;
            }
        }

        bool res = validAll;
        if (!res) {
            return res;
        }

        // check cols
        validAll = 1;
        for (int x = 0; x < n; x++) {
            bool valid = 1;
            int freq[10] = {0};
            for (int y = 0; y < n; y++) {
                int curr = board[y][x];
                int& p = freq[curr];
                p++;
                if (p > 1 && curr != 0) {
                    valid = 0;
                    break;
                }
            }

            if (!valid) {
                validAll = 0;
                break;
            }
        }

        res = validAll;
        return res;
    }

    bool checkSudoku(vector<vector<int>> board) {
        int n = board.size();
        bool valid3x3 = 1;
        for (int x = 0; x < n; x += 3) {
            for (int y = 0; y < n; y += 3) {
                vector<int> b3x3;
                b3x3.reserve(9);
                for (int a = x; a < x + 3; a++) {
                    for (int b = y; b < y + 3; b++) {
                        b3x3.emplace_back(board[a][b]);
                    }
                }

                bool val = checkBoard(b3x3);
                if (!val) {
                    valid3x3 = 0;
                    break;
                }
            }
        }

        bool crc = checkRowsCols(board);
        return (valid3x3 && crc);
    }

    vector<vector<int>> convert(vector<vector<char>> board) {
        int n = board.size();
        vector<vector<int>> res(n, vector<int>(n));
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                int a = 0;
                int c = board[x][y];
                if (c != '.') {
                    a = c - '0';
                }

                res[x][y] = a;
            }
        }

        return res;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> boardInt = convert(board);
        int n = board.size();
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                cout << boardInt[x][y] << " ";
            }

            cout << "\n";
        }

        return checkSudoku(boardInt);
    }
};
