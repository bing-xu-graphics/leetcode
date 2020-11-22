#include"utils.h"
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       vector<int> copy = nums;
       int n = nums.size();
       //
       for(int i=0;i<n;++i){
        //    printf("i=%d, %d, %d, %d\n",i,(i-k),-3/n,(i-k)%n);
           nums[i] = copy[((i-k)%n+n)%n];
       }
    }
};
//发现!!! nums.size()之类的最好不要直接放在一个 加减乘除里面, 根本不知道变成啥,
//还是要先写一个n  比如这里不是n直接写size() 的化 出现很多奇怪的结果.


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n = nums.size();
       if(n<2) return;
       k %= n;
       reverse(nums, 0, n-1);
       reverse(nums, 0, k-1);
       reverse(nums, k, n-1);
    }
    void reverse(vector<int>& nums, int low, int high){
        while(low < high){
            int tmp = nums[high];
            nums[high] = nums[low];
            nums[low] = tmp;
            low++;
            high--;
        }
    }
};



class Solution3 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int count=1;
        int start = 0, current, next;
        int pre , now;
        while(count<n && start<n){
            current = start;
            pre = nums[current];
            current = (current + k) % n;
            while(current!=start){
                // printf("pre = %d current=%d, count=%d\n", pre, current, count);
               now = nums[current];
               nums[current] = pre;
               pre = now;
               current = (current + k)%n;
               count++;
           }
           nums[current] = pre;
           count++;
           start++;
       }
    }
    
};