class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;

        // Up, Right, Down, Left
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {

                int neighRow = row + delRow[k];
                int neighCol = col + delCol[k];

                if (neighRow >= 0 && neighRow < n &&
                    neighCol >= 0 && neighCol < m &&
                    !visited[neighRow][neighCol] &&
                    grid[neighRow][neighCol] == '1') {

                    visited[neighRow][neighCol] = true;
                    q.push({neighRow, neighCol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(
            n, vector<bool>(m, false)
        );

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (!visited[i][j] && grid[i][j] == '1') {

                    bfs(i, j, grid, visited);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};