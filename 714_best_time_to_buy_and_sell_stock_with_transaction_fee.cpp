#include "utils.h"
//method 1  超时了.
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> memorio(prices.size(), -1);
        memorio[0] = 0;
        dp_iterative(prices.size()-1, prices, memorio, fee);
         return memorio[prices.size()-1];
    }

    void dp_iterative(int sell_day, vector<int>& prices, vector<int>& memorio,int fee)   {
        memorio[0] = 0;
        for(int sell_day = 1;sell_day<prices.size();++sell_day){
            int max_profit = 0;
            for(int buy_day = 0;buy_day<=sell_day;++buy_day){
                int profit = 0;
                if(buy_day<=0){
                    profit = max(prices[sell_day] - prices[buy_day] - fee,0);
                }else{
                    profit = memorio[buy_day-1] + max(prices[sell_day] - prices[buy_day] - fee,0);
                }
                 
                if(max_profit < profit) max_profit = profit;
            }
            memorio[sell_day] = max_profit;
        }
    }
    int dp_recursive(int sell_day, vector<int>& prices, vector<int>& memorio,int fee){
        if(sell_day<=0) return 0;
        if(memorio[sell_day]!=-1) return memorio[sell_day];
        int max_profit = 0;
        for(int buy_day=0;buy_day<=sell_day;buy_day++){
            int profit = dp_recursive(buy_day -1, prices, memorio, fee) + max(prices[sell_day] - prices[buy_day] - fee,0);
            if(max_profit < profit) max_profit = profit;
        }
        memorio[sell_day] = max_profit;
        return max_profit;
    }
};

//仔细分析一下为什么超时 , 是因为依然走了2个嵌套循环,所以还是n^2的时间复杂度.
//那么哪一部分是重复的呢, 就是 prices[sell_day] - prices[buy_day]


//method2
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size()<2) return 0;
        vector<int> diffs(prices.size()-1, 0);
        for(int i=1;i<prices.size();++i){
            diffs[i-1] = prices[i]-prices[i-1]; 
        }

        //WHAT TO LEARN
        /**
         * 这边要非常注意的是:
         * 以是否包含当前位置的 个体 为一个区分. 打家劫舍 其实就是不包含相连的情况, 
         * 而continuous subarray 则是只包含相连的情况) 这两种题型, 则只需要包含一个
         * 同时 个体都是一个相加的关系, 这里通过相邻num相减, 也构造出一个相加关系的array
         * 最后, 要注意, 两个量互相影响的话, 一定要记得第一个用临时变量存一下
         * 
        // int max_profit = 0;
        int not_ends_with = 0, ends_with=diffs[0];
        for(int i=1; i<diffs.size();++i){
            int tmp_ends_with = max(not_ends_with, ends_with) + diffs[i];
            not_ends_with = max(ends_with-fee, not_ends_with); 
            ends_with = tmp_ends_with;
            // printf("ends_with = %d, not_ends_with=%d\n", ends_with, not_ends_with);
            // max_profit = max(max(max_profit, not_ends_with), ends_with);
        }
        return max(ends_with-fee, not_ends_with);
    }

    
};