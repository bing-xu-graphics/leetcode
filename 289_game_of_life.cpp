#include "utils.h"
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m<1) return;
        int n = board[0].size();
        if(n<1) return;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> res(m, vector<int>(n, 0));
        
        for(int row=0; row<m; ++row){
            for(int col=0; col<n;++col){
                liveNeighbors(board, row, col, m, n, visited, res);
                visited[row][col] = true;
            }
        }
        for(int row=0; row<m; ++row){
            for(int col=0; col<n;++col){
                if(res[row][col]>3 || res[row][col]<2) board[row][col] = 0;
                else if(res[row][col]==3) board[row][col] = 1;
            }                
        }
       
        
    }
    void liveNeighbors(vector<vector<int>>& board, int row, int col, int m, int n, vector<vector<bool>>& visited, vector<vector<int>>& res){
        int live = 0;
        for(int i=-1;i<=1;++i){
            for(int j=-1;j<=1;++j){
                if(row+i<0 || row+i>=m) continue;
                if(col+j<0||col+j>=n) continue;
                if(i==0 && j==0) continue;
                if(visited[row+i][col+j]) continue;
                if(board[row+i][col+j]==1) live ++;
                res[row+i][col+j]+= board[row][col];
            }
        }
        res[row][col] += live;

    }
};

//SOlution2 how to do it in-place?
//use bits to store the data/information

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m<1) return;
        int n = board[0].size();
        if(n<1) return;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // vector<vector<int>> res(m, vector<int>(n, 0));
        
        for(int row=0; row<m; ++row){
            for(int col=0; col<n;++col){
                liveNeighbors(board, row, col, m, n, visited);
                visited[row][col] = true;
            }
        }
        for(int row=0; row<m; ++row){
            // printf("[");
            for(int col=0; col<n;++col){
                // printf("%d, ", res[row][col]);
                int neighbor = board[row][col]>>1;
                // printf("%d, ", neighbor);
                if(neighbor>3 || neighbor<2) board[row][col] = 0;
                else if(neighbor==3) board[row][col] = 1;
                else board[row][col] = board[row][col]&1;
            }         
            // printf("]");       
        }
       
        
    }
    void liveNeighbors(vector<vector<int>>& board, int row, int col, int m, int n, vector<vector<bool>>& visited){
        int live = 0;
        for(int i=-1;i<=1;++i){
            for(int j=-1;j<=1;++j){
                if(row+i<0 || row+i>=m) continue;
                if(col+j<0||col+j>=n) continue;
                if(i==0 && j==0) continue;
                if(visited[row+i][col+j]) continue;
                if(board[row+i][col+j]&1==1) live ++;
                board[row+i][col+j]+= ((board[row][col]&1)<<1);
            }
        }
        board[row][col] += (live<<1);

    }
};

