class Solution {
public:
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis, int delRow[], int delCol[]){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < 4; i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            
            if(newRow >= 0 and newRow < n and newCol >= 0 and newCol < m and grid[newRow][newCol] == '1' and !vis[newRow][newCol]){
                vis[newRow][newCol] = 1;
                dfs(newRow, newCol, grid, vis, delRow, delCol);
            }
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 0 and grid[i][j] == '1'){
                    cnt++;
                    dfs(i, j, grid, vis, delRow, delCol);
                }
            }
        }
        return cnt;
    }
};