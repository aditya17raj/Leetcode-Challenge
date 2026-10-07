class Solution {
private:
    vector<int> delRow = {0,-1,0,1};
    vector<int> delCol = {1,0,-1,0};
public:
    bool valid(int r, int c, int n, int m){
        if(r>=0 && r<n && c>=0 && c<m)
            return true;
        else
            return false;
    }

    void dfs(int row, int col, int color, int iniClr, vector<vector<int>>&image, vector<vector<int>>&ans, int n, int m){

        ans[row][col] = color;
        
        for(int i=0; i<4; i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];

            if(valid(nrow,ncol,n,m) && image[nrow][ncol]==iniClr && ans[nrow][ncol]!=color){
                dfs(nrow,ncol,color,iniClr,image,ans,n,m);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
        int iniClr = image[sr][sc];
        int n=image.size();
        int m=image[0].size();

        vector<vector<int>> ans = image;

        dfs(sr, sc, color, iniClr, image, ans, n, m);

        return ans;
    }
};