class Solution {
public:
    bool isSafe(int r, int c, int m, int n)
    {
        return (r < m && r >= 0 && c < n && c >= 0);
    }
    void dfs(int r, int c, vector<vector<int>>& image, int orignal_color, int color, int m, int n)
    {
        image[r][c] = color;
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        for(int k = 0; k < 4; k++)
        {
            int newr = r + dir[k][0];
            int newc = c + dir[k][1];

            if(isSafe(newr, newc, m, n) && image[newr][newc] == orignal_color)
            {
                dfs(newr,newc,image,orignal_color,color,m,n);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orig_color = image[sr][sc];
        if(orig_color == color) return image;

        int m = image.size();
        int n = image[0].size();

        dfs(sr,sc,image,orig_color,color,m,n);

        return image;
    }
};