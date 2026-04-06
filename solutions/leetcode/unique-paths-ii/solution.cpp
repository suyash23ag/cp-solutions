// Problem  : Unique Paths II
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Matrix
// URL      : https://leetcode.com/problems/unique-paths-ii/
// Solved on: 2026-04-07 01:55
// ──────────────────────────────────────────────────

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If start or end is blocked
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        // First column
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0)
                dp[i][0] = dp[i - 1][0];
        }

        // First row
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 0)
                dp[0][j] = dp[0][j - 1];
        }

        // Fill rest of DP table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

