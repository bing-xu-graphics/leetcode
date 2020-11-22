#include "utils.h"
/**
 * Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-swap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int maximumSwap(int num) {
        if(num/10==0) return num;
        vector<int> digits;
        int tmp = num;
        while(tmp!=0){
            digits.push_back(tmp%10);
            tmp/=10;
        }
        vector<int> sorted_digits(digits);
        // reverse(digits.begin(), digits.end());

        sort(sorted_digits.begin(), sorted_digits.end());
        int pos_small = digits.size()-1;
        for(;pos_small>=0;pos_small--){
            if(sorted_digits[pos_small]!=digits[pos_small]) break;
        }
        if(pos_small<0) return num; //forget at first time
        int pos_big=0;
        for(;pos_big<digits.size();pos_big++){
            if(digits[pos_big]==sorted_digits[pos_small]) break;
        }
        int swap_tmp = digits[pos_small];
        digits[pos_small] = digits[pos_big];
        digits[pos_big] = swap_tmp;
        int res = 0;
        int multi = 1;
        for(int i=0;i<digits.size();i++){
            res+= digits[i]*multi;
            multi*=10;
        }
        return res;




    }
};