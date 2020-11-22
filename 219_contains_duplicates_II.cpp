#include "utils.h"
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::map<int, vector<int>> positions;
        for(int i =0; i<nums.size();++i){
            if(positions.find(nums[i])!=positions.end()){
                vector<int> vec{i};
                positions.emplace(nums[i], vec);
            } 
            positions[nums[i]].push_back(i);
        }
        for(auto iter=positions.begin();iter!=positions.end();++iter){
            vector<int> vec = iter->second;
            if(vec.size()<2) continue;
            sort(vec.begin(), vec.end());
            for(int i=1;i<vec.size();++i){
                if(vec[i]-vec[i-1]<=k) return true;
            }
        }
        return false;
    }
};