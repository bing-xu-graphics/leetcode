#include "utils.h"
/**
 * Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

/**
 * 思考:
 * 着到题目的特点在于 , 通过矩阵, 把行和列都排序好了, 这个和k 个sorted list 还要多一维度的排序呢.
 * 那么  对于有序的数列来说, searching 就要用到它的有序性, 很容易想到二分法, 那么通常我们对index二分是因为整个是有序, 
 * 这里不是, 我们在有值域大小/信息的时候可以对值域进行二分, 
 * 然后 通过处理  mid 得到一个 信息, 比如这里是找到 <=mid 的个数, 然后同k进行比较. 如果k> sum 则肯定不在这里区间内
 * 最后break 是left==right了, 那么这个就是解.
 * 
 * take away , <= mid, 然后 k>sum
 * 
 */ 
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1];
        while(left<right){
            int mid = (left+right)/2;
            int row=n-1, col=0;
            int cnt =0;
            vector<int> tmp;
            while(row>=0 && col<n){
                if(matrix[row][col]<=mid){
                    cnt += row+1;
                    col++;
                }else row--;
            }
            if(k>cnt) left = mid+1;
            else right = mid;
        }
        
        return left;
    }
};