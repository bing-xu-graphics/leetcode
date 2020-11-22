#include "utils.h"
/**
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/multiply-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0"; //一开始没通过, 少了这个
        vector<int> digits;
        if(num1.size()<num2.size()){
            string tmp = num1;
            num1 = num2;
            num2 = tmp;
        }
        int m = num1.size(), n = num2.size();
        
        for(int ni=n-1; ni>=0; --ni){
            int remain = 0, add = 0, multiplier = num2[ni]-'0';
            vector<int> tmp_sum;
            for(int mi = m-1; mi>=0;--mi){
                int product = (num1[mi]-'0')* multiplier+add;
                remain = product % 10;
                add = product /10;
                tmp_sum.push_back(remain);
            }
            if(add!=0) tmp_sum.push_back(add);
            // print_a_vec(tmp_sum);

            vector<int> tmp_digits;
            if(ni==n-1){
                tmp_digits = tmp_sum;
                digits = tmp_digits;
            }else{
                tmp_digits.reserve((n-ni)+tmp_sum.size());
                for(int i=0;i<(n-ni-1);++i){
                    tmp_digits.push_back(0);
                }
                // tmp_digits[0] = 0;
                tmp_digits.insert(tmp_digits.end(), tmp_sum.begin(), tmp_sum.end());
                // print_a_vec(tmp_digits);
                int add_ = 0, remain_ = 0;
                for(int i=0;i<digits.size();++i){
                    int addition = tmp_digits[i]+digits[i]+add_;
                    remain_ = addition%10;
                     add_ = addition/10;
                    tmp_digits[i]=remain_;
                }
                for(int i=digits.size();i<tmp_digits.size();++i){
                    int addition = tmp_digits[i]+add_;
                    remain_ = addition%10;
                    add_ = addition/10;
                    tmp_digits[i]=remain_;
                }
                if(add_!=0) tmp_digits.push_back(add_);
                // print_a_vec(tmp_digits);
                digits = tmp_digits;
            }
        }

        reverse(digits.begin(), digits.end());
        string ans;
        for(char digit:digits){
            ans+=digit+'0';
        }
        return ans;
    }

    void print_a_vec(vector<int>& nums){
        for(int num:nums){
            printf("%d ", num);
        }
        printf("\n");
    }
};