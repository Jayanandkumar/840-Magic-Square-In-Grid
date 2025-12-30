#include <vector>

using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int i = 0; i <= rows - 3; ++i) {
            for (int j = 0; j <= cols - 3; ++j) {
                if (isMagic(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }

private:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {
        if (grid[r + 1][c + 1] != 5) return false;

        int seen = 0;
        for (int i = r; i < r + 3; ++i) {
            for (int j = c; j < c + 3; ++j) {
                int val = grid[i][j];
                if (val < 1 || val > 9 || (seen & (1 << val))) return false;
                seen |= (1 << val);
            }
        }

        if (grid[r][c] + grid[r][c + 1] + grid[r][c + 2] != 15) return false;
        if (grid[r + 1][c] + grid[r + 1][c + 1] + grid[r + 1][c + 2] != 15) return false;
        if (grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2] != 15) return false;

        if (grid[r][c] + grid[r + 1][c] + grid[r + 2][c] != 15) return false;
        if (grid[r][c + 1] + grid[r + 1][c + 1] + grid[r + 2][c + 1] != 15) return false;
        if (grid[r][c + 2] + grid[r + 1][c + 2] + grid[r + 2][c + 2] != 15) return false;

        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != 15) return false;
        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != 15) return false;

        return true;
    }
};