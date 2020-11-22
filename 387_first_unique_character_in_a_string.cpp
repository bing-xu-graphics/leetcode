#include "utils.h"
/**
 * Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
 

Note: You may assume the string contains only lowercase English letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-unique-character-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, bool> meet;
        for(int i=0;i<s.size();++i){
            if(meet.find(s[i])==meet.end()){
                meet[s[i]] = true;
            }else if(meet[s[i]]==true) meet[s[i]] = false;
        }
        for(int i=0; i<s.size();++i){
            if(meet[s[i]]) return i;
        }
        return -1;
    }
};