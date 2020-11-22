#include "utils.h"
/*
A zero-indexed array A of length N contains all integers from 0 to N-1. Find and return the longest length of set S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.

Suppose the first element in S starts with the selection of element A[i] of index = i, the next element in S should be A[A[i]], and then A[A[A[i]]]… By that analogy, we stop adding right before a duplicate element occurs in S.

Example 1:

Input: A = [5,4,0,3,1,6,2]
Output: 4
Explanation: 
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

One of the longest S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
 

Note:

N is an integer within the range [1, 20,000].
The elements of A are all distinct.
Each element of A is an integer within the range [0, N-1].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/array-nesting
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int longest_length = 1;
        set<int> visited;
        set<int> tmp_visited;
        int tmp_length = 0;
        int start =0;
        for(int start=0;start<nums.size();++start){
            tmp_visited.clear();
            tmp_length = 0;
            if(visited.find(start)!=visited.end()) continue;
            int current = start;
            while(current!=nums[current]){
                if(tmp_visited.find(current)!=tmp_visited.end()) break;
                tmp_visited.insert(current);
                current = nums[current];
                tmp_length++;
            }
            if(tmp_length>longest_length) longest_length = tmp_length;
            for(auto iter=tmp_visited.begin();iter!=tmp_visited.end();++iter){
                visited.insert(*iter);
            }
        }
        return longest_length;
    }
};


//solution2 不需要拆成2个, 因为每个只出现了一次
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int longest_length = 1;
        set<int> visited;
        int tmp_length = 0;
        int start =0;
        for(int start=0;start<nums.size();++start){
            tmp_length = 0;
            if(visited.find(start)!=visited.end()) continue;
            int current = start;
            while(current!=nums[current]){
                if(visited.find(current)!=visited.end()) break;
                visited.insert(current);
                current = nums[current];
                tmp_length++;
            }
            if(tmp_length>longest_length) longest_length = tmp_length;

        }
        return longest_length;
    }
};

//solution3 不利用额外的空间
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int longest_length = 1;
        int tmp_length = 0;
        for(int start=0;start<nums.size();++start){
            tmp_length = 0;
            if(nums[start]==-1) continue;
            int current = start;
            while(current!=nums[current]){
                if(nums[current]==-1) break;
                int tmp = nums[current];
                nums[current] = -1;
                current = tmp;
                tmp_length++;
            }
            if(tmp_length>longest_length) longest_length = tmp_length;

        }
        return longest_length;
    }
};