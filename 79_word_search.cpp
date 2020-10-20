#include "utils.h"
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()<1) return false;
        int m = board.size();
        if(m<1) return false;
        int n = board[0].size();
        vector<vector<bool>> mark(m, vector<bool>(n, false));
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0;i<m; ++i){
            for(int j=0; j<n;++j){
                if(board[i][j]!=word[0]) continue;
                mark[i][j] = true;
                bool res = find_around(board, m, n, i, j, word, 1, directions, mark);
                if(res) return true;
                mark[i][j] = false;
            }
        }
        return false;
    }
private:    
    bool find_around(vector<vector<char>>& board, int& m, int&n, int i, int j, string word, int start, vector<vector<int>>& directions, vector<vector<bool>>& mark){
        if(start==word.size()) return true;
        for(int dii=0; dii<4; ++dii){
            vector<int> direction = directions[dii];
            if( (i+direction[0])>=0 && (i+direction[0])<m &&
            (j+direction[1])>=0 && (j+direction[1])<n && 
            !mark[i+direction[0]][j+direction[1]] &&
            board[i+direction[0]][j+direction[1]]==word[start]){
                mark[i+direction[0]][j+direction[1]] = true;
                bool res = find_around(board, m, n, i+direction[0], j+direction[1],word, start+1, directions, mark);
                if(res) return true;
                mark[i+direction[0]][j+direction[1]] = false;
            } 
        }
        return false;
    }
};