/**
 * In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2-->3
Example 2:
Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
Output: [4,1]
Explanation: The given directed graph will be like this:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/redundant-connection-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//method 1 参考学习的https://leetcode.com/problems/redundant-connection-ii/discuss/278105/topic
//注意有三种情况, 这里比较好的, 即使遇到conflict 选择忽略 只记录下来, 继续前进, 到最后再辨别.
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> roots(edges.size()+1, 0);
        vector<int> parents(edges.size()+1, 0);
        vector<int> vec0;
        vector<int> conflict1;
        vector<int> conflict2;
        bool conflict = false;
        bool cycle = false;
        vector<int> lastCycleEdge;
        for(int i=0;i<=edges.size();++i){
            roots[i] = i;
            parents[i] = i;
        } 
        for(auto& edge:edges){
            int leader2 = find_root(roots, edge[1]);
            if(leader2!=edge[1]){//record the conflict
                // printf("%d, %d\n", edge[0], edge[1]);
                conflict1 = {parents[edge[1]], edge[1]};
                conflict2 = edge;
            }else{
                parents[edge[1]] = edge[0];
                int leader1 = find_root(roots, edge[0]);
                if(leader1 == leader2){//cycle
                    lastCycleEdge = edge;
                }else{
                    roots[leader2] = leader1;
                }
            }
        }

        if(conflict1==vec0){
            // printf("no conflict");
            return lastCycleEdge;
        } 
        else{//there is conflict
            if(lastCycleEdge==vec0){
                // printf("lalal");
                return conflict2;
            }else{
                // printf("hello world");
                return conflict1;
            }
            
        }
        return vec0;
    }

    int find_root(vector<int>& roots, int node){
        while(node!=roots[node]){
            roots[node] = roots[roots[node]];
            node = roots[node];
        }
        return node;
    }

    
    
};