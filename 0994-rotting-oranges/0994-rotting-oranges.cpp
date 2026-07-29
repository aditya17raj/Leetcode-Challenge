class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();

        queue<pair<int, pair<int,int>>> q;
        vector<vector<bool>> visited(r,vector<bool> (c , false));
        int freshCount=0;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 2){
                    q.push({0 , {i,j}});
                    visited[i][j] = true;
                }
                else if(grid[i][j] == 1){
                    freshCount ++;
                }
            }
        } 

        int maxTime=0;
        int cnt=0;

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            int t=top.first;
            int i=top.second.first;
            int j=top.second.second;

            maxTime = max(maxTime , t);

            vector<int> drow = {0,-1,0,1};
            vector<int> dcol = {-1,0,1,0};

            for(int k=0; k<4; k++){
                int row = drow[k]+i;
                int col = dcol[k]+j;

                if( (row>=0 && row<r) && (col>=0 && col<c) && (!visited[row][col]) && (grid[row][col] == 1) ){
                    q.push({t+1, {row,col}});
                    visited[row][col] = true;
                    cnt++;
                }
            }
        }

        return freshCount != cnt ? -1 : maxTime;
    }
};