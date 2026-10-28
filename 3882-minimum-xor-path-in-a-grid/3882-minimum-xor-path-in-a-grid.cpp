
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> molqaviren = grid;

        const int MAXX = 1024;
        vector<vector<bitset<MAXX>>> dp(
            m, vector<bitset<MAXX>>(n)
        );

        dp[0][0].set(molqaviren[0][0]);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                int val = molqaviren[i][j];

                if (i > 0) {
                    for (int x = 0; x < MAXX; x++) {
                        if (dp[i - 1][j][x]) {
                            dp[i][j].set(x ^ val);
                        }
                    }
                }

                if (j > 0) {
                    for (int x = 0; x < MAXX; x++) {
                        if (dp[i][j - 1][x]) {
                            dp[i][j].set(x ^ val);
                        }
                    }
                }
            }
        }

        for (int x = 0; x < MAXX; x++) {
            if (dp[m - 1][n - 1][x]) {
                return x;
            }
        }

        return 0;
    }
};
