#include "utils.h"
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> record1;
        unordered_map<int, int> record2;
        for(int i=0;i<nums1.size();++i){
            if(record1.find(nums1[i])==record1.end()){
                record1[nums1[i]] = 1;
            }else{
                record1[nums1[i]]++;
            }
        }
        for(int i=0;i<nums2.size();++i){
            if(record2.find(nums2[i])==record2.end()){
                record2[nums2[i]] = 1;
            }else{
                record2[nums2[i]]++;
            }
        }
        vector<int> ans;
        for(auto rec:record1){
            if(record2.find(rec.first)!=record2.end()){
                int k = min(rec.second, record2[rec.first]);
                for(int i=0;i<k;++i) ans.push_back(rec.first);
            }
        }
        return ans;

    }
};