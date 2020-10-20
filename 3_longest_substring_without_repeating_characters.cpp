#include "utils.h"
/**
 * Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//method1 超时了
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<1) return 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),0));
        for(int i=0;i<s.size();++i){
            dp[i][i] = 1;
        }
        int max_length = 1;
        for(int i=0;i<s.size();++i){
            unordered_map<char, bool> repeats;
            repeats[s[i]] = true;
            for(int j=i+1;j<s.size();++j){
                // printf("%c\n", s[j]);
                if(!repeats[s[j]]){
                     dp[i][j] = dp[i][j-1]+1;
                     max_length = max(dp[i][j], max_length);
                     repeats[s[j]] = true;
                }
                else{
                    dp[i][j] = 0;
                    break;
                }
            }
        }

        return max_length;
    }
};


//method2 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<1) return 0;
        int left =0;
        unordered_map<char, int> position;
        position[s[0]] = 0;
        int len = 1;
        int max_length = 1;
        for(int right=1; right<s.size();++right){
            if(position.find(s[right])== position.end() || position[s[right]]<left){
                // printf("1   (%d, %d)\n", left, right);
                position[s[right]] = right;
                len++;
                max_length = max(max_length, len);
            }else {
                // printf("2   (%d, %d)\n", left, right);
                left = position[s[right]]+1;
                len = right - left+1;
                position[s[right]] = right;
            }
        }
        return max_length;
    }
};