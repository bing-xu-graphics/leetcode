#include "utils.h"
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m<1) return 0;
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]==1) return 0;
        vector<long long> records(n,0);   //中见有溢出的可能 改成了long long
        records[0] = 1 - obstacleGrid[0][0];
        for(int i=1;i<n;i++){
            if(obstacleGrid[0][i]==1) break;
            else records[i] = 1;
        }
        for(int i=1;i<m;i++){
            records[0] = records[0]==1? 1 - obstacleGrid[i][0]:0;
            for(int j=1;j<n; j++){
                records[j] = obstacleGrid[i][j]==1? 0: (records[j-1] + records[j]);
            }
        }
        return records[n-1];
    }
};