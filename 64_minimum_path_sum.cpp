#include "utils.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m<1) return 0;
        int n = grid[0].size();
        vector<int> sum(n, 0);
        for(int j=0;j<n;j++) sum[j] = j==0? grid[0][0]:sum[j-1]+grid[0][j];
        for(int i=1;i<m;i++){
            for(int j=0; j<n;j++) 
                sum[j] = (j==0)? sum[0]+grid[i][j]: min(sum[j-1],sum[j])+grid[i][j];
        }
        return sum[n-1];
    }
};