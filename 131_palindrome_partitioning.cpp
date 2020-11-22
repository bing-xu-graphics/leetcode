/**
 * Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//method1 not fast enough, 没有使用历史信息
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> current;
        backtrack(res, s, 0,current);
        return res;
    }

    void backtrack(vector<vector<string>>& res, string s, int start, vector<string>& current){
        if(start==s.size()){
            // current.push_back(s.substr(start,1));
            res.push_back(current);
            // current.pop_back();
            return;
        }

        for(int split=start+1; split<=s.size();++split){
            if(isPalindrome(s.substr(start, split-start))){
                current.push_back(s.substr(start, split-start));
                backtrack(res, s, split, current);
                current.pop_back();
            }
        }

    }
    bool isPalindrome(string s){
        string original(s);
        reverse(s.begin(), s.end());
        return s==original;
    }
};

//method2 , 历史信息, 即palindorme可以DP的思想构造一些history. 快了非常多
class Solution {
public:
vector<vector<bool>> dp;
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> current;
        
        dp = vector<vector<bool>>(s.size(), vector<bool>(s.size(), false));
        for(int i=0;i<s.size();++i){
            dp[i][i] = true;
        }
        for(int start=s.size()-2;start>=0;--start){
            for(int end=start+1; end<s.size(); ++end){
                if(start+1<=end-1 && dp[start+1][end-1] && s[start]==s[end]) dp[start][end] = true;
                if(start+1==end) dp[start][end]= s[start]==s[end];
            }
        }
        backtrack(res, s, 0,current);
        return res;

    }

    void backtrack(vector<vector<string>>& res, string s, int start, vector<string>& current){
        if(start==s.size()){
            res.push_back(current);
            return;
        }

        for(int split=start+1; split<=s.size();++split){
            if(isPalindrome(start, split-1)){
                current.push_back(s.substr(start, split-start));
                backtrack(res, s, split, current);
                current.pop_back();
            }
        }

    }
    bool isPalindrome(int start, int end){
        return dp[start][end];
    }
    bool isPalindrome(string s){
        string original(s);
        reverse(s.begin(), s.end());
        return s==original;
    }
};