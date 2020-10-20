#include "utils.h"

//method 1 false
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        set<string> box;
        vector<vector<vector<string>>> dp(s.size(), vector<vector<string>>(s.size(), vector<string>{}));
        int count = 0;
        for(int i=0;i<s.size();++i){
            string str = s.substr(i,1);
            dp[i][i].push_back(str);
            if(box.find(str)==box.end()){
                count++;
                box.insert(str);
            }
        }
        for(int i=0;i<s.size()-1;++i){
            if(s[i]==s[i+1]){
                string str = s.substr(i,2);
                dp[i][i+1].push_back(str);
                if(box.find(str)==box.end()){
                    count++;
                    box.insert(str);
                }
            }else{
                dp[i][i+1].push_back(s.substr(i,1));
                dp[i][i+1].push_back(s.substr(i+1,1));
            }
        }
        
        
        for(int right=2;right<s.size();++right){
            int len = 0;
            while(right + len < s.size()){
                int i=len, j = right+len;
                printf("i=%d, s[i]=%c, j=%d, s[j]=%c\n", i, s[i], j,s[j]);
                if(s[i]==s[j]){
                    for(int k=0;k<=dp[i+1][j-1].size();++k){
                        printf("hello before");
                        string str = s.substr(i,1)+ dp[i+1][j-1][k] + s.substr(j,1);
                        printf("hello after");
                        dp[i][j].push_back(str);
                        if(box.find(str)==box.end()){
                            count++;
                            box.insert(str);
                        }
                    }
                    
                }else{
                    printf("hello there!\n");
                    dp[i][j].reserve(dp[i][j].size() + dp[i+1][j].size()+dp[i][j-1].size());

                    dp[i][j].insert(dp[i][j].end(), dp[i+1][j].begin(), dp[i+1][j].end());
                    dp[i][j].insert(dp[i][j].end(), dp[i][j-1].begin(), dp[i][j-1].end());
                }
                len++;
            }
        }

        return count;
    }
};


//final right solution
/**
 * 1) mod 之前要注意和0的关系
 * 2) 找头尾还是要注意用双指针, 不然整段遍历就超时
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i=0; i<s.size();++i){
            dp[i][i] = 1;
        }
        int MODULE = 1000000007;//pow(10,9) + 7;
        
        for(int i=s.size()-1;i>=0;--i){
            for(int j=i+1;j<s.size();++j){
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1]*2 % MODULE;
                    // vector<int> same_numbers_idx; //to record the same start+end pairs
                    // for(int k=i+1;k<=j-1;k++){
                    //     if(s[k]==s[i]) same_numbers_idx.push_back(k);
                    // }
                    // if(same_numbers_idx.size()<=0) dp[i][j] +=2;
                    // else if(same_numbers_idx.size()==1) dp[i][j] +=1;
                    // else if(same_numbers_idx.size()>1)dp[i][j] -= dp[same_numbers_idx[0]+1][same_numbers_idx[same_numbers_idx.size()-1]-1];
                    int left = i+1, right = j-1;
                    while(left <s.size() && s[left]!=s[i]) left++;
                    while(right>=0 && s[right]!=s[i]) right--;
                    if(left>right) dp[i][j] +=2;
                    else if(left==right ) dp[i][j] +=1;
                    else dp[i][j] -= dp[left+1][right-1];
                }else{
                    dp[i][j] = dp[i+1][j] + (dp[i][j-1] - dp[i+1][j-1]);
                    
                }
               dp[i][j] = dp[i][j]<0? (dp[i][j]+MODULE)%MODULE : dp[i][j]%MODULE; // 一定要注意这里不能直接% 还要比较一下和0 的大小
            }
        }
        return dp[0][s.size()-1];
    }
};