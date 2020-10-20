/**
 * Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

通过次数439,242提交次数1,268,619

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int reverse(int x) {
        bool sign = x>=0? true:false;
        long long xx = x;
        xx = xx>=0?xx :-xx;
        long long res = 0;
        while(xx){
            res = res*10 + xx%10;
            xx /=10;
        }
        // printf("%ld\n", res);
        long long cmp = 2147483647;
        if(sign&&res>cmp ||!sign&&res>cmp+1) return 0;
        int intres = (int)res;
        return sign? res:res*(-1);
    }
};

//method2  会溢出的化就在产生大数之前比较就好了
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x){
            int small = x%10;
            if(x>=0 &&res> (numeric_limits<int>::max()-small)/10) return 0;
            if(x<=0 &&res < (numeric_limits<int>::min()-small)/10) return 0;
            x /=10;
            res = res*10 + small;
        }
        return res;
    }
};