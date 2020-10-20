#include "utils.h"
/*
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

 

Example:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 

Constraints:

The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/task-scheduler
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int all_num = tasks.size();
        map<char, int> count;
        for(int i=0; i<tasks.size();++i){
            if(count.find(tasks[i])!=count.end()) count[tasks[i]]++;
            else count[tasks[i]] = 1;
        }
        int max_num = 0, max_num_count=0;
        for(auto iter=count.begin(); iter!= count.end();++iter){
            if(iter->second>max_num){
                max_num = iter->second;
            } 
        }
        for(auto iter=count.begin(); iter!= count.end();++iter){
            if(iter->second==max_num){
                max_num_count++;
            } 
        }
        int space = (max_num - 1)* (n-max_num_count+1);
        // printf("space=%d", space);
        int extra = max(all_num-max_num*max_num_count-space, 0);
        return max_num*max_num_count+space + extra;
    }
};