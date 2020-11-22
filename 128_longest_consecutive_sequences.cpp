#include "utils.h"
//这个是错误的, 这个无法handle duplicates的情况
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n;
        int remain = n;
        int maxLength = 0;
        for(int start=0; start<nums.size(); ++start){
            remain = n-1;
            for(int i=0;i<nums.size();++i){
                if(start==i) continue;
                if(nums[i]>nums[start] && nums[i]<=nums[start]+remain) continue;
                else remain--;
            }
            // printf("start = %d, remain=%d\n", nums[start], remain);
            maxLength = max(maxLength, remain+1);
        }
        return maxLength;
    }
};



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n;
        int remain = n;
        int maxLength = 0;
        for(int start=0; start<nums.size(); ++start){
            set<int> elements;
            remain = n-1;
            elements.insert(nums[start]);
            for(int i=0;i<nums.size();++i){
                // printf("size of elements=%d\n", (int) elements.size());
                if(start==i) continue;
                if(nums[i]>=nums[start] && nums[i]<=nums[start]+remain && elements.find(nums[i])==elements.end()){
                    elements.insert(nums[i]);
                }else remain--;
                while(elements.find(nums[start]+remain+1)!=elements.end()){
                    elements.erase(nums[start]+remain+1);
                    remain--;
                }//这个loop 非常重要,一开始是缺少的
            }
            // printf("start = %d, remain=%d\n", nums[start], remain);
            maxLength = max(maxLength, remain+1);
        }
        return maxLength;
    }
};

//溢出了 , 全部改成了long, 超时了...

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n;
        int remain = n;
        int maxLength = 0;
        for(int start=0; start<nums.size(); ++start){
            set<long> elements;
            remain = n-1;
            elements.insert(nums[start]);
            for(int i=0;i<nums.size();++i){
                // printf("size of elements=%d\n", (int) elements.size());
                if(start==i) continue;
                if(nums[i]>=nums[start] && (long)nums[i]<=(long)nums[start]+remain && elements.find(nums[i])==elements.end()){
                    elements.insert(nums[i]);
                }else remain--;
                while(elements.find((long)nums[start]+remain+1)!=elements.end()){
                    elements.erase(nums[start]+remain+1);
                    remain--;
                }
            }
            // printf("start = %d, remain=%d\n", nums[start], remain);
            maxLength = max(maxLength, remain+1);
        }
        return maxLength;
    }
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n;
        int remain = n;
        int maxLength = 0;
        int longest_start = 0, longest_end = -1;
        set<int> all;
        for(int num:nums) all.insert(num);
        for(int start=0; start<nums.size(); ++start){
            if(all.find(nums[start]-1) != all.end()) continue; //这个优化没有想到. 就是只从每段最小的开始找.
            set<long> elements;
            remain = n-1;
            elements.insert(nums[start]);
            for(int i=0;i<nums.size();++i){
                // printf("size of elements=%d\n", (int) elements.size());
                if(start==i) continue;
                if(nums[i]>=nums[start] && (long)nums[i]<=(long)nums[start]+remain && elements.find(nums[i])==elements.end()){
                    elements.insert(nums[i]);
                }else remain--;
                while(elements.find((long)nums[start]+remain+1)!=elements.end()){
                    elements.erase(nums[start]+remain+1);
                    remain--;
                }
            }
            // printf("start = %d, remain=%d\n", nums[start], remain);
            maxLength = max(maxLength, remain+1);
        }
        return maxLength;
    }
};


//换一个简便的写法.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n;
        int maxLength = 0;
        
        set<int> all;
        for(int num:nums) all.insert(num);
        for(int start=0; start<nums.size(); ++start){
            if(all.find(nums[start]-1) != all.end()) continue;
            int length =1;
            while(all.find(nums[start]+length)!=all.end()){
                length++;
            }
            // printf("start = %d, remain=%d\n", nums[start], remain);
            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};