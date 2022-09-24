class Solution {
public:
    void dfs(int row, int col, vector<vector<char>> &board, vector<vector<int>> &vis, int delRow[], int delCol[]){
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        
        for(int i = 0; i < 4; i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            
            if(newRow >= 0 and newRow < n and newCol >= 0 and newCol < m and board[newRow][newCol] == 'O' and vis[newRow][newCol] == 0){
                dfs(newRow, newCol, board, vis, delRow, delCol);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        for(int j = 0; j < m; j++){
            if(vis[0][j] == 0 and board[0][j] == 'O'){
                dfs(0, j, board, vis, delRow, delCol);
            }
            
            if(vis[n-1][j] == 0 and board[n-1][j] == 'O'){
                dfs(n-1, j, board, vis, delRow, delCol);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(vis[i][0] == 0 and board[i][0] == 'O'){
                dfs(i, 0, board, vis, delRow, delCol);
            }
            
            if(vis[i][m-1] == 0 and board[i][m-1] == 'O'){
                dfs(i, m-1, board, vis, delRow, delCol);
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 0 and board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};