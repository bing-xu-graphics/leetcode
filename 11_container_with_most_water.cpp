#include "utils.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int left=0, right = height.size()-1;
        while(left<right){
            int area = min(height[left], height[right]) * (right - left);
            maxWater = area>maxWater? area: maxWater;
            if(height[left]<height[right]) left +=1;
            else right-=1;
        }
        return maxWater;
        
    }
};