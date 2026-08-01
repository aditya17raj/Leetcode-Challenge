class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> dis(n, vector<int>(m,0));
        vector<vector<bool>> visited(n, vector<bool> (m,false));

        queue<pair<pair<int,int>, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({ {i,j}, 0 });
                    visited[i][j]=true;
                }else{
                    visited[i][j]=false;
                }
            }
        }

        vector<int> delrow = {0,1,0,-1};
        vector<int> delcol = {-1,0,1,0};

        while(!q.empty()){
            auto front=q.front();
            q.pop();

            int r=front.first.first;
            int c=front.first.second;
            int s=front.second;

            dis[r][c] = s;

            for(int i=0; i<4; i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];

                if( (nrow>=0 && nrow<n) && (ncol>=0 && ncol<m) && !visited[nrow][ncol]){
                    q.push({{nrow,ncol} , s+1 });
                    visited[nrow][ncol] = true;
                }
            }
        }

        return dis;
    }
};