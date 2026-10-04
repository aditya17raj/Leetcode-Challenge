class Solution {
public:
    bool valid(int r, int c, int n, int m){
        if(r>=0 && r<n && c>=0 && c<m)
            return true;
        else
            return false;
    }

    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>> &visited){
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            int row=front.first;
            int col=front.second;

            for(int i=0; i<4; i++){
                int nrow = row+delRow[i];
                int ncol = col+delCol[i];

                if(valid(nrow,ncol,n,m) && visited[nrow][ncol]==0 && grid[nrow][ncol] == '1'){
                    q.push({nrow,ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int cnt=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]==0 && grid[i][j] == '1'){
                    bfs(i, j, grid, visited);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};