//Solution 1
#include<vector>
using std::vector;

class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int traverse_index = 0;
        int to_insert_index = 0;
        while(traverse_index < n){
            if(nums[traverse_index] != 0){
                if (to_insert_index < traverse_index){
                    int tmp = nums[to_insert_index];
                    nums[to_insert_index] = nums[traverse_index];
                    nums[traverse_index] = tmp;
                    to_insert_index +=1;
                }else{
                    to_insert_index +=1;
                }
                traverse_index += 1;
            }else{
                traverse_index += 1;
            }
        }
        
    }
};


//solution2
class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int numZeros = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==0) numZeros +=1;
            else{
                if(numZeros >0){
                    nums[i-numZeros] = nums[i];
                    nums[i] = 0;
                }
            }
        }
    }
};


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int to_insert = 0;
        for(int i=0; i<nums.size();++i){
            if(nums[i]!=0){
                if(nums[i]!=nums[to_insert]){
                    int tmp = nums[i];
                    nums[i] = nums[to_insert];
                    nums[to_insert] = tmp;
                } 
                to_insert++;
            }
        }

    }
};