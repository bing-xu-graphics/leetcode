/**
 * Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/top-k-frequent-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> frequencies;
        for(int num:nums){
            if(frequencies.find(num)==frequencies.end()){
                frequencies[num] = 1;
            }else{
                frequencies[num]++;
            }
        }
        priority_queue<int, vector<pair<int, int>>, decltype(&cmp)> min_heap(cmp);
        for(auto const& elem: frequencies){
            if(min_heap.size()<k){
                min_heap.emplace(elem.first, second);
                // min_heap.push(make_pair(elem.first, elem.second));
            } 
            else{
                if(elem.second < min_heap.top().second) continue;
                min_heap.pop();
                // min_heap.push(make_pair(elem.first, elem.second));
                min_heap.emplace(elem.first, second);
            }
        }
       
        vector<int> res;
        while(!min_heap.empty()){
            res.push_back(min_heap.top().first);
            min_heap.pop();
        }
        return res;
    }
};

//method2   O(N)
class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences;
        for(auto& num: nums){
            occurrences[num]++;
        }
        vector<pair<int,int>> values;
        for(auto &kv:occurrences){
            values.push_back(kv);
        }
        
        vector<int> res;
        qsort(values, 0,values.size()-1, res, k);
        return res;

    }

    //top k numbers
    void qsort(vector<pair<int, int>> v,int start, int end, vector<int>& res, int k){
        int picked = rand() % (end - start + 1) + start;
        swap(v[picked],v[start]);
        int index = start+1;
        for(int i=start+1;i<=end; ++i){
            if(v[i].second >= v[start].second){
                swap(v[i], v[index++]);
            }
        }
        swap(v[--index], v[start]);
        if(k <= index - start){
            qsort(v, start, index-1, res, k);
        }else{
            for(int i=start;i<=index;++i){
                res.push_back(v[i].first);
            }
            if(k - index +start-1>0)qsort(v, index+1, end, res, k - index +start-1);
        }
    }
};