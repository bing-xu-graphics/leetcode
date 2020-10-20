#include "utils.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4) return res;
        std::sort(nums.begin(), nums.end());
        for(int m=0; m<nums.size()-3; m++){
            if(m>0 && nums[m]== nums[m-1]) continue;
            for(int n=m+1; n<nums.size()-2; n++){
                if(n>m+1 &&nums[n]==nums[n-1]) continue;
                int i = n+1, j= nums.size()-1;
                // printf("%d,%d,%d,%d",m,n,i,j);
                while(i<j){
                    int sum = nums[m]+nums[n]+nums[i]+nums[j];
                    if(sum < target) i++;
                    else if(sum > target) j--;
                    else{
                        if(res.size()<1){
                            res.push_back(vector<int>{nums[m],nums[n],nums[i],nums[j]});
                        }else{
                            auto iter_last = res.end()-1;
                            if(!((*iter_last)[0]==nums[m] && (*iter_last)[1]==nums[n]&&(*iter_last)[2]==nums[i] )) res.push_back(vector<int>{nums[m],nums[n],nums[i],nums[j]});
                        }
                        i++;
                        j--;
                    }
                }
            }
        }
        return res;
    }
};