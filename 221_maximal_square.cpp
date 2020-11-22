/**
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m<1) return 0;
        int n = matrix[0].size();

        vector<vector<int>> up(m, vector<int>(n, 0)); //including the one
        vector<vector<int>> down(m, vector<int>(n, 0));
        vector<vector<int>> left(m, vector<int>(n, 0));
        vector<vector<int>> right(m, vector<int>(n, 0));
        

        for(int row=0; row<m; ++row){
            for(int col=0; col<n; ++col){
                if(row==0){
                    up[row][col] = (matrix[row][col]=='1')? 1:0;
                    continue;
                }
                if(matrix[row][col]=='1') up[row][col] = up[row-1][col]+1;
                else up[row][col] = 0;
            }
        }
        

        for(int row=m-1; row>=0; --row){
            for(int col=0; col<n; ++col){
                if(row==m-1){
                    down[row][col] = (matrix[row][col]=='1')? 1:0;
                    continue;
                }
                if(matrix[row][col]=='1') down[row][col] = down[row+1][col]+1;
                else down[row][col] = 0;
            }
        }
        
        for(int row=0; row<m; ++row){
            for(int col=0; col<n; ++col){
                if(col==0){
                    left[row][col] = (matrix[row][col]=='1')? 1:0;
                    continue;
                }
                if(matrix[row][col]=='1') left[row][col] = left[row][col-1]+1;
                else left[row][col] = 0;
            }
        }
        
        for(int row=0; row<m; ++row){
            for(int col=n-1; col>=0; --col){
                if(col==n-1){
                    right[row][col] = (matrix[row][col]=='1')? 1:0;
                    continue;
                }
                if(matrix[row][col]=='1') right[row][col] = right[row][col+1]+1;
                else right[row][col] = 0;
            }
        }
        // printf("haha");

        int maxSum = 0;
        for(int i=0;i<m;++i){
            for(int j=0; j<n;++j){
                int k = min(down[i][j], right[i][j]);
                for(int len=0;len<k;++len){
                    if(up[i+len][j+len]>=len && left[i+len][j+len]>=len){
                        maxSum = max(maxSum, (len+1)*(len+1));
                    }else break;
                }
            }
        }
        return maxSum;

    }
};


//method2  稍微剪枝了一下, 快了10ms
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m<1) return 0;
        int n = matrix[0].size();

        vector<vector<int>> up(m, vector<int>(n, 0)); //including the one
        vector<vector<int>> down(m, vector<int>(n, 0));
        vector<vector<int>> left(m, vector<int>(n, 0));
        vector<vector<int>> right(m, vector<int>(n, 0));
        

        for(int row=0; row<m; ++row){
            for(int col=0; col<n; ++col){
                if(row==0){
                    up[row][col] = (matrix[row][col]=='1')? 1:0;
                    continue;
                }
                if(matrix[row][col]=='1') up[row][col] = up[row-1][col]+1;
                else up[row][col] = 0;
            }
        }
        

        for(int row=m-1; row>=0; --row){
            for(int col=0; col<n; ++col){
                if(row==m-1){
                    down[row][col] = (matrix[row][col]=='1')? 1:0;
                    continue;
                }
                if(matrix[row][col]=='1') down[row][col] = down[row+1][col]+1;
                else down[row][col] = 0;
            }
        }
        
        for(int row=0; row<m; ++row){
            for(int col=0; col<n; ++col){
                if(col==0){
                    left[row][col] = (matrix[row][col]=='1')? 1:0;
                    continue;
                }
                if(matrix[row][col]=='1') left[row][col] = left[row][col-1]+1;
                else left[row][col] = 0;
            }
        }
        
        for(int row=0; row<m; ++row){
            for(int col=n-1; col>=0; --col){
                if(col==n-1){
                    right[row][col] = (matrix[row][col]=='1')? 1:0;
                    continue;
                }
                if(matrix[row][col]=='1') right[row][col] = right[row][col+1]+1;
                else right[row][col] = 0;
            }
        }
        // printf("haha");

        int maxSum = 0;
        int maxLen = -1;
        for(int i=0;i<m;++i){
            for(int j=0; j<n;++j){
                int k = min(down[i][j], right[i][j]);
                if(k<maxLen+1) continue;
                for(int len=0;len<k;++len){
                    if(up[i+len][j+len]>=len && left[i+len][j+len]>=len){
                        if(len>maxLen){
                            maxLen = len;
                            maxSum = (len+1)*(len+1);
                        }
                    }else break;
                }
            }
        }
        return maxSum;

    }
};

///method3
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m<1) return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxSum = 0;
        // dp[0][0] = matrix[0][0]=='1'? 1:0;
        for(int col=0; col<n;++col){
            dp[0][col] = matrix[0][col]=='1' ?  1: 0;
            maxSum = max(maxSum, dp[0][col]);
        }
        for(int row=0; row<m;++row){
            dp[row][0] = matrix[row][0]=='1'? 1:0;
            maxSum = max(maxSum, dp[row][0]);
        }
        for(int i=1;i<m;++i){
            for(int j=1; j<n;++j){
                if(matrix[i][j]=='0') dp[i][j] = 0;
                else{
                    dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1;
                    maxSum = max(maxSum, dp[i][j]*dp[i][j]);
                }
            }
        }

        return maxSum;
    }
};