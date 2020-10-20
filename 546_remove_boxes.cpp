#include "utils.h"
/**
 * Given several boxes with different colors represented by different positive numbers.
You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (composed of k boxes, k >= 1), remove them and get k*k points.
Find the maximum points you can get.

 

Example 1:

Input: boxes = [1,3,2,2,2,3,4,3,1]
Output: 23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)
 

Constraints:

1 <= boxes.length <= 100
1 <= boxes[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-boxes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//method 1 backtracking 超时
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int remain = 0;
        vector<vector<int>> groups =  divide_groups(boxes, remain);
        int max_sum = 0;
        for(vector<int> group: groups){
            int remain = boxes.size();
            int sum = group.size()*group.size();
            for(int idx: group){
                boxes[idx] *=-1;
            }
            if(remain>0)sum += removeBoxes(boxes);
            max_sum = max(sum, max_sum);
            for(int idx: group){
                boxes[idx] *=-1;
            }
        }
        return max_sum;

    }

    

    vector<vector<int>> divide_groups(vector<int>& boxes, int& remain){
        vector<vector<int>> groups;
        int before = 0;
        remain = 0;
        for(int i=0;i<boxes.size();++i){
            if(boxes[i]>0){
                remain++;
                if(boxes[i]!=before){
                    vector<int> vec{i};
                    groups.push_back(vec);
                }else{
                    groups[groups.size()-1].push_back(i);
                }
                before = boxes[i];
            }
        }
        return groups;
    }
};



/**method2 本着DP 的精神, 用top-down memoization 把上面的算法修改了一下 进行一些状态记录,
*由于不知道怎么表示所有的状态, 所以就用简单的hashmap, 记忆所有的状态, 但这里的问题是, 如果backtracking 的顺序导致
 * memoization 根本用不到的时候, ==> 这个想错了, 这个根本不可能  肯定有子问题, 那么子问题肯定是有先后的. 
 * 那么这里超时的原因  很可能是hash 的太慢了.每次hash都要重新走一遍100
 * divide_group 和hash 都可以再进一步优化
 */

class Solution {
public:
struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};  

    int removeBoxes(vector<int>& boxes) {
        //剩余多少数定义为状态
        unordered_map<string, int> memo; //hash the status to max_sum;
        vector<bool> status(boxes.size(), true);
        return dp(boxes, status, memo);
    }

    int dp(vector<int>& boxes, vector<bool>& status, unordered_map<string, int>& memo){ 
        string hashed_status = hash_status(status);
        // printf("%s\n", hashed_status.c_str());
        if(memo.find(hashed_status)!= memo.end()){
            return memo[hashed_status];
        }
        int remain = 0;
        vector<vector<int>> groups = divide_group(boxes, status, remain);
        // printf("number of groups=%d\n", groups.size());
        if(remain==0) return 0;
        int max_sum = 0;
        vector<int> rec_group;

        for(vector<int>& group: groups){
            // printf("hahha\n");
            int sum = 0;
            sum += group.size()*group.size();
            for(int idx:group) status[idx] = false; 
            // printf("here: %s\n", hash_status(status).c_str());
            sum += dp(boxes, status, memo);
            // if(max_sum< sum){
            //     max_sum = max(max_sum, sum);
            //    rec_group = group;
            // }   
            max_sum = max(max_sum, sum);
            for(int idx:group) status[idx] = true;
        }
        
        
        memo[hashed_status] = max_sum;
        // for(int idx:rec_group) status[idx] = false;
        return max_sum;
    }

    string hash_status(vector<bool>& status){
        string str;
        for(bool ss: status){
            str += ss? "1":"0";
        }
        return str;
    }
    vector<vector<int>> divide_group(vector<int> & boxes, vector<bool>& status, int& remain){
        int before = 0;
        vector<vector<int>> groups;
        for(int i=0; i<boxes.size();++i){
            if(status[i]){
                remain++;
                if(boxes[i]!=before){
                    vector<int> vec{i};
                    groups.push_back(vec);
                }else{
                    groups[groups.size()-1].push_back(i);
                }
                before = boxes[i];
            }
        }
        return groups;
    }

};

//method3 之后, 进一步优化了但是还是不行,
class Solution {
public:

    int removeBoxes(vector<int>& boxes) {
        unordered_map<string, int> memo; //hash the status to max_sum;
        vector<bool> status(boxes.size(), true);
        string hashed_key = hash_status(status);
        int remain = 0;
        vector<vector<int>> groups = divide_group(boxes, status, remain);
        return dp_with_less_work(boxes, status, memo, hashed_key, groups);
    }

