#include "utils.h"
/**
 * Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

 

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/repeated-substring-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//method1 非常简单直接的方法
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i=1; i<=n/2;++i){
            if(n%i!=0) continue;
            bool res = true;
            for(int j=1;j<n/i;++j){
                if(s.substr(j*i, i)!=s.substr((j-1)*i, i)){
                    res = false;
                    break;
                }
            }
            if(res) return true;
        }
        return false;
    }
    
};

//method2  把循环的顺序换了一下, 快了一点, 这个时间复杂度是O(N^2)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        // for(int i=1; i<=n/2;++i){
        for(int i=n/2; i>=1;--i){    
            if(n%i!=0) continue;
            bool res = true;
            for(int j=1;j<n/i;++j){
                if(s.substr(j*i, i)!=s.substr((j-1)*i, i)){
                    res = false;
                    break;
                }
            }
            if(res) return true;
        }
        return false;
    }
    
};


//method3  一个性质
/** 假设s由几段相同的ss 组成, 那么把(ss)+ 移到末尾的时候, 其实还是s, 
 * 这样的化可以构造 一个 s+s  同时把第一个和最后一个字符去掉, 再看s是否是他的子串  这个是必要性证明, 
 * 充分性证明:
 * 这个时间复杂度是O(n)
 * 
 *
 */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s+s).find(s, 1)!=s.size();
    }
    
}; 