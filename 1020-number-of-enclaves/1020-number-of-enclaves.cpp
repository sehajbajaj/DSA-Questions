class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>>q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 or i == n-1 or j == 0 or j == m-1){
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        vis[i][j] = 1;
                    }else{
                        vis[i][j] = 0;
                    } 
                }
            }
        }
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int cntOnes= 0;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                
                if(newRow >= 0 and newRow < n and newCol >= 0 and newCol < m and grid[newRow][newCol] == 1 and vis[newRow][newCol] == 0){
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = 1;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 and vis[i][j] == 0){
                    cntOnes++;
                }
            }
        }
        return cntOnes;
    }
};