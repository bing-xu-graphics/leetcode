#include "utils.h"
/**
 * Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.

 

Example 1:

Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 9
Example 2:

Input: grid = [[1,1,0,0]]
Output: 1
 

Constraints:

1 <= grid.length <= 100
1 <= grid[0].length <= 100
grid[i][j] is 0 or 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-1-bordered-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//之前有一个失误: 是以为 sqaure 是长方形, 其实就是正方形.
//method 1 暴力解法 + 加一个简单的剪枝
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        if(grid.size()<1) return 0;
        int m = grid.size();
        if(grid[0].size()<1) return 0;
        int n = grid[0].size();
        int max_area = 0;
        int max_k = -1;
        for(int i=0;i<m;++i){
            for(int j=0; j<n;++j){
                for(int k=min(m-i, n-j)-1;k>=0;--k){ //而且这里是从大到小的
                    if(k<max_k) break; //只是在这里剪枝了一下
                    bool bordered = true;
                    //check if grid[i][j] - grid[i+k][j+k] are 1 bordered
                    for(int t=0;t<=k;t++){
                        if(grid[i][j+t]!=1){
                            bordered = false; break;
                        }
                        if(grid[i+k][j+t]!=1){
                            bordered = false; break;
                        }
                        if(grid[i+t][j]!=1){
                            bordered = false; break;
                        }
                        if(grid[i+t][j+k]!=1){
                            bordered = false; break;
                        }
                    }
                    if(bordered){
                        int area = (k+1)*(k+1);
                        if(max_area<area){
                            max_k = k;
                            max_area = area;
                        }
                        break;// 这里也剪枝了一下, 但是没有显著的效率提升
                    }
                    
                }
            }
        }
        return max_area;
    }
};

//method 动态规划保存了一些信息, 类似于前缀和??
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        if(grid.size()<1) return 0;
        int m = grid.size();
        if(grid[0].size()<1) return 0;
        int n = grid[0].size();
        int max_area = 0;
        int max_k = 0;
        vector<vector<int>> dp_left(m, vector<int>(n, 0)); //分别代表向四个方向延伸的最长距离(包括自己)
        vector<vector<int>> dp_right(m, vector<int>(n, 0));
        vector<vector<int>> dp_up(m, vector<int>(n, 0));
        vector<vector<int>> dp_down(m, vector<int>(n, 0));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1){
                    dp_left[i][j] = 1;
                    dp_right[i][j] = 1;
                    dp_up[i][j] = 1;
                    dp_down[i][j] = 1;
                }
            }
        }
        for(int i=0;i<m;++i){
            for(int j=1; j<n;++j){
                dp_left[i][j] = (grid[i][j]==1)? dp_left[i][j-1]+1:0;
            }
        }

        for(int i=0;i<m;++i){
            for(int j=n-2; j>=0;--j){
                dp_right[i][j] = (grid[i][j]==1)? dp_right[i][j+1]+1:0;
            }
        }
        for(int j=0;j<n;++j){
            for(int i=1;i<m;++i){
                dp_up[i][j] = (grid[i][j]==1)? dp_up[i-1][j]+1:0;
            }
        }
        for(int j=0;j<n;++j){
            for(int i=m-2;i>=0;--i){
                dp_down[i][j] = (grid[i][j]==1)? dp_down[i+1][j]+1:0;
            }
        }
        // printf("blabla");
        for(int i=0;i<m;++i){
            for(int j=0; j<n;++j){
                //top_left 
                int possible_k = min(dp_right[i][j], dp_down[i][j]);
                if(possible_k<max_k) continue;
                for(int k=possible_k-1;k>=0;--k){
                    if(dp_left[i+k][j+k]>=k &&dp_up[i+k][j+k]>=k){
                        int area = (k+1)*(k+1);
                        if(area>max_area){
                            max_k = k+1;
                            max_area = area;
                            break;
                        }
                    }
                }
            }
        }
        return max_area;
    }
};