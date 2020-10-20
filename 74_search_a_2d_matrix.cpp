#include "utils.h"
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m<1) return false;
        int n = matrix[0].size();
        int low=0, high = m*n;
        while(low<high){
            int median = (low+high) >>1;
            int row = median/n;
            int col = median%n;
            if(matrix[row][col]== target) return true;
            else if(matrix[row][col]<target) low = median+1;
            else high = median;
        }
        return false;
    }
};