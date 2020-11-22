#include "utils.h"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        vector<int> diff(prices.size()-1);
        for(int i=1; i<prices.size(); ++i){
            diff[i-1] = prices[i]-prices[i-1];
        }
        int sum = 0;
        for(int i=0; i<diff.size(); ++i) sum+= diff[i]>0? diff[i]:0;
        return sum;

        
    }
};
//在上面的基础上, 可以直接省略diff 这个vector

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int sum = 0;
        for(int i=1; i<prices.size(); ++i) sum+= prices[i]-prices[i-1]>0? prices[i]-prices[i-1]:0;
        return sum;
    }
};