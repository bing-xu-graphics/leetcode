#include "utils.h"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int buy = 0, maxProfit = 0;
        for(int i=1;i<prices.size();++i){
            if(prices[i]>prices[buy]) maxProfit = maxProfit>prices[i]-prices[buy]?maxProfit:prices[i]-prices[buy];
            else if(prices[i]<prices[buy]) buy = i;
        }
        return maxProfit;
    }
};


//单调栈, O(n)时间内得知所有位置两遍第一个比它大(小)的数的位置, 同时可以知道右边所有比它大(小)的值, 在历史上存在过
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        prices.push_back(-1);
        vector<int> st;
        int maxProfit = 0;
        st.push_back(prices[0]);
        for(int i=1;i<prices.size();++i){
            while(!st.empty() && st.back()>prices[i]){
                maxProfit = maxProfit>st.back() - st.front()?maxProfit : st.back() - st.front();
                st.pop_back();
            }
           
            st.push_back(prices[i]);
        }
        return maxProfit;

        
    }
};