#include "utils.h"
//超出时间限制, 这个相当于遍历了所有的路程, 没有做pruning
class Solution1 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()<1) return 0;
        if(triangle[0].size()<1) return 0;
        return minimumTotal(triangle, 0, 0);
    }
    int minimumTotal(vector<vector<int>>& triangle, int startRow, int startCol){
        if(startRow==triangle.size()-1) return triangle[startRow][startCol];
        int minChild = min(minimumTotal(triangle, startRow+1, startCol), minimumTotal(triangle, startRow+1, startCol+1));
        return minChild + triangle[startRow][startCol];
    }
};

//Dynamic programming 
//Tabulation
class Solution2 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()<1) return 0;
        if(triangle[0].size()<1) return 0;
        vector<int> table = triangle[triangle.size()-1];
        for(int row=triangle.size()-2; row>=0; --row){
            for(int col=0;col<=row;++col)
                table[col] = triangle[row][col]+min(table[col], table[col+1]);
        }
        return table[0];
    }
    
};