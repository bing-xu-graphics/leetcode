#include "utils.h"

/**
 * 
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/course-schedule
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

//method 1 纯暴力, permutation所有组合然后检查是否符合要求
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<int> permutation;
        bool res = permute(visited, permutation, numCourses, prerequisites);
        return res;

    }

    bool permute(vector<bool>& visited, vector<int>& permutation, int numCourses, vector<vector<int>>& prerequisites){
        // printf("permutaiton.size()=%d,\n", permutation.size());
        if(permutation.size()== numCourses) return true;
        for(int i=0;i<numCourses;i++){
            // printf("permutaiton.size()=%d, i=%d\n", permutation.size(),i);
            if(visited[i]) continue;
            //check if satistfy the condition
            set<int> preCourses;
            for(vector<int> pair: prerequisites){
                if(pair[0]==i){
                    preCourses.emplace(pair[1]);
                }
            }
            if(preCourses.size()!=0){
                for(int ii=0;ii<permutation.size();ii++){
                    auto iter = preCourses.find(permutation[ii]);
                    if(iter!= preCourses.end()) preCourses.erase(iter);
                }
                if(preCourses.size()!=0) continue;//
            }
            
            permutation.push_back(i);
            visited[i] = true;
            bool subRes = permute(visited, permutation, numCourses, prerequisites);
            if(subRes) return true;
            // if(!subRes) return subRes;
            permutation.pop_back();
            visited[i] = false;
        }
        return false;
    } 

};

//to search the preprequisites for circles. if no circle, then pass
//use the graph representations
//一开始我没有把prerequisites 改成preTable , 每次要循环所有的V 就超时了, 
//这里的visited 类似于借用了 算法导论里面的white gray black 作为搜索状态的标记
//method2: DFS 
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        bool res = true;
        vector<vector<int>> preTable(numCourses, vector<int>());
        for(vector<int> pre: prerequisites){
            preTable[pre[0]].push_back(pre[1]);
        }
        for(int course=0;course<numCourses; course++){
            res = dfs(preTable, visited, course);
            if(!res)break;
        }
        return res;
    }

    bool dfs(vector<vector<int>>& preTable, vector<int>& visited, int sourceCourse){
        if(visited[sourceCourse]==1) return false;
        if(visited[sourceCourse]==2) return true;
        visited[sourceCourse] = 1;
        vector<int> pres = preTable[sourceCourse];
        for(int pre: pres){
            bool res = dfs(preTable, visited, pre);
            if(!res) return false;
            
        }
        visited[sourceCourse] = 2;
        return true;
    }
 
};

//method3:  BFS