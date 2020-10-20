#include "utils.h"
//method1  这两个都一样, 基本是暴力的解法, 除了一个小小的剪枝外, 没有任何优化, O(n^3) 复杂度太高了. 
//考虑一下进行了哪些重复计算
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int max_length = 0;
        for(int start=0; start<A.size(); ++start){
            for(int i=0; i<B.size();++i){
                int length = 0;
                // printf("start=%d, i=%d\n", start, i);
                int tmp_start = start, tmp_i = i;
                while(tmp_start<A.size() && tmp_i<B.size() && A[tmp_start]==B[tmp_i]){
                    length++;
                    tmp_start++;
                    tmp_i++;
                }
                max_length = max(max_length, length); 
                if(length>=(A.size()-start-1)) return max_length;
                // start = tmp_start;
            }
        }
        return max_length;
    }
};

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int max_length = 0;
        for(int start=0; start<A.size(); ++start){
            for(int i=0; i<B.size();++i){
                int k =0;
                while(start+k<A.size() && i+k<B.size() && A[start+k]==B[i+k])k++;
                max_length = max(max_length, k); 
                if(k>=(A.size()-start-1)) return max_length;
                // start = tmp_start;
            }
        }
        return max_length;
    }
};

//method 2 DP, dp[i][j] 表示 以(i, j) 为起点的最长连续子数组.  
/**
 * 这里可以学习的点
 * 1.  多做一个维度, 在index 有可能超出的时候, 这样比额外设置其实的行/列要代码简洁一些.
 * 2. 可以做空间压缩. 缩短为2行
 * 3.  这个题目相当于, 最后构造出来之后, 才能求得所有的最大值, 当然在过程中就可以维护一个流动的max/min
 */
 class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));
        int max_length = 0;
        for(int i=A.size()-1;i>=0;--i){
            for(int j=B.size()-1; j>=0; --j){
                if(A[i]==B[j]) dp[i][j] = dp[i+1][j+1]+1;
                else dp[i][j] = 0;
                max_length = max(dp[i][j], max_length);
            }
        }
        return max_length;
    }

};