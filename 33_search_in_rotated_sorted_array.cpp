#include<utils.h>
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return -1;
        if(n==1) return nums[0]== target? 0:-1;
        
        int low = 0, high = n-1, last_median=0;
        int offset=0;
        while(low < high){
            int median = (low+high)/2;
            printf("low=%d, high=%d, median=%d \n",low, high, median);
            if(nums[low]>nums[median]){
                high = median - 1;
                last_median = median;
            }
            else if(nums[median]>nums[high]){
                low = median+1;
                last_median = median + 1;
            } 
            else break;
            // last_median = median;
        }
        offset = last_median;
        printf("offset=%d \n", offset);
        int i=0, j=n-1;
        while(i<=j){
            int median = (i+j)/2;
            if(nums[(median+offset)%n]<target) i = median+1;
            else if(nums[(median+offset)%n]>target) j = median-1;
            else return (median+offset)%n;
        }

        return -1;

    }
};

//solution2: 不想那么多,合并两个,进行排除,比较难的还是边界条件
class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return -1;
        if(n==1) return nums[0]== target? 0:-1;
        
        int low = 0, high = n-1;
        while(low <= high){
            int median = (low+high)/2;
            // printf("low=%d, high=%d, median=%d\n",low, high, median);
            if(nums[median]==target) return median;
            if(nums[low]<=nums[median]){
                if(nums[low]<=target && target <nums[median]) high = median -1;
                else low = median +1;
            }else{
                if(nums[median]< target&& target<=nums[high]) low = median + 1;
                else high = median -1;
            }
        }
        return -1;
    }
};