    int dp_with_less_work(vector<int>& boxes, vector<bool>& status, unordered_map<string, int>& memo , string& hashed_key, vector<vector<int>>& groups){ 
        if(memo.find(hashed_key)!= memo.end()){
            return memo[hashed_key];
        }
        if(groups.size()<1) return 0;
        
        int max_sum = 0;
        
        for(int i=0;i<groups.size();++i){
            vector<int>& group = groups[i];
            int sum = 0;
            sum += group.size()*group.size();
            string tmp_hash_key = hashed_key;
            vector<vector<int>> tmp_groups = groups;
            // printf("groups.size() = %d\n", groups.size());
            if(i>0 && i<tmp_groups.size()-1 && boxes[groups[i-1][0]]==boxes[groups[i+1][0]]){          tmp_groups[i-1].insert(tmp_groups[i-1].end(), tmp_groups[i+1].begin(), tmp_groups[i+1].end());
                tmp_groups.erase(tmp_groups.begin()+i, tmp_groups.begin()+i+2);
            }else{
                tmp_groups.erase(tmp_groups.begin()+i);
            }
            for(int idx:group){
                status[idx] = false; 
                tmp_hash_key.replace(idx, 1, "0");
            }      
            sum += dp_with_less_work(boxes, status, memo, tmp_hash_key, tmp_groups);   
            max_sum = max(max_sum, sum);
            for(int idx:group) status[idx] = true;
        }
        
        
        memo[hashed_key] = max_sum;
        // for(int idx:rec_group) status[idx] = false;
        return max_sum;
    }

    string hash_status(vector<bool>& status){
        string str;
        for(bool ss: status){
            str += ss? "1":"0";
        }
        return str;
    }
    vector<vector<int>> divide_group(vector<int> & boxes, vector<bool>& status, int& remain){
        int before = 0;
        vector<vector<int>> groups;
        for(int i=0; i<boxes.size();++i){
            if(status[i]){
                remain++;
                if(boxes[i]!=before){
                    vector<int> vec{i};
                    groups.push_back(vec);
                }else{
                    groups[groups.size()-1].push_back(i);
                }
                before = boxes[i];
            }
        }
        return groups;
    }

};

/**
 * 突然想到, 我这个是错误的, 比如 0100 和 1000  都是一样的,但是我这样的hash 就无法利用相似的pattern 就是错误的. 
 * 就是讲道理 应该被hash 的是groups的情况  而不是status.
 */

string operator*(const string& s, unsigned int n) {
    stringstream out;
    while (n--)
        out << s;
    return out.str();
}
class Solution {
public:


    int removeBoxes(vector<int>& boxes) {
        unordered_map<string, int> memo; //hash the status to max_sum;
        vector<bool> status(boxes.size(), true);
        return dp(boxes, status, memo);
    }

    int dp(vector<int>& boxes, vector<bool>& status, unordered_map<string, int>& memo){ 
        
        int remain = 0;
        vector<vector<int>> groups = divide_group(boxes, status, remain);
        if(remain==0) return 0;
        string hashed_status = hash_status(boxes, groups);
        // printf("hashed_status = %s\n", hashed_status.c_str());
        if(memo.find(hashed_status)!= memo.end()){
            return memo[hashed_status];
        }
        int max_sum = 0;
        for(vector<int>& group: groups){
            int sum = 0;
            sum += group.size()*group.size();
            for(int idx:group) status[idx] = false; 
            sum += dp(boxes, status, memo);
 
            max_sum = max(max_sum, sum);
            for(int idx:group) status[idx] = true;
        }
        memo[hashed_status] = max_sum;
        return max_sum;
    }
    
    string hash_status(vector<int>& boxes, vector<vector<int>>& groups){
        string str;
        unordered_map<int, string> hash_map;
        int i=0;
        for(vector<int>& group:groups){
            // printf("=====group[0]=%d\n", group[0]);
            int num = boxes[group[0]];
            if(hash_map.find(num)== hash_map.end()){ //找不到
                str += to_string(i)*group.size();
                hash_map[num] = to_string(i++);
            }else{
                str +=hash_map[num]*group.size();
            }
        }
        return str;
    }
    vector<vector<int>> divide_group(vector<int> & boxes, vector<bool>& status, int& remain){
        int before = 0;
        vector<vector<int>> groups;
        for(int i=0; i<boxes.size();++i){
            if(status[i]){
                remain++;
                if(boxes[i]!=before){
                    vector<int> vec{i};
                    groups.push_back(vec);
                }else{
                    groups[groups.size()-1].push_back(i);
                }
                before = boxes[i];
            }
        }
        return groups;
    }

};


//然而这样, 为什么还是超时!!!!!!!???????????苍天啊!!
/**我觉得这个解法其实已经是对的了, 而且memo了所有的subproblem, 
 * 现在可能问题出在
 * 1)　divide_groups 和hash groups 太慢
 * 2)  没有做到足够的剪枝