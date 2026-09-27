class Solution {
public:
    int path(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp){
        if(i==0 && j==0)
            return grid[0][0];

        if(i<0 || j<0)
            return 1e9;

        if(dp[i][j] != -1)
            return dp[i][j];

        int up=grid[i][j] + path(grid, i-1, j, dp);
        int left=grid[i][j] + path(grid, i, j-1, dp);

        dp[i][j] = min(up, left);

        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m,-1));

        return path(grid, n-1, m-1, dp);
    }
};