#include "utils.h"
/**
 * Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.

 

Example 1:

Input: num = 16
Output: true
Example 2:

Input: num = 14
Output: false
 

Constraints:

1 <= num <= 2^31 - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-perfect-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        int k=1;
        while(k<46341 && k*k<num){k++;}
        return k<46341 &&k*k==num;
    }
};

//二分法
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1) return true;
        int left = 2, right = num/2;
        while(left<right){
            int mid = left+ (right - left)/2;
            if(mid>= 46341){
                right = mid-1;
                continue;
            }
            if(mid*mid == num) return true;
            else if(mid*mid < num) left = mid+1;
            else right = mid-1;
        }
        return left<46341 &&left*left == num;
        // return false;
    }
};


// 牛顿法 太棒啦!!
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1) return true;
        int x = 46340;//num/2;
        // while(x>=2147483647/x) x--;
        while(x*x>num){
            x = (x+ num/x)/2;
        }
        return x*x==num;
    }
};