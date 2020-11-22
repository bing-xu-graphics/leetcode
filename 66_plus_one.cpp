#include "utils.h"
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int position = digits.size()-1;
        int add = 1;
        while(position>=0){
            if(add==0) break;
            int tmp = digits[position]+add;
            digits[position] = tmp%10;
            add = tmp/10;
            position--;
        }
        if(add == 0) return digits;
        res.reserve(1 + digits.size());
        res.push_back(1);
        res.insert(res.end(), digits.begin(), digits.end());
        return res;
    }
};