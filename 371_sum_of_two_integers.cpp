#include "utils.h"
/**
 * Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-two-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/**
 * 这里学到了好多东西啊
 * 1)  亦或,   a^b 相当于无进位的相加
 * 而  (a&b) <<1  相当于找到进位, 即carry  注意这里是进了一位噢. 
 * 2) 由于<<1 有可能造成负数的溢出, 所以可以把 (a&b)换成(unsigned int) 或者(long long) 这里并不是因为
 * unsigned int 可以存负数, 只是暂时加了一个 2147483648*2   到时候输出 又转换回来signed int 的
 * 3)
class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            auto carry = ((unsigned int)(a&b))<<1;
            // printf("%d %u \n", (unsigned int)a&b, (unsigned int)a&b); 
            //-4 4294967292 
            //0 0
            a = a^b;
            b = carry;
        }
        return a;
    }
};