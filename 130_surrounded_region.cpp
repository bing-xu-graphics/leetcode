#include "utils.h"

/**
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if(rows<3) return;
        int cols = board[0].size();
        if(cols<3) return;
        //upper_bound
        for(int col=0;col<cols;++col){
            if(board[0][col]=='O') dfs(board, rows, cols, 0, col);
        }
        // printf("rows=%d, cols=%d\n", rows, cols);
        ////lower_bound
        for(int col=0;col<cols;++col){
            if(board[rows-1][col]=='O'){
                dfs(board, rows, cols, rows-1, col);
            } 
        }
        //left_bound
        for(int row=1;row<rows-1;++row){
            if(board[row][0]=='O') dfs(board, rows, cols, row, 0);
        }
        //right-bound
        for(int row=1; row<rows-1;++row){
            if(board[row][cols-1]=='O') dfs(board, rows, cols, row, cols-1);
        }

        for(int row=0; row<rows;++row){
            for(int col=0; col<cols; ++col){
                if(board[row][col]=='O') board[row][col] = 'X';
            }
        }
        for(int row=0; row<rows;++row){
            for(int col=0; col<cols; ++col){
                if(board[row][col]=='T') board[row][col] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int& rows, int& cols, int row, int col){
        if(row<0 || row>=rows || col<0 || col>= cols) return;
        if(board[row][col]=='T'||board[row][col]=='X') return;
        if(board[row][col]=='O') board[row][col] = 'T';
        dfs(board, rows, cols, row-1, col);
        dfs(board, rows, cols, row, col-1);
        dfs(board, rows, cols, row, col+1);
        dfs(board, rows, cols, row+1, col);
    }
};