class Solution {
public:
    int n;
    pair<int,int> getcoordinates(int num)
    {
        int RT = (num-1)/n;
        int row = (n-1) - RT;
        int col = (num-1) % n;
        if((n%2 == 0 && row %2 == 0) || (n%2 == 1 && row%2 == 1))
        {
            col = (n-1)-col;
        }
        return make_pair(row,col);
    }
    int snakesAndLadders(vector<vector<int>>& board) {
         n = board.size();
        int steps = 0;
        queue<int>q;

        vector<vector<bool>> visited(n, vector<bool>(n,false));
        visited[n-1][0] = true;
        q.push(1);
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int x = q.front();
                q.pop();
                if(x ==n*n)
                {
                    return steps;
                }
                for(int k = 1; k <= 6; k++)
                {
                    int val = x+k;
                    if(val > n*n)
                    {
                        break;
                    }
                    pair<int,int> coordinates = getcoordinates(val);
                    int r = coordinates.first;
                    int c = coordinates.second;
                    if(visited[r][c] == true)
                    {
                        continue;
                    }
                    visited[r][c] = true;
                    if(board[r][c] == -1)
                    {
                        q.push(val);
                    }
                    else
                    {
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};