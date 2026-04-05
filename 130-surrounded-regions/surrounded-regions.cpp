class Solution {
public:

    bool isSafe(int r, int c, int m, int n)
    {
        return (r >= 0 && r < m && c >= 0 && c < n);
    }

    void floodFill(int r, int c, int m, int n, vector<vector<char>>& board)
    {
        board[r][c] = 'V';
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        for(int k = 0; k < 4; k++)
        {
            int newr = r + dir[k][0];
            int newc = c + dir[k][1];

            if(isSafe(newr, newc, m,n) && board[newr][newc] == 'O')
            {
                floodFill(newr,newc,m,n,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O') floodFill(i,0,m,n,board);
            if(board[i][n-1] == 'O') floodFill(i,n-1,m,n,board);
        }
        for(int j = 0; j < n; j++)
        {
            if(board[0][j] == 'O') floodFill(0,j,m,n,board);
            if(board[m-1][j] == 'O') floodFill(m-1,j,m,n,board);
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'V')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};