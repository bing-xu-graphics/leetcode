#include "utils.h"
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i=0;i<nums.size()-2; ++i){
            for(int j=i+1; j<nums.size()-1; ++j){
                int left = j+1, right = nums.size();
                while(left<right){
                    int median = left + (right-left)/2; //这里一开始>>1 是错的, int median = left + ((right-left)>>1); 
                    //优先级不同一定要注意, >> << 的优先级太低了
                    if(nums[i]+nums[j] <= nums[median]) right = median;
                    else left = median+1;
                }
                res+= left-(j+1);
            }
        }
        return res;
    }

};
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i=0;i<nums.size()-2; ++i){
            int left = i+2;
            for(int j=i+1; j<nums.size()-1;++j){
                int right = nums.size();
                while(left<right){
                    int median = left + (right-left)/2;
                    if(nums[i]+nums[j]<=nums[median]) right = median;
                    else left = median+1;
                }
                // printf("i=%d, j=%d, k=%d, left=%d \n", i,j,k, left);
                res += max(0,left-(j+1));
            }
        }
        return res;
    }

};
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i=0;i<nums.size()-2; ++i){
            int k = -1;
            for(int j=i+1; j<nums.size()-1;++j){
                if(k==-1) k = j+1;
                else k=max(k, j+1);
                int left = k, right = nums.size();
                while(left<right){
                    int median = left + (right-left)/2;
                    if(nums[i]+nums[j]<=nums[median]) right = median;
                    else left = median+1;
                }
                // printf("i=%d, j=%d, k=%d, left=%d \n", i,j,k, left);
                res += left-(j+1);
                k = left;
            }
        }
        return res;
    }

};

//这个只有O(n^2)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i=nums.size()-1;i>=2;--i){
            int left = 0, right = i-1;
            while(left<right){
                if(nums[left]+nums[right]>nums[i]){
                    res += right-left;
                    right--;
                }else left++;
            }
        }
        return res;
    }

};