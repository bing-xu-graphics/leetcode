#include "utils.h"
/**
 * Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Note:

The input string length won't exceed 1000.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindromic-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//一定要注意填入dp table 的顺序,   其实这里只用了一半的内存.
//另外, dp[i][j] 代表以i开始, j结尾的是否是回文
class Solution {
public:
    int countSubstrings(string s) {
        if(s.size()<2) return 1;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        //starts with i , ends with j
        for(int i=0;i<s.size();++i){
            dp[i][i] = 1;
        }
        
        for(int i=0;i<s.size()-1;++i){
            if(s[i]==s[i+1]) dp[i][i+1] = 1;
        }

        // for(int i=0;i<s.size();++i){
        //     for(int j=i+2;j<s.size();++j){
        //         if(dp[i+1][j-1]==1 && s[i]==s[j]) dp[i][j] = 1;
        //     }
        // }
        
        for(int right = 2;right<s.size();++right){
            int k=0;
            while(right+k<s.size()){
                if(dp[k+1][right+k-1]==1 && s[k]==s[right+k]) dp[k][right+k] = 1;
                k++;
            }
        }
        
        int cnt=0;
        for(int i=0; i<s.size();++i){
            for(int j=i;j<s.size();++j){
                // printf("(%d, %d)= %d\n", i, j, dp[i][j]);
                cnt+=dp[i][j];
            }
        }
        return cnt;
    }
};