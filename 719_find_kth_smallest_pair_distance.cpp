#include "utils.h"
//method1  超时了, 利用差的大小来做的. 其实是用桶排序来做的.
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> counter(1000000, 0);
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size(); ++j){
                counter[abs(nums[i]-nums[j])]++;
            }
        }
        int count = 0;
        for(int i=0;i<1000000;++i){
            count+=counter[i];
            if(count>=k) return i;
        }
        return -1;
    }   
};

//method2  这个是一个错误的方法.   不对 
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        printf("nums:  ");
        print_list(nums);
        vector<int> diffs;
        unordered_map<int, vector<int>> diff_2_position;
        for(int i=1;i<nums.size();++i){
            int diff = nums[i]- nums[i-1];
            diffs.push_back(diff);
            if(diff_2_position.find(diff)==diff_2_position.end()){
                vector<int> position{i-1};
                diff_2_position[diff] = position;
            }else{
                diff_2_position[diff].push_back(i-1);
            }
        }
        printf("diffs:  ");
        print_list(diffs);
        vector<int> sorted_diffs(diffs);
        sort(sorted_diffs.begin(), sorted_diffs.end());
        printf("sorted_diffs:  ");
        print_list(sorted_diffs);
        int cnt=0;
        vector<int> tmp;
        int j =0;
        for(int i=0;i<sorted_diffs.size();++i){
            tmp = diff_2_position[sorted_diffs[i]];
            for(j=0; j<tmp.size();++j){
                cnt += (n-1) -tmp[j];
                // printf("(i,j) =(%d, %d) cnt=%d, k=%d\n", i, j, cnt, k);
                if(cnt==k) return nums[nums.size()-1]-nums[tmp[j]];
                if(cnt>k) break;
            }
            if(cnt>k) break;
        }
        return nums[nums.size()-1-cnt+k] - nums[tmp[j]]; 

        
    }   
    void print_list(vector<int>& nums){
        for(int i=0; i<nums.size();++i){
            printf("%d ", nums[i]);
        }
        printf("\n");
    }
};


// the right solution, using binary search!!  
/**
 * 来搜索值域, 我没有太明白, 为什么从min_distance 开始就不对, 从0 开始才对呢,  噢, 因为nums[1]-nums[0]不一定是最小值
 * 另外这个时间复杂度是 Nlog(N) + Nlog(W)  w = max_distance.
 * 
 * for(int right=left+1; right<n;++right){
                while(right<n && nums[right]-nums[left]>mid) left++;
                cnt+=(right-left);
            } 这一段为什么是O(N) 呢
 */
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[nums.size()-1]- nums[0];// nums[1]- nums[0]  这里low 不是
        while(low<high){
            int mid = (low+high)/2;
            int cnt = 0;
            //to calculate the cnt <=mid
            int left = 0;
            for(int right=left+1; right<n;++right){
                while(right<n && nums[right]-nums[left]>mid) left++;
                cnt+=(right-left);
            }
            if(k > cnt) low = mid+1;
            else high = mid; 
        }
        return low;
    }   
    void print_list(vector<int>& nums){
        for(int i=0; i<nums.size();++i){
            printf("%d ", nums[i]);
        }
        printf("\n");
    }
};

//method  稍微修改一下中间的循环
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[nums.size()-1]- nums[0];// nums[1]- nums[0]  这里low 不是
        while(low<high){
            int mid = (low+high)/2;
            int cnt = 0;
            //to calculate the cnt <=mid
            int left = 0;
            // for(int right=left+1; right<n;++right){
            //     while(right<n && nums[right]-nums[left]>mid) left++;
            //     cnt+=(right-left);
            // }
            for(int right=left+1; right<n;++right){
                while(right<n && nums[right]-nums[left]<=mid) right++;
                cnt+=(--right-left);
                left++;
            }
            while(left<n) cnt+=(n-1-left++);
            if(k > cnt) low = mid+1;
            else high = mid; 
        }
        return low;
    }   
    void print_list(vector<int>& nums){
        for(int i=0; i<nums.size();++i){
            printf("%d ", nums[i]);
        }
        printf("\n");
    }
};