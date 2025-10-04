class Solution{
public:
    vector<vector<int>> res;

    vector<vector<int>> nQueen(int n) {
        vector<int> board(n, 0); // board[i] stores row of queen in i-th column
        solve(0, board, n);
        return res;
    }

    void solve(int col, vector<int> &board, int n) {
        if (col == n) {
            vector<int> config;
            for (int i = 0; i < n; i++) {
                config.push_back(board[i] + 1); // 1-based index
            }
            res.push_back(config);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(col, row, board)) {
                board[col] = row;
                solve(col + 1, board, n);
            }
        }
    }

    bool isSafe(int col, int row, vector<int> &board) {
        for (int i = 0; i < col; i++) {
            int prow = board[i];
            if (prow == row || abs(prow - row) == abs(i - col)) {
                return false;
            }
        }
        return true;
    }
};
