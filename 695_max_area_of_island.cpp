#include "utils.h"
/**
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-area-of-island
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m<1) return 0;
        int n = grid[0].size();
        int max_area = 0;
        for(int row=0; row<m;++row){
            for(int col=0; col<n;++col){
                int area = dfs(grid, m, n, row, col);
                if(area>max_area) max_area = area;
            }
        }
        return max_area;

    }
    int dfs(vector<vector<int>>& grid, int m, int n, int row, int col){
        if(row<0 || row>=m ||col<0 || col>=n|| grid[row][col]==0 ||grid[row][col]==2) return 0;
        grid[row][col] = 2;
        return 1 
        + dfs(grid, m, n, row, col-1) 
        + dfs(grid, m, n, row, col+1)
        + dfs(grid, m, n, row+1, col)
        + dfs(grid, m, n, row-1, col);


    }
};