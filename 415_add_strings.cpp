#include "utils.h"
class Solution {
public:
    string addStrings(string num1, string num2) {
        int remain=0, add=0;
        int m = num1.size();
        int n = num2.size();
        vector<char> results;
        if(m<n){
            string tmp = num1;
            num1 = num2;
            num2 = tmp;
            int tmpint = m;
            m=n;
            n=tmpint;
        }
        int i=0;
        for(;i<n;i++){
            int sum = (num1[m-1-i]-'0') + (num2[n-1-i]-'0') + add;
            add = sum/10;
            remain = sum%10;
            results.push_back('0'+remain);
            // printf("%d %d %d ", sum, remain, add);
        }
        for(;add>0 && i<m;i++){
            // if(add==0) break;
            int sum = (num1[m-1-i]-'0')+add;
            add = sum/10;
            remain = sum%10;
            results.push_back('0'+remain);
        }
        for(;i<m;i++){
            results.push_back(num1[m-1-i]);
        }
        if(add!=0) results.push_back('1');
        std::reverse(results.begin(), results.end());
        string res(results.begin(), results.end());
        return res;


    }
};