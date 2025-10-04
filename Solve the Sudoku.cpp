class Solution {
public:
    void solveSudoku(vector<vector<int>>& grid) {
        bool row[9][10] = {false};
        bool col[9][10] = {false};
        bool box[9][10] = {false};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                int num = grid[i][j];
                if (num != 0) {
                    row[i][num] = true;
                    col[j][num] = true;
                    box[getBox(i, j)][num] = true;
                }
            }
        }

        solve(grid, 0, 0, row, col, box);
    }

private:
    bool solve(vector<vector<int>>& grid, int i, int j,
               bool row[9][10], bool col[9][10], bool box[9][10]) {
        if (i == 9) return true;
        if (j == 9) return solve(grid, i + 1, 0, row, col, box);
        if (grid[i][j] != 0) return solve(grid, i, j + 1, row, col, box);

        for (int num = 1; num <= 9; ++num) {
            int bIdx = getBox(i, j);
            if (!row[i][num] && !col[j][num] && !box[bIdx][num]) {
                grid[i][j] = num;
                row[i][num] = col[j][num] = box[bIdx][num] = true;

                if (solve(grid, i, j + 1, row, col, box)) return true;

                // Backtrack
                grid[i][j] = 0;
                row[i][num] = col[j][num] = box[bIdx][num] = false;
            }
        }

        return false;
    }

    int getBox(int i, int j) {
        return (i / 3) * 3 + (j / 3);
    }
};
