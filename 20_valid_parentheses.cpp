#include "utils.h"
/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n%2!=0) return false;
        stack<char> st;
        for(int i=0; i<s.size();++i){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                st.push(s[i]);
            }else if(s[i]==']'){
                if(st.empty()||st.top()!='[') return false;
                st.pop();
            }else if(s[i]=='}'){
                if(st.empty()||st.top()!='{') return false;
                st.pop();
            }else if(s[i]==')'){
                if(st.empty()||st.top()!='(') return false;
                st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
    }

};