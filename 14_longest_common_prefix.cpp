#include "utils.h"
/**
 * Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<1) return "";
        int len = 0;
        bool same = true;
        while(len<strs[0].size()){
            for(int i=1; i<strs.size();++i){
                if(strs[i].size()<len+1 || strs[i][len]!=strs[0][len]){
                    return strs[0].substr(0,len);
                }
            }
            len++;
        }
        return strs[0].substr(0,len);
    }
};