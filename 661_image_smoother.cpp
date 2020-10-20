#include "utils.h"
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m =  M.size();
        if(m<1) return M;
        int n = M[0].size();
        for(int i=0; i<m;++i){
            for(int j=0; j<n;++j){
                int average = getAverage(M, i, j, m, n);
                M[i][j] += average<<8;
            }
        }
        for(int i=0; i<m;++i){
            for(int j=0; j<n;++j){
                M[i][j] = M[i][j]>>8;
            }
        }
        return M;

    }

    int getAverage(vector<vector<int>>& M, int row, int col, int m, int n){
        int sum = 0, dividor = 0;
        for(int i=-1;i<=1;++i){
            for(int j=-1;j<=1;++j){
                if(row+i>=0 && row+i<m && col+j>=0 && col+j<n){
                    sum += M[row+i][col+j] & 255;
                    dividor++;
                }
            }
        }
        return sum/dividor;
    }
};