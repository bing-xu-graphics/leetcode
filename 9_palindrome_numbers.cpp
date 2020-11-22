#include "utils.h"
/**
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        vector<int> nums;
        while(x){
            nums.push_back(x%10);
            x/=10;
        }
        int n = nums.size();
        if(n%2==0){
            int k = 0;
            while(k<n/2){
                if(nums[n/2-1-k]!=nums[n/2+k++]) return false;
            }
        }else{
            int k=1;
            while(k<=(n-1)/2){
                if(nums[n/2-k]!=nums[n/2+k++]) return false;
            }
        }

        return true;
    }
};

//method2  只翻转一半, 防止溢出
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || x!=0 && x%10==0) return false;
        int reverted = 0;
        while(reverted < x){
            reverted = reverted*10 +x%10;
            x /=10;
        }
        return reverted==x || reverted/10 == x;//奇数和偶数的情况
    }
};