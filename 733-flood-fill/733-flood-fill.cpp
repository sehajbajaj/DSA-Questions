class Solution {
public:
    void dfs(vector<vector<int>> &image, vector<vector<int>> &copy, int row, int col, int color, int initialColor, int delRow[], int delCol[]){
        copy[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        
        for(int i = 0; i < 4; i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            
            if(newRow >= 0 and newRow < n and newCol >= 0 and newCol < m and image[newRow][newCol] == initialColor and copy[newRow][newCol] != color){
                dfs(image, copy, newRow, newCol, color, initialColor, delRow, delCol);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>> copy = image;
  
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        dfs(image, copy, sr, sc, color, initialColor, delRow, delCol);
        return copy;
    }
};