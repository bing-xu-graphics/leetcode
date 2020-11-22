/**
 * In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

Update (2017-09-26):
We have overhauled the problem description + test cases and specified clearly the graph is an undirected graph. For the directed graph follow up please see Redundant Connection II). We apologize for any inconvenience caused.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/redundant-connection
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//method1   暴力找cycle, 判断一个edge 在不在一个cycle之中.   ETL! 超时!
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //find a cycle and remove one edge of the cycle
        vector<bool> visited(edges.size(), false);
        for(int i=edges.size()-1; i>=0; --i){
            visited[i] = true;
            bool res = dfs_redundant(edges, edges[i], edges[i], visited);
            if(res) return edges[i];
            visited[i] = false;
        } 
        // test();  
        return vector<int>();

    }

    bool dfs_redundant(vector<vector<int>>& edges, vector<int>& target_edge, vector<int>& current_edge, vector<bool> visited){
        for(int i=0;i<edges.size();++i){
            if(!visited[i] && isConnected(edges[i], current_edge)){
                if(edges[i]==current_edge) return true;
                vector<int> mergeEdge = mergeEdges(edges[i], current_edge);
                // if(mergeEdge==target_edge) return true;
                visited[i] = true;
                bool redundant = dfs_redundant(edges, target_edge, mergeEdge,  visited);  
                if(redundant) return true;
                visited[i] = false;
            }
        }
        return false;
    }

    bool isConnected(vector<int>e1, vector<int>e2){
        return e1[0]==e2[0] || e1[0] == e2[1] || e1[1] == e2[0] || e1[1] == e2[1];
    }
    vector<int> mergeEdges(vector<int> e1, vector<int> e2){
        if(e1==e2) return e1;
        vector<int> merge(e1);
        merge.reserve(4);
        copy(e2.begin(),e2.end(), back_inserter(merge));
        // for_each(merge.begin(), merge.end(), [](auto& v){printf("%d ", v);});
        sort(merge.begin(), merge.end());
        for(int i=0;i<3;++i){
            if(merge[i]==merge[i+1]){
                merge.erase(merge.begin()+i, merge.begin()+i+2);
                return merge;
            } 
        }
        return merge;
    }

    void test(){
        vector<int> e1{1,2};
        vector<int> e2{2,3};
        printf("isConnected = %d", isConnected(e1, e2));
        vector<int> merge = mergeEdges(e1, e2);
        for_each(merge.begin(), merge.end(), [](auto& v){printf("%d ", v);});
    }
};


//method2  union-find

//只有find 没有union 没有update, 如果每次update , 则find 就变简单了. 
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> leaders(edges.size()+1, 0);
        for(int i=0;i<leaders.size();++i) leaders[i] = i;
        for(auto & edge: edges){
            int leader1 = find(edge[0], leaders);
            int leader2 = find(edge[1], leaders);
            if(leader1 == leader2) return edge;
            else{
                leaders[leader1] = leader2;
            }
        }
        return {0,0};
        
    }
    int find(int node, vector<int>& leaders){
            while(leaders[node]!=node){
                node = leaders[node];
            }
            return node;
        }
};

//加了一个union-find 的path compression