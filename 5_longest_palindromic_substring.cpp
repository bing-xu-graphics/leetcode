#include "utils.h"
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2) return s;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i=0; i<s.size();++i){
            dp[i][i] = 1;
        }
        vector<int> res{0,0};
        for(int i=0;i<s.size()-1;++i){
            if(s[i]==s[i+1]){
                dp[i][i+1] = 2;
                res[0] = i;
                res[1] = i+1;
            } 
        }

        int max_length = 0;
        for(int right=2; right<s.size();++right){
            int k =0;
            while(right+k<s.size()){
                if(dp[k+1][right+k-1]!=0 && s[k]==s[right+k]) dp[k][right+k] = dp[k+1][right+k-1]+2;
                if(max_length < dp[k][right+k]){
                    max_length =dp[k][right+k];
                    res[0] = k;
                    res[1] = right+k;
                }
                k++;
            }
        }
        return s.substr(res[0], res[1]-res[0]+1);
    }
};