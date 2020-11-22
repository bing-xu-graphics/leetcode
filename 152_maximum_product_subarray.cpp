#include "utils.h"
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //O(n^3)
        //O(n^2)
        if(nums.size()<1) return -1;//exception actually
        if(nums.size()<2) return nums[0];
        int smallest = 1;
        int largest = 1;
        int res = nums[0];
        //for initialize
        bool largest_set = false, smallest_set = false;
        int i = 0;
        for(;i<nums.size();++i){
            if(nums[i]==0){
                res = max(res, 0);
                smallest = 1;
                largest = 1;
                smallest_set = false;
                largest_set = false;
            }
            if(largest_set && smallest_set){
                if(nums[i]<0){
                int tmp_smallest = nums[i]*largest;
                largest = nums[i]* smallest;
                smallest = tmp_smallest;
                res = max(largest, res);
                }else{
                    smallest *= nums[i];
                    largest *= nums[i];
                    res = max(largest, res);
                }
            }
            else if(nums[i]>0){
                largest*= nums[i];
                largest_set = true;
                res = max(res, largest);
                if(smallest_set) smallest*=nums[i];
            }else if(nums[i]<0){
                if(smallest<0){
                    largest = smallest * nums[i];
                    largest_set = true;
                    res = max(res, largest);
                    smallest = nums[i];//
                    continue;
                }
                smallest_set = true;
                smallest = largest*nums[i];       
                largest = 1;
            }
            // printf("start=%d, smallest=%d, largest = %d\n", i, smallest, largest);
        }
        
        return res;
    }
};

//上面的太麻烦了.每次就是记录两个status 


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()<1) return -1;
        int smallest = nums[0];
        int largest = nums[0];
        int res = nums[0];
        for(int i=1;i<nums.size();++i){
            int smallest_backup = smallest;
            int largest_backup = largest;
            smallest = min(min(largest_backup*nums[i], smallest_backup*nums[i]), nums[i]);
            largest = max(max(smallest_backup*nums[i], largest_backup*nums[i]), nums[i]);
            res = max(largest, res);
        }
        
        return res;
    }
};