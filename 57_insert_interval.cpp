#include "utils.h"
/*
这边走一个binary search 的专题.
* To pay attention
一定要是前闭后开的, 这样才能保证可以表示一个空的空间. [low, high)

//for cases without duplicates
int binarySearch(vector<int> nums, int target){
    int low = 0, high = nums.size();
    while(low<high){
        int median = (low + high)>>1;
        if(nums[median] == target) return median;
        else if(nums[median]<target) low = median+1;    
        else high = median;
    }
    return -1;
}

// cases with duplicates, we need to find the lower_bound and upper_bound
int lower_bound(vector<int> nums, int target){
    int low = 0, high = nums.size();
    while(low < high){
        if(nums[median]<target) low = median+1;
        else high = median;
    }
    return low;
}

int upper_bound(vector<int> nums, int target){
    int low=0, high = nums.size();
    while(low<high){
        int median = (low+high)>>1;
        if(nums[median]<=target) low = median+1;
        else high = median;
    }
    return low; // here actually low== high
}


vector<int> findIntervalOfTarget(vector<int> nums, int target){
    int low =0, high = nums.size();
    while(low<high){
        int median = (low+high)>>1;
        if(nums[median]<target) low = meidan+1;
        else high = median;
    }
    int left = low;
    low = 0; high = nums.size();
    while(low < high){
        int median = (low + high )>>1;
        if(nums[median]<= target) low = median +1;
        else high = medianl
    }
    int right = low;
    return {left, right};
}
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int low=0, high = n; 
        int left  = binarySearch(intervals, newInterval[0]);
        int right = binarySearch(intervals, newInterval[1]);
        printf("left = %d, right = %d\n", left, right);
        vector<vector<int>> res;
        for(int i=0; i<left; ++i) res.push_back(intervals[i]);
        if(left==right && (left>=n||newInterval[1]<intervals[left][0])){
            res.push_back(newInterval);
            if(right<n)res.push_back(intervals[right]);
        }else if(right>=n || newInterval[1]<intervals[right][0]){ //之类的条件非常麻烦, 容易出错
            res.push_back({min(intervals[left][0], newInterval[0]), newInterval[1]});
            if(right<n)res.push_back(intervals[right]);
        }else{
            res.push_back({ min(intervals[left][0], newInterval[0]) ,
            max(intervals[right][1], newInterval[1]) });
        }  
        for(int i=right+1; i<n;i++) res.push_back(intervals[i]);
        return res;
    }
private:
    int binarySearch(vector<vector<int>>& intervals, int target){
        int low = 0, high = intervals.size();
        while(low < high){
            int median = (low+high)>>1;
            if(intervals[median][0]<=target && intervals[median][1]>=target) {
                return median;
            }
            else if(intervals[median][0]> target)high = median;
            else low = median + 1;
        }
        return low; //to insert
    }    
};