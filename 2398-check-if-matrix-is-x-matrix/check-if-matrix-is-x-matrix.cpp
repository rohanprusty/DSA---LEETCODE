class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        for(int row = 0; row < grid.size(); ++row)
        {
            for(int col = 0; col < grid[row].size(); ++col)
            {
                if(row == col || row+col == grid.size()-1)
                {
                    if(grid[row][col] == 0)
                        return false;
                }
                else if(grid[row][col] != 0)
                    return false;
            }
        }
        return true;
    }
};