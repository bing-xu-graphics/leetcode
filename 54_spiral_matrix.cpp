#include "utils.h"
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m<1) return vector<int>{};
        int n = matrix[0].size();
        if(n<1) return vector<int>{};
        int row_min =0, col_min = 0,row_max = m-1, col_max = n-1, i=0,j=0;
        vector<std::tuple<int, int>> direction = {std::make_tuple(0,1), std::make_tuple(1,0), std::make_tuple(0,-1),std::make_tuple(-1,0)};
        int di = 0;
        vector<int> res;
        while(res.size()<m*n){
            if(i>=row_min && i<=row_max && j>=col_min && j<=col_max){
                res.push_back(matrix[i][j]);
                // printf("(%d,%d):%d ", i,j,matrix[i][j]);
                i+=std::get<0>(direction[di%4]);
                j+=std::get<1>(direction[di%4]);
                // printf("(%d,%d), (%d,%d,%d,%d) \n",i,j,row_min,row_max,col_min, col_max);
                continue;
            }
            else if(di%4==0){
                row_min++;
                j--;
                i++;
            } 
            else if(di%4==1){
                col_max--;
                i--;
                j--;
            } 
            else if(di%4==2){
                row_max--;
                j++;
                i--;
            } 
            else {//if(di%4==3
                col_min++;
                i++;
                j++;
            } 
            ++di;
        }
        return res;

    }
};