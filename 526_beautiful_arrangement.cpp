#include "utils.h"
/**
 * Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 <= i <= N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
 

Now given N, how many beautiful arrangements can you construct?

Example 1:

Input: 2
Output: 2
Explanation: 

The first beautiful arrangement is [1, 2]:

Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

The second beautiful arrangement is [2, 1]:

Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
 

Note:

N is a positive integer and will not exceed 15.
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/beautiful-arrangement
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int countArrangement(int N) {
        int cnt = 0;
        vector<int> permutation;
        vector<bool> visited(N, false);
        permute(N, permutation, visited, cnt);
        return cnt;

    }

    void permute(int N, vector<int>& permutation, vector<bool>& visited, int& cnt){
        if(permutation.size()==N){
            cnt++;
            return;
        }
        int i = permutation.size()+1;
        for(int current=1;current<=N;current++){
            if(visited[current-1]) continue;
            if(current%i==0 || i%current==0){
                permutation.push_back(current);
                visited[current-1] = true;
                permute(N, permutation, visited, cnt);
                permutation.pop_back();
                visited[current-1] = false;
            }
        }
        // return false;
    }
};

//method2  其实没有必要保留一个permutaion 只要记录position 就可以了
class Solution {
public:
    int countArrangement(int N) {
        int cnt = 0;
        // vector<int> permutation;
        vector<bool> visited(N, false);
        permute(N, 1, visited, cnt);
        return cnt;

    }

    void permute(int N, int pos, vector<bool>& visited, int& cnt){
        // if(permutation.size()==N){
        if(pos>N){
            cnt++;
            return;
        }
        for(int current=1;current<=N;current++){
            if(visited[current-1]) continue;
            if(current%pos==0 || pos%current==0){
                visited[current-1] = true;
                permute(N, pos+1, visited, cnt);
                visited[current-1] = false;
            }
        }
    }
};

//method 3 

//改变经典的permutation
class Solution1 {
    public:
    int countArrangeent(int N){
        vector<int> arr;
        for(int i=0;i<N;i++){
            arr.push_back(i+1); //do initialization
        }
    }

    void permute(int N, vector<int>& arr, int pos){
        for(int i=pos;i<N;i++){
            if("..some conditon"){
                swap(arr, i, pos);
                permute(N, arr, pos+1);
                swap(arr,i, pos);
            }
        }
    }

    void swap(vector<int>& arr, int pos1, int pos2){
        int tmp = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = tmp;
    }
};