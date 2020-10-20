#include "utils.h"
/**
 * Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

You may assume that both strings contain only lowercase letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ransom-note
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, int> letters;
        for(int i=0; i<magazine.size();++i){
            if(letters.find(magazine[i])==letters.end()){
                letters[magazine[i]] = 1;
            }else letters[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.size();++i){
            if(letters.find(ransomNote[i])==letters.end()) return false;
            else{
                if(letters[ransomNote[i]]==0) return false;
                letters[ransomNote[i]]--;
            }
        }
        return true;
    }
};