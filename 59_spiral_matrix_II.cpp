#include "utils.h"
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n<1) return {};
        vector<vector<int>> res(n, vector<int>(n, 0));
        int row_min = 0, row_max = n-1, col_min=0,col_max=n-1, i=0,j=0;
        vector<std::tuple<int,int>> direction = {std::make_tuple(0,1),
        std::make_tuple(1,0),std::make_tuple(0,-1), std::make_tuple(-1,0)};
        int di = 0;
        int count = 0;
        while(count<n*n){
            if(i>=row_min && i<= row_max && j>=col_min && j<=col_max){
                res[i][j] = ++count;
                // printf("%d ",res[i][j]);
                i += std::get<0>(direction[di%4]);
                j += std::get<1>(direction[di%4]);
                continue;
            }else if(di%4==0){
                row_min++;
                j--;
                i++;
            }else if(di%4==1){
                col_max--;
                i--;
                j--;
            }else if(di%4==2){
                row_max--;
                j++;
                i--;
            }else{
                col_min++;
                i++;
                j++;
            }
            di++;
        }
        return res;

    }
};