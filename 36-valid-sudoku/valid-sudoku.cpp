class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> f(10, 0);
        for (int i = 0; i < 9; i++) {
            fill(f.begin(), f.end(), 0);
            for (int j = 0; j < 9; j++) {
                if (isdigit(board[i][j])) {
                    int num = board[i][j] - '0';
                    if (f[num] > 0) return false;
                    f[num]++;
                }
            }
        }
        for (int j = 0; j < 9; j++) {
            fill(f.begin(), f.end(), 0);
            for (int i = 0; i < 9; i++) {
                if (isdigit(board[i][j])) {
                    int num = board[i][j] - '0';
                    if (f[num] > 0) return false;
                    f[num]++;
                }
            }
        }
        int k=0,m=0;
        while (k < 9) {
            fill(f.begin(), f.end(), 0);
            for (int i = 0 + k; i < 3 + k; i++) {
                for (int j = 0 + m; j < 3 + m; j++) {
                    if (isdigit(board[i][j])) {
                        int num = board[i][j] - '0';
                        if (f[num] > 0) return false;
                        f[num]++;
                    }
                }
            }
            m=m+3;
            if (m == 9) {
                k = k + 3;
                m=0;
            }
        }
        return true;
    }
};