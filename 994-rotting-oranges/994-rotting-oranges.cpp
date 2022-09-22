class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        int freshOranges = 0;
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j},0});
                    vis[i][j] = 2;
                }else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int minTime = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            minTime = max(minTime, time);
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                
                if(newRow >=0 and newRow < n and newCol >= 0 and newCol < m and grid[newRow][newCol] == 1 and vis[newRow][newCol] == 0){
                    q.push({{newRow, newCol}, time + 1});
                    vis[newRow][newCol] = 2;
                    freshOranges--;
                }
            }
        }
        
        if(freshOranges != 0){
            return -1;
        }
        return minTime;
    }
};