#include "utils.h"
/**
 * Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:

Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
 

Example 2:

Input: 3
Output: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-square-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0, b = 46340;//c/2;
        while(a<=b){
            int left = a*a;
            int right = c - b*b;
            if(left>right) b--;
            else if(left<right) a++;
            else return true;
        }
        return false;
    }
};

//稍微改造了一下就快了很多
class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0, b = sqrt(c);//46340;//c/2;
        while(a<=b){
            int left = a*a;
            int right = c - b*b;
            if(left>right) b--;
            else if(left<right) a++;
            else return true;
        }
        return false;
    }
};



/**
 * 方法三：费马平方和定理
费马平方和定理告诉我们：

一个非负整数 cc 能够表示为两个整数的平方和，当且仅当 cc 的所有形如 4k+34k+3 的质因子的幂次均为偶数。

证明方法可以见 这里。

因此我们对 cc 进行质因数分解，再判断形如 4k+34k+3 的质因子的幂次是否均为偶数即可。

Java

public class Solution {
    public boolean judgeSquareSum(int c) {
        for (int i = 2; i * i <= c; i++) {
            int count = 0;
            if (c % i == 0) {
                while (c % i == 0) {
                    count++;
                    c /= i;
                }
                if (i % 4 == 3 && count % 2 != 0)
                    return false;
            }
        }
        return c % 4 != 3;
    }
}
复杂度分析

时间复杂度：O(\sqrt{c})O( 
c
​	
 )。

空间复杂度：O(1)O(1)。

作者：LeetCode
链接：https://leetcode-cn.com/problems/sum-of-square-numbers/solution/ping-fang-shu-zhi-he-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/