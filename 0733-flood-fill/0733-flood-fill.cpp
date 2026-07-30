class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>>& image, vector<vector<int>> &ans, 
            int inicolor, int color, vector<int> delrow, vector<int> delcol)
    {
        ans[sr][sc] = color;
        int n=image.size();
        int m=image[0].size();

        for(int i=0; i<4; i++){
            int nrow = sr+delrow[i];
            int ncol = sc+delcol[i];

            if( (nrow >= 0 && nrow<n) && (ncol>=0 && ncol<m) && image[nrow][ncol] == inicolor &&
                ans[nrow][ncol] != color )
            {
                dfs(nrow, ncol, image, ans, inicolor, color, delrow, delcol);
            }

        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        
        vector<int> delrow = {0,-1,0,1};
        vector<int> delcol = {-1,0,1,0};

        dfs(sr, sc, image, ans, iniColor, color, delrow, delcol);

        return ans;
    }
};