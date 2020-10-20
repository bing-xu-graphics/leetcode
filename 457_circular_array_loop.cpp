#include"utils.h"

/**
 * You are given a circular array nums of positive and negative integers. If a number k at an index is positive, then move forward k steps. Conversely, if it's negative (-k), move backward k steps. Since the array is circular, you may assume that the last element's next element is the first element, and the first element's previous element is the last element.

Determine if there is a loop (or a cycle) in nums. A cycle must start and end at the same index and the cycle's length > 1. Furthermore, movements in a cycle must all follow a single direction. In other words, a cycle must not consist of both forward and backward movements.

 

Example 1:

Input: [2,-1,1,2,2]
Output: true
Explanation: There is a cycle, from index 0 -> 2 -> 3 -> 0. The cycle's length is 3.
Example 2:

Input: [-1,2]
Output: false
Explanation: The movement from index 1 -> 1 -> 1 ... is not a cycle, because the cycle's length is 1. By definition the cycle's length must be greater than 1.
Example 3:

Input: [-2,1,-1,-2,-2]
Output: false
Explanation: The movement from index 1 -> 2 -> 1 -> ... is not a cycle, because movement from index 1 -> 2 is a forward movement, but movement from index 2 -> 1 is a backward movement. All movements in a cycle must follow a single direction.
 

Note:

-1000 ≤ nums[i] ≤ 1000
nums[i] ≠ 0
1 ≤ nums.length ≤ 5000
 

Follow up:

Could you solve it in O(n) time complexity and O(1) extra space complexity?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/circular-array-loop
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
//Solution 1 使用了太多存储
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        if(nums.size()<1) return false;
        set<int> same_direction;
        set<int> other_direction;
        set<int> used_start;
        // vector<bool> visited(nums.size(), false);
        int n = nums.size();
        for(int start = 0; start<n;++start){
            if(used_start.find(start)!=used_start.end()) continue;
            int prev = start;
            int current = ((nums[prev]+prev)%n+n)%n;
            same_direction.clear();
            other_direction.clear();
            same_direction.insert(prev);
            used_start.insert(prev);
            while(current!=prev){
                used_start.insert(current);
                // printf("prev=%d, current=%d\n", prev, current);
                // printf("show same_direction set\n");
                // for(auto iter=same_direction.begin();iter!=same_direction.end();++iter){
                //     printf("%d ", *iter);
                // }
                // printf("\nshow other_direction set\n");
                // for(auto iter=other_direction.begin();iter!=other_direction.end();++iter){
                //     printf("%d ", *iter);
                // }
                // printf("\n");

                if(nums[prev]*nums[current]>0){
                    if(same_direction.find(current)!=same_direction.end()) return true;
                    else{
                        same_direction.insert(current);
                    }
                }else{
                    if(other_direction.find(current)!=other_direction.end()) break;
                    else{
                        other_direction = same_direction;
                        same_direction.clear();
                        same_direction.insert(current);
                    }
                }
                // int step = nums[current];
                prev = current;
                current = ((nums[current]+current) % n +n)%n;
            }
            
        }//这个loop 是后来加的, 发现start位置其实是不确定的
        return false;
        
    }
};