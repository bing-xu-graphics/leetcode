#include "utils.h"
/**
 * Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//method1 TLE!
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int pairs = 0;
        int sorted_r = nums.size()-1, sorted_l = sorted_r, mover = sorted_l-1;
        while(mover>=0){
            //find the numbr of paris using binary search
            int low = sorted_l, high = sorted_r;
            while(low<=high){
                int mid = low + (high-low)/2;
                if((double)nums[mover]/2<=nums[mid]){
                    high = mid - 1;
                }else low = mid+1;
            }
            pairs += (low-1-sorted_l+1);
            // printf("mover = %d, pairs = %d\n", mover, pairs);
            //insert the mover into
            // printf("haha\n");
            int tmp = nums[mover];
            int i = sorted_l;
            // printf("i=%d, tmp=%d\n", i, tmp);
            while(i<=sorted_r && nums[i]<tmp){
                // printf("i=%d,\n");
                nums[i-1] = nums[i];
                i++;
            }
            nums[i-1] = tmp;
            sorted_l--;
            mover--;
            // for(int ii=0;ii<nums.size();++ii){
            //     printf("%d ", nums[ii]);
            // }
            // printf("\n");
        }
        return pairs;
    }
};
/**
 * method1 太慢了, 可以想到是因为我用了insertsort 的方法, 让复杂度降到了 O(n^2)
 * 我这里需要的一个数据结构是, 又支持找到比某数小的个数, 又支持插入比较快. 
 * 上面就是我的维持一个sorted list , search 很快 只要logN   但是插入用了N, 
 * 那么有什么方法都比较快呢?
 * BInary search tree 在平均可以达到NlogN  但是在最坏的情况下会退化为链表, 即也要用到N来插入和搜索, 更加的慢
 * 于是也超时
 * 我们这里需要的是search 和insert 都比较快的 , 因为搜索的范围是在不断变化的, 比如balanced-tree 如 红黑树或者AVL Tree,
 * BIT binary indexted tree,  segment tree 等等
 */




//method2 用了BIT

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size()<2) return 0;
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        vector<int> bit(nums.size()+1, 0);
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            ans += search(bit, index(sorted_nums, (long)2*nums[i]+1)+1);
            update(bit, index(sorted_nums, nums[i])+1);
        }
        return ans;
    }
    int search(vector<int>& bit, int idx){
        int sum = 0;
        // while(idx>0){
        while(idx<bit.size()){
            sum += bit[idx];
            // idx -= (idx & -idx);
            idx += (idx & -idx);
        }
        return sum;
    }

    void update(vector<int>& bit, int idx){//这里的value 等于个数等于1
        // while(idx<bit.size()){
        while(idx>0){    
            bit[idx]+=1;
            // idx += (idx & -idx);
            idx -= (idx & -idx);
        }
    }
    int index(vector<int>& sorted_nums, long target){
        int low = 0, high = sorted_nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(sorted_nums[mid]>=target) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};

