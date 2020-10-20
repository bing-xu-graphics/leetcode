#include "utils.h"
//solution1 双指针的解法

//之前一直纠结一个loop 中 left 好处理, 但right 很难处理, 很麻烦, 一直不对
//没有想到左右两边同时开工的方法, 这样就简单很多
//双指针方法, 主要考虑的点是:
//移动left 还是right 要依据什么? 一般是靠这两个的比较, 进行操作完成之后,left++ / right--
//另外是对于某个left/right, 改变的策略是什么? 这个就根据不同的问题来决定了.
class Solution1 {
public:
    int trap(vector<int>& height) {
        if(height.size()<3) return 0;
        int left = 0, right = height.size()-1;
        int left_max = 0, right_max = height.size()-1;
        int total_area = 0;
        while(left <= right){
            if(height[left] < height[right]){
                if(height[left]>=height[left_max]){
                    for(int i=left_max+1; i<left;i++) total_area+=height[left_max]-height[i];  
                    left_max = left;
                }
                left++;
            }else{
                if(height[right]>=height[right_max]){
                    for(int i=right_max-1;i>right;i--) total_area+=height[right_max]-height[i];
                    right_max = right;
                }
                right--;
            }
        }
        int bounded_height = min(height[left_max], height[right_max]);
        for(int i=left_max+1; i<right_max; i++) total_area+= bounded_height-height[i];
        return total_area;
    }
};


//Solution2 
//左右指针这种对称的形式很适合用一个stack//
//
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3) return 0;
        int total_area = 0;
        stack<int> st;
        st.push(0);
        for(int i=1; i<height.size(); i++){
            if(height[i]<height[st.top()]) st.push(i);
            else{
                
                while(!st.empty() && height[i]>=height[st.top()]){
                    // printf("top=%d, i=%d, total_area=%d\n", st.top(),i, total_area);        
                    int top = st.top();
                    st.pop();
                    if(st.empty())break;
                    total_area += (i-st.top()-1)*(min(height[i],height[st.top()])-height[top]);
                    
                }
                st.push(i);
            }
            
        }
        return total_area;
    }
       
};

class Solution_wrong {
public:
    int trap(vector<int>& height) {
if(height.size()<3) return 0;
        int total_area = 0, tmp_area = height[0];
        int left_tall = height[0],right_tall = height[0],left_tall_idx = 0, right_tall_idx = 0;
        for(int i=1; i<height.size(); i++){
            printf("i=%d,left_tall_idx = %d, right_tall_idx = %d, total_area=%d, tmp_area=%d\n", i,left_tall_idx, right_tall_idx,total_area, tmp_area);
            if(height[i] >= left_tall){
                total_area += (i-left_tall_idx)*left_tall;
                left_tall = height[i];
                left_tall_idx = i;
                right_tall = height[i];
                right_tall_idx = i;
                tmp_area = height[i];
            }else if(height[i]<left_tall){
                if(left_tall_idx==right_tall_idx){
                    right_tall_idx = i;
                    right_tall = height[i];
                }
                if(height[i]<height[i-1]) tmp_area += height[i];
                else{
                    if(height[i]<right_tall){
                        for(int j=right_tall_idx+1;j<i;j++) tmp_area+=(height[i]-height[j])>0?(height[i]-height[j]):0;
                    }else{
                        for(int j=left_tall_idx+1;j<i;j++) tmp_area+=(height[i]-right_tall);
                    }
                    right_tall = height[i];
                    right_tall_idx = i;
                    tmp_area +=height[i];
                }
            }
        }
        // printf("total_area = %d\n", total_area);
        total_area += tmp_area;
        // printf("total_area = %d\n", total_area);
        for(int i=0; i<height.size();i++){
            total_area-=height[i];
        }
        return total_area;



    }
};