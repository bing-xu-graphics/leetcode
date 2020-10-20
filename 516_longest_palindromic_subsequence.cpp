#include "utils.h"
/**
 * Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
 

Example 2:
Input:

"cbbd"
Output:
2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//这道题目和之前的区别就是, 这个是subsequence ,而不是substring, 
//之前substring 的化, dp[i][j] 的代表含义是一样的, 但是状态转移方程就不一样, 
//substring 的化 如果d[i+1][j-1] 如果不是回文的化, 外面也不可能是, 但是subsequence 就放宽了,  
//如果s[i]!=s[j] 注意这这里面收缩的  选一个最大值.  注意这个普遍的方法. 
//最开始没有想出来, 还是因为没有想好dp 到底定义什么. 
//注意这里的填表顺序, 从下往上, 从左到右, 比我之前的填表方法简单一些
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i=0;i<s.size();++i){
            dp[i][i] = 1;
        }
        for(int i=s.size()-1;i>=0;--i){
            for(int j=i+1; j<s.size();++j){
                if(s[i]==s[j]) dp[i][j] = d[i+1][j-1]+2;
                else{
                    dp[i][j] = max(d[i+1][j], d[i][j-1]);
                }
            }

        }
        return dp[0][s.size()-1];


    }
};