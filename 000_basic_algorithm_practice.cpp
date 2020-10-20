/**
 * 每日必练的内功, 每天打10遍
 * 	1. 最短路径( Floyd, Dijstra, Bellman-Ford)
	2. 最小生成树(先写个prim , kruscal 要用并查集, 不好写)
	3. 大数(高精度 ) 加减乘除
	4. 二分查找(代码在5行以内)
	5. 叉乘, 判断线段相交, 然后写个凸包
	6. BFS, DFS  同时熟练hash表(要熟, 要灵活, 代码要简单)
	7. 数学上的有:  辗转相除法(两行以内), 线段交点, 多角形面积公式
	8. 调用系统的qsort, quicksort, mergesort  技巧很多, 慢慢掌握
	9. 任意进制之间的转换
	10. 并查集
	11. 熟悉动态规划的各个典型: LCS, 最长递增字串, 三角剖分, 记忆化dp
	12. 双向广度搜索, A*
**/

#include "utils.h"

class basic_algorithms_daily_practice{
    public:
    // 1. binary search
    //input: a array of unduplicated ordered numbers. the target number
    //output: return the index of the found target number
    int binarySearch_unduplicates(vector<int>& nums, int target){
        int left = 0, right = nums.size();
        while(left<right){
            int mid = (left+right)/2;
            if(nums[mid]<target){
                left = mid+1;
            }else if(nums[mid]>target){
                right = mid;
            }else{
                return mid;
            }
            return left;
        }
    }
    //return the first of the duplicates
    int binarySearch_duplicates(vector<int>& nums, int target){
        int left = 0, right = nums.size();
        while(left<right){
            int mid = (left + right)/2;
            if(nums[mid]<target){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};
